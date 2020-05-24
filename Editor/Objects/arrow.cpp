#include "arrow.h"

#include "Editor/editor.h"

Arrow::Arrow(Editor * const editor):
    Object(editor)
{
}

Arrow::~Arrow()
{
}

void Arrow::draw(QPainter& painter) const
{
    painter.drawLine(m_editor->fromXOY(pos()).toPointF().toPoint(), m_editor->fromXOY(m_dest).toPointF().toPoint());
}

bool Arrow::intersects(const QRect& ) const
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
