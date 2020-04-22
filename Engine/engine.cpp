#include "engine.h"

#include "charge.h"
#include <QElapsedTimer>
#include <QDebug>

const float Engine::SCALE = 1.f;

Engine::Engine(QWidget *parent):
    QWidget(parent),
    m_draw_grid(true),
    m_is_left_mouse_pressed(false),
    m_is_right_mouse_pressed(false),
    m_current_cursor_pos(),
    m_pos_left_mouse_clicked(),
    m_previous_pos_right_mouse_clicked(),
    m_diff_from_start(),
    m_default_time(10.f),
    m_main_timer(),
    m_lambda(0.1f),
    m_dielectric(1.f),
    m_charges()
{
    m_main_timer.start(m_default_time);
    connect(&m_main_timer, SIGNAL(timeout()), this, SLOT(redraw()));
    setFocusPolicy(Qt::StrongFocus);
    setMinimumSize(400, 400);

    m_charges.push_back(std::unique_ptr<Charge>(new Charge(0.1f, Vector(3, 3), this)));
    m_charges.push_back(std::unique_ptr<Charge>(new Charge(0.1f, Vector(2, -1), this)));
    m_charges.push_back(std::unique_ptr<Charge>(new Charge(1.f, Vector(-1, 0), this)));

    m_charges[0]->setCharge(0.00001);
    m_charges[1]->setCharge(-0.00001);
    m_charges[2]->setCharge(0.00001);
}

Engine::~Engine()
{
}

void Engine::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    drawBorder(painter);
    drawCharges(painter);
    calculateTension(painter);

//    if(m_is_left_mouse_pressed)
//    {
//        drawSelectingRect(painter);
//    }

    if(m_draw_grid)
    {
        drawGrid(painter);
    }
}

void Engine::mousePressEvent(QMouseEvent* e)
{
    if((e->button() == Qt::LeftButton && m_is_right_mouse_pressed)
            || (e->button() == Qt::RightButton && m_is_left_mouse_pressed))
    {
        m_is_left_mouse_pressed = false;
        m_is_right_mouse_pressed = false;
        return;
    }

    if(e->button() == Qt::LeftButton)
    {
        m_is_left_mouse_pressed = true;
        m_pos_left_mouse_clicked = e->pos();
    }
    else if(e->button() == Qt::RightButton)
    {
        m_is_right_mouse_pressed = true;
        m_previous_pos_right_mouse_clicked = e->pos();
    }

    m_current_cursor_pos = e->pos();
    repaint();
}

void Engine::mouseMoveEvent(QMouseEvent* e)
{
    if(m_is_right_mouse_pressed)
    {
        m_diff_from_start += e->pos() - m_previous_pos_right_mouse_clicked;
        m_previous_pos_right_mouse_clicked = e->pos();
    }

    m_current_cursor_pos = e->pos();
    repaint();
}

void Engine::mouseReleaseEvent(QMouseEvent* e)
{
    if(e->button() == Qt::LeftButton)
    {
        m_is_left_mouse_pressed = false;
    }
    else if(e->button() == Qt::RightButton)
    {
        m_is_right_mouse_pressed = false;
    }

    m_current_cursor_pos = e->pos();
    repaint();
}

void Engine::redraw()
{
    repaint();
}

void Engine::drawBorder(QPainter& painter)
{
    static const int d = 1;
    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine));
    painter.setBrush(Qt::NoBrush);

    painter.drawLine(0, 0, width() - d, 0);
    painter.drawLine(width() - d, 0, width() - d, height() - d);
    painter.drawLine(width() - d, height() - d, 0, height() - d);
    painter.drawLine(0, height() - d, 0, 0);
}

void Engine::drawCharges(QPainter& painter)
{
    //QElapsedTimer timer;
    //timer.start();

    for(size_t i = 0; i < m_charges.size(); i++)
    {
        m_charges[i]->setForce(applyCharge(i));
    }

    for(std::unique_ptr<Charge>& charge : m_charges)
    {
        charge->tick(painter, m_default_time/1000);
    }

    //qDebug() << timer.elapsed();
}

void Engine::drawSelectingRect(QPainter& painter)
{
    painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine));
    painter.setBrush(QBrush(QColor(0, 0, 255, 80), Qt::SolidPattern));
    painter.drawRect(QRect(m_pos_left_mouse_clicked, m_current_cursor_pos));
}

void Engine::drawGrid(QPainter& painter)
{
    const int step = width() / 25;
    painter.setPen(QPen(QColor(100, 100, 100, 120), 1, Qt::SolidLine));

    for(int i = m_diff_from_start.x() % step; i < width(); i += step)
    {
        painter.drawLine(i, 0, i, height());
    }

    for(int i = m_diff_from_start.y() % step; i < height(); i += step)
    {
        painter.drawLine(0, i, width(), i);
    }
}

void Engine::calculateTension(QPainter & painter)
{
}

void Engine::drawTension(QPainter& painter, const Vector& pos, const Vector& tension)
{
}

Vector Engine::applyCharge(size_t i)
{
    static const float k = 9000000000;
    Vector res;

    for(size_t j = 0; j < m_charges.size(); j++)
    {
        if(i != j)
        {
            const float dx = m_charges[j]->pos().x() - m_charges[i]->pos().x();
            const float dy = m_charges[j]->pos().y() - m_charges[i]->pos().y();
            const float r = sqrt(dx*dx+dy*dy);
            const float f = k*abs(m_charges[i]->charge()*m_charges[j]->charge())/(r*r*m_dielectric);
            const float fx = f*abs(dx)/r;
            const float fy = f*abs(dy)/r;

            res += Vector(sign(dx)*fx, sign(dy)*fy) * (-sign(m_charges[i]->charge() * m_charges[j]->charge()));
        }
    }

    return res;
}

int Engine::sign(float x)
{
    return (x > 0) ? 1 : -1;
}

Vector Engine::toXOY(float x, float y) const
{
    return toXOY(Vector(x, y));
}

Vector Engine::toXOY(const Vector& vec) const
{
    return Vector(vec.x() - size().width()/2 - m_diff_from_start.x(), -vec.y() + size().height()/2 + m_diff_from_start.y())*m_lambda;
}

Vector Engine::fromXOY(float x, float y) const
{
    return fromXOY(Vector(x, y));
}

Vector Engine::fromXOY(const Vector& vec) const
{
    return Vector(vec.x(), -vec.y())/m_lambda + size()/2 + m_diff_from_start;
}

float Engine::lambda() const
{
    return m_lambda;
}

void Engine::setDrawGrid(bool b)
{
    m_draw_grid = b;
}
