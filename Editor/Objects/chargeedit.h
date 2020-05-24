#ifndef CHARGEEDIT_H
#define CHARGEEDIT_H

#include "Editor/Objects/object.h"

class ChargeEdit : public Object
{
    static int m_r;

public:
    ChargeEdit(Editor* const);
    virtual ~ChargeEdit();

    virtual void draw(QPainter &) const override;
    virtual bool intersects(const QRect &) const override;

    virtual void setPos(const Vector &) override;
    virtual void movePos(const Vector&) override;
};

#endif // CHARGEEDIT_H
