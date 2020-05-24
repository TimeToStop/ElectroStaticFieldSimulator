#include "mediator.h"

Mediator::Mediator():
    m_bounded_objects()
{
}

Mediator::~Mediator()
{
}

void Mediator::bindPair(Arrow* arrow, ChargeEdit* charge)
{
    m_bounded_objects.push_back(std::make_pair(arrow, charge));
}

void Mediator::rmBind(Arrow* arrow)
{
    for(Bounds::iterator it = m_bounded_objects.begin(); it != m_bounded_objects.end(); ++it)
    {
        if(it->first == arrow)
        {
            m_bounded_objects.erase(it);
            return;
        }
    }
}

void Mediator::rmBind(ChargeEdit* charge)
{
    for(Bounds::iterator it = m_bounded_objects.begin(); it != m_bounded_objects.end(); ++it)
    {
        if(it->second == charge)
        {
            m_bounded_objects.erase(it);
            return;
        }
    }
}

Arrow* Mediator::get(ChargeEdit* charge)
{
    for(Bound const& pair : m_bounded_objects)
    {
        if(pair.second == charge)
        {
            return pair.first;
        }
    }

    return nullptr;
}

ChargeEdit* Mediator::get(Arrow* arrow)
{
    for(Bound const& pair : m_bounded_objects)
    {
        if(pair.first == arrow)
        {
            return pair.second;
        }
    }

    return nullptr;
}
