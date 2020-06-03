#include "engine.h"

#include "charge.h"
#include <QElapsedTimer>
#include <QDebug>

Engine::Engine():
    m_lambda(0.1f),
    m_dielectric(1.f),
    m_charges(),
    m_engine_state(EngineState::PAUSE)
{
    m_charges.push_back(std::unique_ptr<Charge>(new Charge(0.1f, Vector(3, 3), this)));
//    m_charges.push_back(std::unique_ptr<Charge>(new Charge(0.1f, Vector(2, -1), this)));
//    m_charges.push_back(std::unique_ptr<Charge>(new Charge(1.f, Vector(-1, 0), this)));

    m_charges[0]->setCharge(0.00001);
//    m_charges[1]->setCharge(0.00001);
//    m_charges[2]->setCharge(0.00001);
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
        if(!m_charges[i]->is_ignored() && m_charges[i]->is_movable())
        {
            m_charges[i]->setForce(applyCharge(i));
        }
    }

    for(const std::unique_ptr<Charge>& charge : m_charges)
    {
        if(!charge->is_ignored() && charge->is_movable())
        {
            charge->tick(deltatime);
        }
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

void Engine::clearCharges()
{
    m_charges.clear();
}

size_t Engine::chargesNum() const
{
    return m_charges.size();
}

bool Engine::hasCharges() const
{
    return m_charges.size() != 0;
}

std::unique_ptr<Charge>& Engine::getCharge(size_t i)
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

Vector Engine::calculateTension(const Vector& v)  const
{
    static const long long k = 9000000000.l;
    float res_tension_x = 0;
    float res_tension_y = 0;
    for (size_t i = 0; i < m_charges.size(); ++i)
    {
        if(!m_charges[i]->is_ignored())
        {
            const float dx = v.x() - m_charges[i]->pos().x();
            const float dy = m_charges[i]->pos().y() - v.y();
            const double distance = sqrt(dx * dx + dy * dy);
            if (abs(distance) > 0.f) {
            const double tension = (k * (double)m_charges[i]->charge()) / (distance * distance);
            const float tension_x = tension * dx / distance;
            const float tension_y = tension * dy / distance;
            res_tension_x += tension_x;
            res_tension_y += tension_y;
            }
        }
    }
    return Vector(res_tension_x, res_tension_y);
}

float Engine::calculatePotential(const Vector& v) const
{
    static const long long k = 9000000000.l;
    float res_potential = 0;
    for (size_t i = 0; i < m_charges.size(); ++i)
    {
        if(!m_charges[i]->is_ignored())
        {
            const float dx = v.x() - m_charges[i]->pos().x();
            const float dy = m_charges[i]->pos().y() - v.y();
            const double distance = sqrt(dx * dx + dy * dy);
            const double potential = (k * (double)m_charges[i]->charge()) / distance;
            res_potential += potential;
        }
    }
    return res_potential;
}

float Engine::calculateEnergy(const Vector& v) const
{
    static const long long k = 9000000000.l;
    float w = 0.f;

    for(size_t i = 0; i < m_charges.size(); i++)
    {
        if(!m_charges[i]->is_ignored())
        {
            const float dx = v.x() - m_charges[i]->pos().x();
            const float dy = m_charges[i]->pos().y() - v.y();
            const float distance = sqrt(dx * dx + dy * dy);
            const float potential = (k * (double)m_charges[i]->charge()) / distance;
            w += 0.5 * m_charges[i]->charge() * potential;
        }
    }

    return w;
}

float Engine::calculateKineticEnergy(const int index) const {
    return m_charges[index]->mass() * m_charges[index]->velocity().module() * m_charges[index]->velocity().module() / 2;

}

float Engine::calculateKineticEnergyOfSystem() const
{
    float w = 0.f;

    for(size_t i = 0; i < m_charges.size(); i++)
    {
        if(!m_charges[i]->is_ignored())
        {
            w += m_charges[i]->mass() * (m_charges[i]->velocity() * m_charges[i]->velocity())/2;
        }
    }

    return w;
}

float Engine::calculateEnergyOfSystem() const
{
    static const long long k = 9000000000.l;
    float w = 0.f;
    for (size_t i = 0; i < m_charges.size(); ++i)
    {
        if(!m_charges[i]->is_ignored())
        {
            for(size_t j = 0; j < m_charges.size(); ++j)
            {
                if(!m_charges[j]->is_ignored() && i != j)
                {
                    const float dx = m_charges[j]->pos().x() - m_charges[i]->pos().x();
                    const float dy = m_charges[j]->pos().y() - m_charges[i]->pos().y();
                    const float distanse = sqrt(dx*dx + dy*dy);
                    w += k*m_charges[i]->charge() * m_charges[j]->charge()/distanse;
                }
            }
        }
    }

    return w;
}

float Engine::calculateWork(const Vector& start, const Vector& dest, float charge) const {
  float p1 = calculatePotential(start);
  float p2 = calculatePotential(dest);
  return charge*p1 - charge*p2;

}

Vector Engine::applyCharge(size_t i)
{
    static const float k = 9000000000;
    Vector res;

    for(size_t j = 0; j < m_charges.size(); j++)
    {
        if(i != j && !m_charges[j]->is_ignored())
        {
            const float dx = m_charges[j]->pos().x() - m_charges[i]->pos().x();
            const float dy = m_charges[j]->pos().y() - m_charges[i]->pos().y();
            const float r = sqrt(dx*dx+dy*dy);
            const float f = k*abs(m_charges[i]->charge()*m_charges[j]->charge())/(r*r*m_dielectric);
            const float fx = f*dx/r;
            const float fy = f*dy/r;

            res += Vector(fx, fy) * (-sign(m_charges[i]->charge() * m_charges[j]->charge()));
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

EngineState Engine::engineState() const
{
    return m_engine_state;
}
