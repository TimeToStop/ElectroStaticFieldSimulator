#ifndef ENGINEWIDGET_H
#define ENGINEWIDGET_H

#include "Engine/engine.h"
#include <QWidget>

class EngineWidget:
        public QWidget,
        public Engine
{
    Q_OBJECT

    bool m_draw_grid;
    bool m_draw_field;

    bool m_is_left_mouse_pressed;
    bool m_is_right_mouse_pressed;

    QPoint m_current_cursor_pos;
    QPoint m_pos_left_mouse_clicked;
    QPoint m_previous_pos_right_mouse_clicked;
    QPoint m_diff_from_start;

    const float m_default_time;
    QTimer m_main_timer;
    
    mutable int m_camera;

public:
    explicit EngineWidget(QWidget *parent = nullptr);
    virtual ~EngineWidget();

    void setDrawGrid(bool);
    void setCamera(int);
    void setDrawField(bool);

    QPoint current_cursos_pos() const;

    virtual Vector toXOY(const Vector&) const override;
    virtual Vector fromXOY(const Vector&) const override;

protected:
    virtual void paintEvent(QPaintEvent *) override;

    virtual void mousePressEvent(QMouseEvent*) override;
    virtual void mouseMoveEvent(QMouseEvent*) override;
    virtual void mouseReleaseEvent(QMouseEvent*) override;

signals:
    void cursorMoved(const QPoint&);
    void blockCursor();

public slots:
    void timeTick();

private:
    void drawBorder(QPainter&);
    void drawCharges(QPainter&);
    void drawSelectingRect(QPainter&);
    void drawGrid(QPainter&);
    void drawElectrostaticField(QPainter&);
};

#endif // ENGINEWIDGET_H
