#include "chargeedit.h"

int ChargeEdit::m_radius = 5;

ChargeEdit::ChargeEdit(PlotGridWidget * const widget):
    Object(widget)
{
}

ChargeEdit::~ChargeEdit()
{
}

void ChargeEdit::draw(QPainter& painter) const
{
    if(isSelected())
    {
        painter.setPen(QPen(QColor(255, 0, 0), 1, Qt::SolidLine));
        painter.setBrush(QBrush(QColor(255, 0, 0), Qt::SolidPattern));

    }
    else
    {
        painter.setPen(QPen(QColor(0, 0, 0), 1, Qt::SolidLine));
        painter.setBrush(QBrush(QColor(0, 0, 0), Qt::SolidPattern));
    }

    QPoint pos = m_widget->fromXOY(this->pos()).toPointF().toPoint();
    painter.drawEllipse(pos.x() - m_radius, pos.y() - m_radius, 2 * m_radius, 2 * m_radius);
}

bool ChargeEdit::intersects(const QRect& rect) const
{
    QPoint p = m_widget->fromXOY(pos()).toPointF().toPoint();
    return rect.contains(p.x() + m_radius, p.y())
        || rect.contains(p.x() - m_radius, p.y())
        || rect.contains(p.x(), p.y() + m_radius)
        || rect.contains(p.x(), p.y() - m_radius);
}

bool ChargeEdit::isClose(const QPoint& _pos)
{
    Vector position = m_widget->fromXOY(pos());
    return (pow(_pos.x() - position.x(), 2) + pow(_pos.y() -  position.y(), 2) < m_radius*m_radius);
}

void ChargeEdit::setPos(const Vector& pos)
{
    Object::setPos(pos);
    m_widget->
}

void ChargeEdit::movePos(const Vector& pos)
{
    Object::movePos(pos);
}
