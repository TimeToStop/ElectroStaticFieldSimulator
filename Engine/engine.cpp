#include "engine.h"

#include "charge.h"
#include <QElapsedTimer>
#include <QDebug>

Engine::Engine():
    m_lambda(0.1f),
    m_dielectric(1.f),
    m_charges(),
    m_engine_state(EngineState::PLAY)
{
    m_charges.push_back(std::unique_ptr<Charge>(new Charge(0.1f, Vector(3, 3), this)));
    m_charges.push_back(std::unique_ptr<Charge>(new Charge(0.1f, Vector(2, -1), this)));
    m_charges.push_back(std::unique_ptr<Charge>(new Charge(1.f, Vector(-1, 0), this)));

    m_charges[0]->setCharge(0.00001);
    m_charges[1]->setCharge(-0.00001);
    m_charges[2]->setCharge(0.00001);
}

Engine::~Engine()
{
}

void Engine::drawCharges(QPainter& painter)
{
    for(std::unique_ptr<Charge>& charge : m_charges)
    {
        charge->draw(painter);
    }
}

void Engine::tick(float deltatime)
{
    for(size_t i = 0; i < m_charges.size(); i++)
    {
        m_charges[i]->setForce(applyCharge(i));
    }

    for(const std::unique_ptr<Charge>& charge : m_charges)
    {
        charge->tick(deltatime);
    }
}

void Engine::addCharge(std::unique_ptr<Charge>&& charge)
{
    m_charges.push_back(std::move(charge));
}

void Engine::rmCharge(size_t i)
{
    m_charges.erase(m_charges.begin() + i);
}

size_t Engine::chargesNum() const
{
    return m_charges.size();
}

bool Engine::hasCharges() const
{
    return m_charges.size() != 0;
}

const std::unique_ptr<Charge>& Engine::getCharge(size_t i) const
{
    return m_charges[i];
}

QStringList Engine::chargeNames() const
{
    QStringList names;

    for(const std::unique_ptr<Charge>& charge : m_charges)
    {
        names.push_back(charge->name());
    }

    return names;
}

Vector Engine::toXOY(float x, float y) const
{
    return toXOY(Vector(x, y));
}

Vector Engine::fromXOY(float x, float y) const
{
    return fromXOY(Vector(x, y));
}

float Engine::lambda() const
{
    return m_lambda;
}

Vector Engine::applyCharge(size_t i)
{
    static const float k = 9000000000;
    Vector res;

    for(size_t j = 0; j < m_charges.size(); j++)
    {
        if(i != j)
        {
            const float dx = m_charges[j]->pos().x() - m_charges[i]->pos().x();
            const float dy = m_charges[j]->pos().y() - m_charges[i]->pos().y();
            const float r = sqrt(dx*dx+dy*dy);
            const float f = k*abs(m_charges[i]->charge()*m_charges[j]->charge())/(r*r*m_dielectric);
            const float fx = f*abs(dx)/r;
            const float fy = f*abs(dy)/r;

            res += Vector(sign(dx)*fx, sign(dy)*fy) * (-sign(m_charges[i]->charge() * m_charges[j]->charge()));
        }
    }

    return res;
}

int Engine::sign(float x)
{
    return (x > 0) ? 1 : -1;
}

void Engine::setEngineState(EngineState state)
{
    m_engine_state = state;
}
