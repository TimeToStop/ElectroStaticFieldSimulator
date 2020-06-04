#include "charge.h"

#include "engine.h"
#include <QDebug>

const int Charge::m_radius = 5;
long long Charge::m_amount = 0;

Charge::Charge(Engine* const engine):
    m_engine(engine),
    m_name("Charge " + QString::number(m_amount++)),
    m_is_movable(true),
    m_charge(0.f),
    m_mass(1.f),
    m_pos(),
    m_velocity(),
    m_acceleration()
{
}

Charge::Charge(float mass, Vector pos, Engine * const engine):
    m_engine(engine),
    m_name("Charge " + QString::number(m_amount++)),
    m_is_movable(true),
    m_charge(0.f),
    m_mass(mass),
    m_pos(pos),
    m_velocity(),
    m_acceleration()
{
}

Charge::Charge(const QString& name, float q, float mass, Vector pos, Engine * const engine):
    m_engine(engine),
    m_name(name),
    m_is_movable(true),
    m_charge(q),
    m_mass(mass),
    m_pos(pos),
    m_velocity(),
    m_acceleration()
{
    m_amount++;
}

Charge::Charge(const QString& name, float q, float mass, Vector pos, Vector vel, bool movable, Engine * const engine):
    m_engine(engine),
    m_name(name),
    m_is_movable(movable),
    m_charge(q),
    m_mass(mass),
    m_pos(pos),
    m_velocity(vel),
    m_acceleration()
{
    m_amount++;
}

Charge::~Charge()
{
    m_amount--;
}

void Charge::draw(QPainter& painter)
{
    if (m_charge < 0) {
      painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine));
      painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    } else {
      painter.setPen(QPen(Qt::darkRed, 1, Qt::SolidLine));
      painter.setBrush(QBrush(Qt::darkRed, Qt::SolidPattern));
    }
    painter.drawEllipse(m_engine->fromXOY(m_pos).toPointF(), m_radius, m_radius);
}

void Charge::tick(float deltatime)
{
    if(m_is_movable)
    {
        m_velocity += m_acceleration * deltatime;
        m_pos += m_velocity * deltatime;
    }
}

void Charge::setMovable(bool b)
{
    m_is_movable = b;
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
    if(m_is_movable)
    {
        m_acceleration += force/m_mass;
    }
}

bool Charge::is_movable() const
{
    return m_is_movable;
}

QString Charge::name() const
{
    return m_name;
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

int Charge::radius() const
{
    return m_radius * m_engine->lambda();
}

long long Charge::amount()
{
    return m_amount;
}
