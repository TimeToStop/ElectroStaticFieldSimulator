#include "object.h"

#include "Editor/editor.h"

Object::Object(Editor* const widget):
    m_widget(widget),
    m_is_selected(false),
    m_pos()
{
}

Object::~Object()
{
}

void Object::setPos(const Vector& pos)
{
    m_pos = pos;
}

void Object::movePos(const Vector& pos)
{
    m_pos += pos;
}

void Object::setSelected(bool b)
{
    m_is_selected = b;
}

bool Object::isSelected() const
{
    return m_is_selected;
}

Vector Object::pos() const
{
    return m_pos;
}
