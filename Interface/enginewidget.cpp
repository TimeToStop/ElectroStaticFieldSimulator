#include "enginewidget.h"
#include "Engine/charge.h"
#include <QDebug>

EngineWidget::EngineWidget(QWidget *parent):
    QWidget(parent),
    Engine(),
    m_draw_grid(true),
    m_is_left_mouse_pressed(false),
    m_is_right_mouse_pressed(false),
    m_current_cursor_pos(),
    m_pos_left_mouse_clicked(),
    m_previous_pos_right_mouse_clicked(),
    m_diff_from_start(),
    m_default_time(1.f),
    m_main_timer(),
    m_camera(-1)
{    
    m_main_timer.start(m_default_time);
    connect(&m_main_timer, SIGNAL(timeout()), this, SLOT(timeTick()));
    setFocusPolicy(Qt::StrongFocus);
    setMinimumSize(400, 400);
}

EngineWidget::~EngineWidget()
{
}

void EngineWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    drawBorder(painter);
    Engine::drawCharges(painter);

    if(m_draw_grid)
    {
        drawGrid(painter);
    }

    if(m_draw_field)
    {
        // To able this function, increase m_default_time otherwise it will crash
        drawElectrostaticField(painter);
    }
}

void EngineWidget::mousePressEvent(QMouseEvent* e)
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

void EngineWidget::mouseMoveEvent(QMouseEvent* e)
{
    if(m_is_right_mouse_pressed && m_camera == -1)
    {
        m_diff_from_start += e->pos() - m_previous_pos_right_mouse_clicked;
        m_previous_pos_right_mouse_clicked = e->pos();
    }

    m_current_cursor_pos = e->pos();
    emit(cursorMoved(e->pos()));
    repaint();
}

void EngineWidget::mouseReleaseEvent(QMouseEvent* e)
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
    repaint();
}

void EngineWidget::drawBorder(QPainter& painter)
{
    static const int d = 1;
    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine));
    painter.setBrush(Qt::NoBrush);

    painter.drawLine(0, 0, width() - d, 0);
    painter.drawLine(width() - d, 0, width() - d, height() - d);
    painter.drawLine(width() - d, height() - d, 0, height() - d);
    painter.drawLine(0, height() - d, 0, 0);
}

void EngineWidget::drawSelectingRect(QPainter& painter)
{
    painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine));
    painter.setBrush(QBrush(QColor(0, 0, 255, 80), Qt::SolidPattern));
    painter.drawRect(QRect(m_pos_left_mouse_clicked, m_current_cursor_pos));
}

