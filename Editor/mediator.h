#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "Editor/Objects/arrow.h"
#include "Editor/Objects/chargeedit.h"

#include <vector>
#include <utility>

class Mediator
{
   std::vector<std::pair<Arrow*, ChargeEdit*>> m_bounded_objects;

public:
    Mediator();
    ~Mediator();

    void bindPair(Arrow*, ChargeEdit*);
    void rm(Arrow*);
    void rm(ChargeEdit*);

    Arrow* get(ChargeEdit*);
    ChargeEdit* get(Arrow*);
};

#endif // MEDIATOR_H
