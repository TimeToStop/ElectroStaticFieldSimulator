#ifndef PLOTGRIDWIDGET_H
#define PLOTGRIDWIDGET_H

#include "Engine/vector.h"

#include <QPaintEvent>
#include <QMouseEvent>
#include <QWheelEvent>

#include <QPainter>
#include <QWidget>

class PlotGridWidget : public QWidget
{
    Q_OBJECT

    bool m_is_draw_border;
    bool m_is_draw_grid;

protected:
    bool m_is_left_mouse_pressed;
    bool m_is_right_mouse_pressed;

    QPoint m_current_cursor_pos;
    QPoint m_pos_left_mouse_clicked;
    QPoint m_previous_pos_right_mouse_clicked;
    QPoint m_diff_from_start;

    float m_scale;

public:
    explicit PlotGridWidget(QWidget *parent = nullptr);
    virtual ~PlotGridWidget();

    void setDrawBorder(bool);
    void setDrawGrid(bool);

    Vector toXOY(const Vector&) const;
    Vector toXOY(float, float) const;
    Vector fromXOY(const Vector&) const;
    Vector fromXOY(float, float) const;

    float scale() const;

protected:
    virtual void paintEvent(QPaintEvent*) override;

    virtual void mousePressEvent(QMouseEvent*) override;
    virtual void mouseMoveEvent(QMouseEvent*) override;
    virtual void mouseReleaseEvent(QMouseEvent*) override;

    virtual void wheelEvent(QWheelEvent *event) override;

private:
    void drawBorder(QPainter&);
    void drawSelectingRect(QPainter&);
    void drawGrid(QPainter&);
};

#endif // PLOTGRIDWIDGET_H
