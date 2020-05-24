#include "chargeedit.h"

#include "Editor/editor.h"

int ChargeEdit::m_r = 5;

ChargeEdit::ChargeEdit(Editor * const editor):
    Object(editor)
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

    QPoint p = m_editor->fromXOY(pos()).toPointF().toPoint();
    painter.drawEllipse(p.x() - m_r, p.y() - m_r, 2*m_r, 2*m_r);
}

bool ChargeEdit::intersects(const QRect& rect) const
{
    return rect.contains(m_editor->fromXOY(pos()).toPointF().toPoint());
}

bool ChargeEdit::isClose(const QPoint& _pos) const
{
    return QLineF(_pos, m_editor->fromXOY(pos()).toPointF().toPoint()).length() < m_r;
}

void ChargeEdit::setPos(const Vector& _pos)
{
    Object::setPos(_pos);
    Arrow* arrow = m_editor->get(this);
    if(arrow != nullptr)
    {
        arrow->setDest(pos());
    }
}

void ChargeEdit::movePos(const Vector& _pos)
{
    Object::movePos(_pos);
    Arrow* arrow = m_editor->get(this);
    if(arrow != nullptr)
    {
        arrow->setDest(pos());
    }
}

void ChargeEdit::setSelected(bool b)
{
    Object::setSelected(b);
    Arrow* arrow = m_editor->get(this);
    if(arrow != nullptr)
    {
        arrow->setSelected(b);
    }
}

int ChargeEdit::index() const
{
    return 1;
}
