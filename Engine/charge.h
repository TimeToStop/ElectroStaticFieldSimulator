#ifndef CHARGE_H
#define CHARGE_H

#include <QPainter>
#include <QPointF>

#include "vector.h"

class Engine;

class Charge
{
    Engine* const m_engine;

    static const int m_radius;

    float m_charge;
    float m_mass;

    Vector m_pos;
    Vector m_velocity;
    Vector m_acceleration;

public:
    Charge(Engine* const);
    Charge(float, Vector, Engine * const);
    ~Charge();

    void tick(QPainter&, float);

    void setPos(const Vector&);
    void setVelocity(const Vector&);
    void setAcceleration(const Vector&);
    void setForce(const Vector&);
    void setMass(float);
    void setCharge(float);

    void movePos(const Vector&);
    void addForce(const Vector&);

    Vector pos() const;
    Vector velocity() const;
    Vector acceleration() const;
    float mass() const;
    float charge() const;

    int radius() const;

private:
    void draw(QPainter&) const;
    void tick(float);
};

#endif // CHARGE_H
