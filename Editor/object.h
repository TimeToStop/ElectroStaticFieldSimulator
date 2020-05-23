#ifndef OBJECT_H
#define OBJECT_H

#include <QPoint>
#include <QPainter>

class Object
{
    QPoint m_pos;

public:
    Object();
    virtual ~Object();

    virtual void draw(QPainter&) const = 0;
    virtual bool intersects(const QRect&) const = 0;

    void setPos(const QPoint&);
    void movePos(const QPoint&);

    QPoint pos() const;
};

#endif // OBJECT_H
