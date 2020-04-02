#include "charge.h"

#include "Engine/engine.h"

const int Charge::m_radius = 5;

Charge::Charge(Engine* const engine):
    m_engine(engine),
    m_charge(0.f),
    m_mass(1.f),
    m_pos(),
    m_velocity(),
    m_acceleration()
{
}

Charge::Charge(float mass, Vector pos, Engine * const engine):
    m_engine(engine),
    m_charge(0.f),
    m_mass(mass),
    m_pos(pos),
    m_velocity(),
    m_acceleration()
{
}

Charge::~Charge()
{
}

void Charge::tick(QPainter& painter, float deltatime)
{
    draw(painter);
    tick(deltatime);
}

void Charge::setPos(const Vector& pos)
{
    m_pos = pos;
}

void Charge::setVelocity(const Vector& v)
{
    m_velocity = v;
}

void Charge::setAcceleration(const Vector& a)
{
    m_acceleration = a;
}

void Charge::setForce(const Vector& f)
{
    m_acceleration = f/m_mass;
}

void Charge::setMass(float m)
{
    m_mass = m;
}

void Charge::setCharge(float c)
{
    m_charge = c;
}

void Charge::movePos(const Vector& pos)
{
    m_pos = pos;
}

void Charge::addForce(const Vector& force)
{
    m_acceleration += force/m_mass;
}

Vector Charge::pos() const
{
    return m_pos;
}

Vector Charge::velocity() const
{
    return m_velocity;
}

Vector Charge::acceleration() const
{
    return m_acceleration;
}

float Charge::mass() const
{
    return m_mass;
}

float Charge::charge() const
{
    return m_charge;
}

void Charge::draw(QPainter& painter) const
{
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine));
    painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
    painter.drawEllipse(m_engine->fromXOY(m_pos).toPointF(), m_radius, m_radius);
}

void Charge::tick(float deltatime)
{
    m_velocity += m_acceleration * deltatime;
    m_pos += m_velocity * deltatime;
}
