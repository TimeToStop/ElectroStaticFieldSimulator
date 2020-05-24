#include "mediator.h"

Mediator::Mediator()
{
}

Mediator::~Mediator()
{
    m_bounded_objects.clear();
}

void Mediator::bindPair(Arrow* arrow, ChargeEdit* charge)
{
    m_bounded_objects.push_back(std::make_pair(arrow, charge));
    arrow->recount();
}

void Mediator::rm(Arrow* arrow)
{
    for(std::vector<std::pair<Arrow*, ChargeEdit*>>::iterator it = m_bounded_objects.begin(); it != m_bounded_objects.end(); ++it)
    {
        if(it->first == arrow)
        {
            m_bounded_objects.erase(it);
            return;
        }
    }
}

void Mediator::rm(ChargeEdit* charge)
{
    for(std::vector<std::pair<Arrow*, ChargeEdit*>>::iterator it = m_bounded_objects.begin(); it != m_bounded_objects.end(); ++it)
    {
        if(it->second == charge)
        {
            m_bounded_objects.erase(it);
            return;
        }
    }
}

Arrow *Mediator::get(ChargeEdit* charge)
{
    for(std::pair<Arrow*, ChargeEdit*> bound : m_bounded_objects)
    {
        if(bound.second == charge)
        {
            return bound.first;
        }
    }

    return nullptr;
}

ChargeEdit *Mediator::get(Arrow * arrow)
{
    for(std::pair<Arrow*, ChargeEdit*> bound : m_bounded_objects)
    {
        if(bound.first == arrow)
        {
            return bound.second;
        }
    }

    return nullptr;
}
