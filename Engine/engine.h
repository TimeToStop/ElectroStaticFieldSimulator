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

    void drawCharges(QPainter&);
    void tick(float);

    void addCharge(std::unique_ptr<Charge>&&);
    void rmCharge(size_t);

    size_t chargesNum() const;
    bool hasCharges() const;

    const std::unique_ptr<Charge>& getCharge(size_t i) const;

    QStringList chargeNames() const;
    float lambda() const;

    Vector toXOY(float, float) const;
    virtual Vector toXOY(const Vector&) const = 0;
    Vector fromXOY(float, float) const;
    virtual Vector fromXOY(const Vector&) const = 0;

    Vector applyCharge(size_t);
    static int sign(float);

    void setEngineState(EngineState);
};

#endif // ENGINE_H
