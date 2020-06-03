#ifndef ENGINE_H
#define ENGINE_H

#include <QWidget>

#include <QPainter>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QMouseEvent>
#include <memory>

#include "vector.h"
#include <QTimer>

enum EngineState
{
    PLAY,
    PAUSE,
    SPEED_2,
    EDIT
};

class Charge;

class Engine
{
protected:
    float m_lambda;
    float m_dielectric;

    std::vector<std::unique_ptr<Charge>> m_charges;

    EngineState m_engine_state;

public:
    Engine();
    virtual ~Engine();

    virtual Vector fromXOY(const Vector&) const = 0;
    virtual Vector toXOY(const Vector&) const = 0;
    Vector toXOY(float, float) const;
    Vector fromXOY(float, float) const;

    void drawCharges(QPainter&);
    void tick(float);

    void setEngineState(EngineState);
    EngineState engineState() const;

    void addCharge(std::unique_ptr<Charge>&&);
    void rmCharge(size_t);
    void clearCharges();

    size_t chargesNum() const;
    bool hasCharges() const;
    std::unique_ptr<Charge>& getCharge(size_t i);
    QStringList chargeNames() const;
    float lambda() const;
    void setLambda(float);

    Vector calculateTension(const Vector&) const;
    float calculatePotential(const Vector&) const;
    float calculateEnergy(const Vector&) const;
    float calculateKineticEnergy(const int index) const;
    float calculateKineticEnergyOfSystem() const;
    float calculateEnergyOfSystem() const;
    float calculateWork(const Vector& start, const Vector& dest, float charge) const;

    Vector applyCharge(size_t);
    static int sign(float);
};

#endif // ENGINE_H
