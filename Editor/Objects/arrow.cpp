#include "arrow.h"

#include "Editor/editor.h"

Arrow::Arrow(Editor* const editor):
    Object(editor)
{
}

Arrow::~Arrow()
{
    m_editor->rm(this);
}

void Arrow::draw(QPainter& painter) const
{
    painter.setPen(QPen(QColor(0, 0, 255), 3, Qt::SolidLine));

    QPoint start = m_editor->fromXOY(pos()).toPointF().toPoint();
    painter.drawLine(start, m_editor->fromXOY(m_dest).toPointF().toPoint());
    Vector diff = m_dest - pos();
    diff.normalize().rotate(-M_PI_4);

    painter.drawLine(start, m_editor->fromXOY(pos() + diff).toPointF().toPoint());
    diff.rotate(M_PI_2);
    painter.drawLine(start, m_editor->fromXOY(pos() + diff).toPointF().toPoint());
}

bool Arrow::intersects(const QRect& rect) const
{
    QLineF line(m_editor->fromXOY(pos()).toPointF().toPoint(),
                m_editor->fromXOY(m_dest).toPointF().toPoint());

    return line.intersects(QLineF(rect.topLeft(), rect.topRight()), nullptr) == QLineF::IntersectType::BoundedIntersection
        || line.intersects(QLineF(rect.bottomRight(), rect.topRight()), nullptr) == QLineF::IntersectType::BoundedIntersection
        || line.intersects(QLineF(rect.bottomRight(), rect.bottomLeft()), nullptr) == QLineF::IntersectType::BoundedIntersection
            || line.intersects(QLineF(rect.topLeft(), rect.bottomLeft()), nullptr) == QLineF::IntersectType::BoundedIntersection;
}

bool Arrow::isClose(const QPoint &) const
{
    return false;
}

void Arrow::recount()
{
    ChargeEdit* charge = m_editor->get(this);
    if(charge != nullptr)
    {
        setDest(charge->pos());
        setPos(charge->pos() + Vector(5, 0));
    }
}

void Arrow::setDest(const Vector& dest)
{
    m_dest = dest;
}

int Arrow::index() const
{
    return 0;
}
