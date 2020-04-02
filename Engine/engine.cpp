#include "engine.h"

#include "Engine/charge.h"
#include <QElapsedTimer>
#include <QDebug>

Engine::Engine(int w, int h, QWidget *parent):
    QWidget(parent),
    m_is_left_mouse_pressed(false),
    m_is_right_mouse_pressed(false),
    m_current_cursor_pos(),
    m_pos_left_mouse_clicked(),
    m_previous_pos_right_mus_clicked(),
    m_diff_from_start(),
    m_default_time(10.f),
    m_main_timer(),
    m_lambda(0.1f),
    m_charges()
{
    m_main_timer.start(m_default_time);
    connect(&m_main_timer, SIGNAL(timeout()), this, SLOT(redraw()));
    setFocusPolicy(Qt::StrongFocus);
    setMinimumSize(w, h);

    m_charges.push_back(std::unique_ptr<Charge>(new Charge(1.f, Vector(), this)));
    m_charges.push_back(std::unique_ptr<Charge>(new Charge(1.f, Vector(1, 0), this)));
    m_charges.push_back(std::unique_ptr<Charge>(new Charge(1.f, Vector(-1, 0), this)));

    m_charges[0]->setVelocity(Vector(0, 40));
    m_charges[0]->addForce(Vector(0, -10));
    m_charges[1]->addForce(Vector(0, -9.8));
    m_charges[2]->addForce(Vector(0, -9.8));
}

Engine::~Engine()
{
}

void Engine::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    drawBorder(painter);
    drawCharges(painter);

    if(m_is_left_mouse_pressed)
    {
        drawSelectingRect(painter);
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
        m_previous_pos_right_mus_clicked = e->pos();
    }

    m_current_cursor_pos = e->pos();
    repaint();
}

void Engine::mouseMoveEvent(QMouseEvent* e)
{
    if(m_is_right_mouse_pressed)
    {
        m_diff_from_start += e->pos() - m_previous_pos_right_mus_clicked;
        m_previous_pos_right_mus_clicked = e->pos();
    }

    m_current_cursor_pos = e->pos();
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
//    QElapsedTimer timer;
//    timer.start();

    for(std::unique_ptr<Charge>& charge : m_charges)
    {
        charge->tick(painter, m_default_time/1000);
    }

//    qDebug() << timer.elapsed();
}

void Engine::drawSelectingRect(QPainter& painter)
{
    painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine));
    painter.setBrush(QBrush(QColor(0, 0, 255, 80), Qt::SolidPattern));

    painter.drawRect(QRect(m_pos_left_mouse_clicked, m_current_cursor_pos));
}

Vector Engine::toXOY(const Vector& vec) const
{
    return (Vector(vec.x(), -vec.y()) + m_diff_from_start - size()/2) * m_lambda;
}

Vector Engine::fromXOY(const Vector& vec) const
{
    return Vector(vec.x(), -vec.y())/m_lambda + size()/2 + m_diff_from_start;
}
