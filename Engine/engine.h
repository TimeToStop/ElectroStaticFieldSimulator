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

class Charge;

class Engine : public QWidget
{
    Q_OBJECT

    bool m_draw_grid;

    bool m_is_left_mouse_pressed;
    bool m_is_right_mouse_pressed;

    QPoint m_current_cursor_pos;
    QPoint m_pos_left_mouse_clicked;
    QPoint m_previous_pos_right_mouse_clicked;
    QPoint m_diff_from_start;

    const float m_default_time;
    QTimer m_main_timer;

    float m_lambda;
    float m_dielectric;

    static const float SCALE;

    std::vector<std::unique_ptr<Charge>> m_charges;

public:
    explicit Engine(QWidget *parent = nullptr);
    virtual ~Engine();

    Vector toXOY(float, float) const;
    Vector toXOY(const Vector&) const;
    Vector fromXOY(float, float) const;
    Vector fromXOY(const Vector&) const;

    float lambda() const;

    void setDrawGrid(bool);

protected:
    virtual void paintEvent(QPaintEvent *) override;

    virtual void mousePressEvent(QMouseEvent*) override;
    virtual void mouseMoveEvent(QMouseEvent*) override;
    virtual void mouseReleaseEvent(QMouseEvent*) override;

signals:

public slots:
    void redraw();

private:
    void drawBorder(QPainter&);
    void drawCharges(QPainter&);
    void drawSelectingRect(QPainter&);
    void drawGrid(QPainter&);

    void calculateTension(QPainter&);
    void drawTension(QPainter&, const Vector&, const Vector&);

    Vector applyCharge(size_t);

    static int sign(float);
};

#endif // ENGINE_H
