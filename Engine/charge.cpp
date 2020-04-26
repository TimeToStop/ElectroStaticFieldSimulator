#include "charge.h"

#include "engine.h"

const int Charge::m_radius = 5;
long long Charge::m_amount = 0;

Charge::Charge(Engine* const engine):
    m_engine(engine),
    m_name("Charge " + QString::number(m_amount++)),
    m_is_ignored(false),
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
    m_is_ignored(false),
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
    m_is_ignored(false),
    m_charge(q),
    m_mass(mass),
    m_pos(pos),
    m_velocity(),
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
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine));
    painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
    painter.drawEllipse(m_engine->fromXOY(m_pos).toPointF(), m_radius, m_radius);
}

void Charge::tick(float deltatime)
{
    m_velocity += m_acceleration * deltatime;
    m_pos += m_velocity * deltatime;
}

void Charge::setIgnore(bool b)
{
    m_is_ignored = b;
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

bool Charge::is_ignored() const
{
    return m_is_ignored;
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
