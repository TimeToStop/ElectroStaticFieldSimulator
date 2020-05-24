#ifndef OBJECT_H
#define OBJECT_H

#include "Engine/vector.h"
#include <QPainter>

class Editor;

class Object
{
protected:
    Editor* const m_editor;

private:
    bool m_is_selected;
    Vector m_pos;

public:
    Object(Editor* const);
    virtual ~Object();

    virtual void draw(QPainter&) const = 0;
    virtual bool intersects(const QRect&) const = 0;
    virtual bool isClose(const QPoint&) const = 0;

    virtual void setSelected(bool);

    virtual void setPos(const Vector&);
    virtual void movePos(const Vector&);

    Vector pos() const;
    bool isSelected() const;

    static bool isLeftGreater(const std::shared_ptr<Object>&, const std::shared_ptr<Object>&);

protected:
    virtual int index() const = 0;
};

#endif // OBJECT_H