void EngineWidget::drawGrid(QPainter& painter)
{
    Vector startVector = fromXOY(Vector(0, 0));
    const int startX = startVector.x();
    const int startY = startVector.y();
    Vector stepVector;
    int step;

    painter.setPen(QPen(QColor(100, 100, 100, 60), 1, Qt::SolidLine));

    // ОТРИСОВКА СЕТКИ
    stepVector = fromXOY(Vector(1, 0));
    step = stepVector.x() - startVector.x();
    for(int i = startX % step; i < width(); i += step)
    {
        painter.drawLine(i, 0, i, height());
    }

    for(int i = startY % step; i < height(); i += step)
    {
        painter.drawLine(0, i, width(), i);
    }

    painter.setPen(QPen(QColor(0, 0, 0), 2, Qt::SolidLine));
    // ОТРИСОВКА ОСЕЙ
    painter.drawLine(startX, 0, startX, height());
    painter.drawLine(width(), startY, 0, startY);

    QFont font = painter.font();
    font.setPixelSize(12);
    painter.setFont(font);

    // ОТРИСОВКА ПОЛОСОК КАЖДЫЕ 5 ЕДИНИЦ ПО Х

    stepVector = fromXOY(Vector(5, 0));
    step = stepVector.x() - startVector.x();
    for (int i = startX % step; i < width(); i += step) {
        painter.drawLine(i, startY - 5, i, startY + 5);
    }

    // ОТРИСОВКА ПОЛОСОК КАЖДЫЕ 5 ЕДИНИЦ ПО У
    for (int i = startY % step; i < height(); i += step) {
        painter.drawLine(startX - 5, i, startX + 5, i);
    }

    // ОТРИСОВКА ЧИСЕЛ ПО Х
    Vector vectorX = toXOY(Vector(0, height() / 2));
    for (int i = vectorX.x() - (int)vectorX.x() % 5; fromXOY(Vector(i, startY)).x() < width(); i += 5) {
        painter.drawText(fromXOY(Vector(i, 0)).x(), startY - 10, QString::number(i));
        if (Engine::toXOY(0, 0).y() < 0) {
            painter.drawText(Engine::fromXOY(i, 0).x(), 15, QString::number(i));
        } else if (Engine::toXOY(0, height()).y() > 0) {
            painter.drawText(Engine::fromXOY(i, 0).x(), height() - 10, QString::number(i));
        }

    }

    // ОТРИСОВКА ЧИСЕЛ ПО У
    Vector vectorY = toXOY(Vector(width() / 2, 0));
    qDebug() << vectorY.toPointF();

    for (int i = vectorY.y() - (int)vectorY.y() % 5; fromXOY(Vector(startX, i)).y() < height(); i -= 5) {
        if (i != 0)
            painter.drawText(startX + 10, fromXOY(Vector(startX, i)).y(), QString::number(i));
        if (Engine::fromXOY(0,0).x() < 0) {
            painter.drawText(4, Engine::fromXOY(0, i).y(), QString::number(i));
        } else if (Engine::toXOY(width(), 0).x() < 0) {
            painter.drawText(width() - 25, Engine::fromXOY(0, i).y(), QString::number(i));
        }
    }
}

void EngineWidget::drawElectrostaticField(QPainter& painter) { //Перевести в координаты
    const int stepX = 1;
    const int stepY = 1;
    Vector window_size(toXOY(Vector(width(), height())));
    painter.setPen(QPen(Qt::red, 1.5, Qt::SolidLine));
    qDebug() << window_size.x();
    qDebug() << window_size.y();
    for(int x = toXOY(Vector(0, 0)).x(); x <= window_size.x(); x += stepX) {
        for(int y = toXOY(Vector(0, 0)).y(); y >= window_size.y(); y -= stepY) {
            const Vector tension(Engine::calculateTension(x, y));
            Vector pos(fromXOY(Vector(x, y)));
            painter.drawLine(pos.x(), pos.y(), pos.x() + tension.x()/m_lambda, pos.y() + tension.y()/m_lambda);
        }
    }
}

void EngineWidget::setDrawGrid(bool b)
{
    m_draw_grid = b;
}

void EngineWidget::setCamera(int camera)
{
    m_camera = camera;
    if(m_camera != -1)
    {
        m_diff_from_start = QPoint(0, 0);
    }
}

void EngineWidget::setDrawField(bool b)
{
    m_draw_field = b;
}

QPoint EngineWidget::current_cursos_pos() const
{
    return m_current_cursor_pos;
}

Vector EngineWidget::toXOY(const Vector& vec) const
{
    if(m_camera == -1)
    {
        return Vector(vec.x() - size().width()/2 - m_diff_from_start.x(), -vec.y() + size().height()/2 + m_diff_from_start.y())*m_lambda;
    }
    else
    {
        int temp = m_camera;
        Vector v;
        m_camera = -1;
        v = toXOY(vec - fromXOY(m_charges[temp]->pos()));
        m_camera = temp;
        return v;
    }
}

Vector EngineWidget::fromXOY(const Vector& vec) const
{
    if(m_camera == -1)
    {
        return Vector(vec.x(), -vec.y())/m_lambda + size()/2 + m_diff_from_start;
    }
    else
    {
        int temp = m_camera;
        Vector v;
        m_camera = -1;
        v = fromXOY(vec - m_charges[temp]->pos());
        m_camera = temp;
        return v;
    }
}
