#include "Editor/Objects/object.h"

Object::Object(Editor* const editor):
    m_editor(editor),
    m_is_selected(false),
    m_pos()
{
}

Object::~Object()
{
}

void Object::setSelected(bool b)
{
    m_is_selected = b;
}

void Object::setPos(const Vector& pos)
{
    m_pos = pos;
}

void Object::movePos(const Vector& pos)
{
    m_pos += pos;
}

Vector Object::pos() const
{
    return m_pos;
}

bool Object::isSelected() const
{
    return m_is_selected;
}
