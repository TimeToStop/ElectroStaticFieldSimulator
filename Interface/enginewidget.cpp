#include "enginewidget.h"
#include "Engine/charge.h"

EngineWidget::EngineWidget(QWidget *parent):
    PlotGridWidget(parent),
    Engine(),
    m_draw_grid(true),
    m_draw_field(false),
    m_default_time(1.f),
    m_main_timer(),
    m_camera(-1)
{    
    m_main_timer.start(m_default_time);
    connect(&m_main_timer, SIGNAL(timeout()), this, SLOT(timeTick()));
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);
    setMinimumSize(400, 400);
}

EngineWidget::~EngineWidget()
{
}

void EngineWidget::paintEvent(QPaintEvent* e)
{
    PlotGridWidget::paintEvent(e);

    QPainter painter(this);
    Engine::drawCharges(painter);

    if(m_draw_field)
    {
        drawElectrostaticField(painter);
    }
}

void EngineWidget::mousePressEvent(QMouseEvent * e)
{
    PlotGridWidget::mousePressEvent(e);
}

void EngineWidget::mouseMoveEvent(QMouseEvent * e)
{
    PlotGridWidget::mouseMoveEvent(e);
}

void EngineWidget::mouseReleaseEvent(QMouseEvent * e)
{
    PlotGridWidget::mouseReleaseEvent(e);
}

void EngineWidget::timeTick()
{
    // TODO: Count tick
    float tick = m_default_time/1000.f;

    switch (m_engine_state)
    {
    case PAUSE:
    case EDIT:
        return;
    case SPEED_2:
        tick *= 2;
        break;
    case PLAY:
        break;
    }

    Engine::tick(tick);
    emit(recountPhysics());
    repaint();
}

void EngineWidget::drawElectrostaticField(QPainter& painter)
{
    const int stepX = 1;
    const int stepY = 1;
    Vector window_size(toXOY(Vector(width(), height())));
    painter.setPen(QPen(Qt::red, 1.5, Qt::SolidLine));
    for(int x = toXOY(Vector(0, 0)).x(); x <= window_size.x(); x += stepX)
    {
        for(int y = toXOY(Vector(0, 0)).y(); y >= window_size.y(); y -= stepY)
        {
            const Vector tension = Engine::calculateTension(Vector(x, y));
            Vector pos = fromXOY(Vector(x, y));
            Vector t = tension/ tension.module();
            t *= 7.f;
            painter.drawLine(pos.x(), pos.y(), pos.x() + t.x(), pos.y() + t.y());
        }
    }
}

void EngineWidget::setDrawGrid(bool b)
{
    m_draw_grid = b;
}

void EngineWidget::setCamera(int camera)
{
}

void EngineWidget::setDrawField(bool b)
{
    m_draw_field = b;
}
