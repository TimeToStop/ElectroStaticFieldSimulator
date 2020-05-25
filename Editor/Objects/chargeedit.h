#ifndef CHARGEEDIT_H
#define CHARGEEDIT_H

#include "Editor/Objects/object.h"

class ChargeEdit : public Object
{
    static unsigned long long m_amount;
    static const int m_r;

    QString m_name;
    Vector m_init_velocity;
    float m_mass;
    float m_charge;
    bool m_is_ignored;
    bool m_is_movable;

public:
    ChargeEdit(const QString& name, const Vector& pos, const Vector& init_vel, float mass, float charge, bool ignore, bool movable, Editor* const);
    ChargeEdit(Editor* const);
    virtual ~ChargeEdit();

    virtual void draw(QPainter &) const override;
    virtual bool intersects(const QRect &) const override;
    virtual bool isClose(const QPoint &) const override;

    virtual void setPos(const Vector &) override;
    virtual void movePos(const Vector&) override;

    virtual void setSelected(bool) override;

    void setInitialVelocityArrow(const Vector&);

    void setName(const QString&);
    void setInitVelocity(const Vector&);
    void setMass(float);
    void setCharge(float);
    void setIgnored(bool);
    void setMovable(bool);

    QString name() const;
    Vector initVelocity() const;
    float mass() const;
    float charge() const;
    bool ignored() const;
    bool movable() const;

protected:
    virtual int index() const override;
};

#endif // CHARGEEDIT_H
