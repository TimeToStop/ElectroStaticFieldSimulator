#include "mediator.h"

Mediator::Mediator():
    m_bounded_objects()
{
}

Mediator::~Mediator()
{
}

void Mediator::bindPair(std::shared_ptr<Arrow> arrow, std::shared_ptr<ChargeEdit> charge)
{
    m_bounded_objects.push_back(std::make_pair(arrow, charge));
}

void Mediator::rmBind(std::shared_ptr<Arrow> arrow)
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

void Mediator::rmBind(std::shared_ptr<ChargeEdit> charge)
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

std::shared_ptr<Arrow> Mediator::get(std::shared_ptr<ChargeEdit> charge)
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

std::shared_ptr<ChargeEdit> Mediator::get(std::shared_ptr<Arrow> arrow)
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
