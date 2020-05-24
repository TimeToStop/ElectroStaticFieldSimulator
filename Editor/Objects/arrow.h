#ifndef ARROW_H
#define ARROW_H

#include "Editor/Objects/object.h"

class Arrow : public Object
{
    Vector m_dest;

public:
    Arrow(Editor* const);
    virtual ~Arrow();

    virtual void draw(QPainter &) const override;
    virtual bool intersects(const QRect &) const override;

    void recount();
    void setDest(const Vector&);
};

#endif // ARROW_H
