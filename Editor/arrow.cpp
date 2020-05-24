#include "arrow.h"
#include "Editor/editor.h"

Arrow::Arrow(ArrowColor color, Editor * const widget):
    Object(widget),
    m_color(color),
    m_to()
{
}

Arrow::~Arrow()
{
}

void Arrow::draw(QPainter& painter) const
{
    switch (m_color)
    {
    case ArrowColor::RED:
    {
        painter.setPen(QPen(QColor(255, 0, 0), 2, Qt::SolidLine));
        break;
    }
    case ArrowColor::BLUE:
    {
        painter.setPen(QPen(QColor(0, 0, 255), 2, Qt::SolidLine));
        break;
    }
    default: break;
    }

    painter.drawLine(m_to, m_widget->fromXOY(pos()).toPointF().toPoint());
}

bool Arrow::isClose(const QPoint& pos)
{
    return false;
}

bool Arrow::intersects(const QRect& rect) const
{
    QLineF line(m_widget->fromXOY(pos()).toPointF().toPoint(), m_to);
    return (line.intersects(QLineF(rect.topLeft(), rect.topRight()), nullptr) == QLineF::IntersectType::BoundedIntersection)
            || (line.intersects(QLineF(rect.topRight(), rect.bottomRight()), nullptr) == QLineF::IntersectType::BoundedIntersection)
            || (line.intersects(QLineF(rect.bottomRight(), rect.bottomLeft()), nullptr) == QLineF::IntersectType::BoundedIntersection)
            || (line.intersects(QLineF(rect.bottomLeft(), rect.topLeft()), nullptr) == QLineF::IntersectType::BoundedIntersection);
}
