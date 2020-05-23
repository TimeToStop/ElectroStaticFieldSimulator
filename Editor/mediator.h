#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "Editor/chargeedit.h"
#include "Editor/arrow.h"

class Mediator
{
    typedef std::pair<std::shared_ptr<Arrow>, std::shared_ptr<ChargeEdit>> Bound;
    typedef std::vector<Bound> Bounds;
    Bounds m_bounded_objects;

public:
    Mediator();
    ~Mediator();

    void bindPair(std::shared_ptr<Arrow>, std::shared_ptr<ChargeEdit>);
    void rmBind(std::shared_ptr<Arrow>);
    void rmBind(std::shared_ptr<ChargeEdit>);

    std::shared_ptr<Arrow> get(std::shared_ptr<ChargeEdit>);
    std::shared_ptr<ChargeEdit> get(std::shared_ptr<Arrow>);
};

#endif // MEDIATOR_H
