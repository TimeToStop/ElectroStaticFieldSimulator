#ifndef ENGINE_H
#define ENGINE_H

#include <QWidget>

#include <QPainter>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QMouseEvent>
#include <memory>

#include "Engine/vector.h"
#include <QTimer>

class Charge;

class Engine : public QWidget
{
    Q_OBJECT

    bool m_is_left_mouse_pressed;
    bool m_is_right_mouse_pressed;

    QPoint m_current_cursor_pos;
    QPoint m_pos_left_mouse_clicked;
    QPoint m_previous_pos_right_mus_clicked;
    QPoint m_diff_from_start;

    const float m_default_time;
    QTimer m_main_timer;

    float m_lambda;

    std::vector<std::unique_ptr<Charge>> m_charges;

public:
    explicit Engine(int, int, QWidget *parent = nullptr);
    virtual ~Engine();

    Vector toXOY(const Vector&) const;
    Vector fromXOY(const Vector&) const;

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
};

#endif // ENGINE_H
