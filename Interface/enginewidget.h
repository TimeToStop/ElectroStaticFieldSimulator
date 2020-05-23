#ifndef ENGINEWIDGET_H
#define ENGINEWIDGET_H

#include "Engine/engine.h"
#include "Interface/plotgridwidget.h"
#include <QWidget>

class EngineWidget:
        public PlotGridWidget,
        public Engine
{
    Q_OBJECT

    bool m_draw_grid;
    bool m_draw_field;

    const float m_default_time;
    QTimer m_main_timer;
    
    mutable int m_camera;

public:
    explicit EngineWidget(QWidget *parent = nullptr);
    virtual ~EngineWidget();

    void setDrawGrid(bool);
    void setCamera(int);
    void setDrawField(bool);

    QPoint currentCursorPos() const;

protected:
    virtual void paintEvent(QPaintEvent*) override;

    virtual void mousePressEvent(QMouseEvent*) override;
    virtual void mouseMoveEvent(QMouseEvent*) override;
    virtual void mouseReleaseEvent(QMouseEvent*) override;

signals:
    void leftButtonClicked();
    void recountPhysics();
    void cursorMoved(const QPoint&);

public slots:
    void timeTick();

private:
    void drawCharges(QPainter&);
    void drawElectrostaticField(QPainter&);
};

#endif // ENGINEWIDGET_H
