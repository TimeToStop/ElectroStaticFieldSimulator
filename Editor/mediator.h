#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "Editor/chargeedit.h"
#include "Editor/arrow.h"

class Mediator
{
    typedef std::pair<Arrow*, ChargeEdit*> Bound;
    typedef std::vector<Bound> Bounds;
    Bounds m_bounded_objects;

public:
    Mediator();
    ~Mediator();

    void bindPair(Arrow*, ChargeEdit*);
    void rmBind(Arrow*);
    void rmBind(ChargeEdit*);

    Arrow* get(ChargeEdit*);
    ChargeEdit* get(Arrow*);
};

#endif // MEDIATOR_H
