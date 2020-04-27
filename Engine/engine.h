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

    void addCharge(std::unique_ptr<Charge>&&);
    void rmCharge(size_t);

    size_t chargesNum() const;
    bool hasCharges() const;
    const std::unique_ptr<Charge>& getCharge(size_t i) const;
    QStringList chargeNames() const;
    float lambda() const;

    Vector calculateTension(float x, float y);
    float calculatePotential(float x, float y);

    Vector applyCharge(size_t);
    static int sign(float);
};

#endif // ENGINE_H
