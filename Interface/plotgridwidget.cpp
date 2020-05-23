#include "plotgridwidget.h"

PlotGridWidget::PlotGridWidget(QWidget *parent):
    QWidget(parent),
    m_is_draw_border(true),
    m_is_draw_grid(true),
    m_is_left_mouse_pressed(false),
    m_is_right_mouse_pressed(false),
    m_current_cursor_pos(),
    m_pos_left_mouse_clicked(),
    m_previous_pos_right_mouse_clicked(),
    m_diff_from_start(),
    m_scale(0.1f)
{   
}

PlotGridWidget::~PlotGridWidget()
{
}

void PlotGridWidget::setDrawBorder(bool b)
{
    m_is_draw_border = b;
}

void PlotGridWidget::setDrawGrid(bool b)
{
    m_is_draw_grid = b;
}

Vector PlotGridWidget::toXOY(const Vector& vec) const
{
    return Vector(vec.x() - size().width()/2 - m_diff_from_start.x(), -vec.y() + size().height()/2 + m_diff_from_start.y())*m_scale;
}

Vector PlotGridWidget::toXOY(float x, float y) const
{
    return toXOY(Vector(x, y));
}

Vector PlotGridWidget::fromXOY(const Vector& vec) const
{
    return Vector(vec.x(), -vec.y())/m_scale + size()/2 + m_diff_from_start;
}

Vector PlotGridWidget::fromXOY(float x, float y) const
{
    return fromXOY(Vector(x, y));
}

float PlotGridWidget::scale() const
{
    return m_scale;
}

void PlotGridWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    if(m_is_draw_border)
    {
        drawGrid(painter);
    }

    if(m_is_draw_border)
    {
        drawBorder(painter);
    }
}

void PlotGridWidget::mousePressEvent(QMouseEvent* e)
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

void PlotGridWidget::mouseMoveEvent(QMouseEvent* e)
{
    if(m_is_right_mouse_pressed)
    {
        m_diff_from_start += e->pos() - m_previous_pos_right_mouse_clicked;
        m_previous_pos_right_mouse_clicked = e->pos();
    }

    m_current_cursor_pos = e->pos();
    repaint();
}

void PlotGridWidget::mouseReleaseEvent(QMouseEvent* e)
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

void PlotGridWidget::wheelEvent(QWheelEvent *)
{

}

void PlotGridWidget::drawBorder(QPainter& painter)
{
    static const int d = 1;
    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine));
    painter.setBrush(Qt::NoBrush);

    painter.drawLine(0, 0, width() - d, 0);
    painter.drawLine(width() - d, 0, width() - d, height() - d);
    painter.drawLine(width() - d, height() - d, 0, height() - d);
    painter.drawLine(0, height() - d, 0, 0);
}

void PlotGridWidget::drawSelectingRect(QPainter& painter)
{
    painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine));
    painter.setBrush(QBrush(QColor(0, 0, 255, 80), Qt::SolidPattern));
    painter.drawRect(QRect(m_pos_left_mouse_clicked, m_current_cursor_pos));
}

void PlotGridWidget::drawGrid(QPainter& painter)
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
    for (int i = startX % step; i < width(); i += step)
    {
        painter.drawLine(i, startY - 5, i, startY + 5);
    }

    // ОТРИСОВКА ПОЛОСОК КАЖДЫЕ 5 ЕДИНИЦ ПО У
    for (int i = startY % step; i < height(); i += step)
    {
        painter.drawLine(startX - 5, i, startX + 5, i);
    }

    // ОТРИСОВКА ЧИСЕЛ ПО Х
    Vector vectorX = toXOY(Vector(0, height() / 2));
    for (int i = vectorX.x() - (int)vectorX.x() % 5; fromXOY(Vector(i, startY)).x() < width(); i += 5)
    {
        painter.drawText(fromXOY(Vector(i, 0)).x(), startY - 10, QString::number(i));
        if (toXOY(0, 0).y() < 0)
        {
            painter.drawText(fromXOY(i, 0).x(), 15, QString::number(i));
        }
        else if (toXOY(0, height()).y() > 0)
        {
            painter.drawText(fromXOY(i, 0).x(), height() - 10, QString::number(i));
        }

    }

    // ОТРИСОВКА ЧИСЕЛ ПО У
    Vector vectorY = toXOY(Vector(width() / 2, 0));

    for (int i = vectorY.y() - (int)vectorY.y() % 5; fromXOY(Vector(startX, i)).y() < height(); i -= 5)
    {
        if (i != 0)
        {
             painter.drawText(startX + 10, fromXOY(Vector(startX, i)).y(), QString::number(i));
        }

        if (fromXOY(0,0).x() < 0)
        {
            painter.drawText(4, fromXOY(0, i).y(), QString::number(i));
        }
        else if (toXOY(width(), 0).x() < 0)
        {
            painter.drawText(width() - 25, fromXOY(0, i).y(), QString::number(i));
        }
    }
}
