#ifndef CHARGE_H
#define CHARGE_H

#include <QPainter>
#include <QPointF>

#include "vector.h"

class Engine;

class Charge
{
    static const int m_radius;
    static long long m_amount;

    Engine* const m_engine;
    QString m_name;

    bool m_is_ignored;
    bool m_is_movable;

    float m_charge;
    float m_mass;

    Vector m_pos;
    Vector m_velocity;
    Vector m_acceleration;

public:
    Charge(Engine* const);
    Charge(float, Vector, Engine * const);
    Charge(const QString&, float, float, Vector, Engine* const);
    Charge(const QString&, float, float, Vector, bool, bool, Engine* const);
    ~Charge();

    void draw(QPainter&);
    void tick(float);

    void setIgnore(bool);
    void setMovable(bool);
    void setPos(const Vector&);
    void setVelocity(const Vector&);
    void setAcceleration(const Vector&);
    void setForce(const Vector&);
    void setMass(float);
    void setCharge(float);

    void movePos(const Vector&);
    void addForce(const Vector&);

    bool is_ignored() const;
    bool is_movable() const;
    QString name() const;
    Vector pos() const;
    Vector velocity() const;
    Vector acceleration() const;
    float mass() const;
    float charge() const;

    int radius() const;

    static long long amount();
};

#endif // CHARGE_H
