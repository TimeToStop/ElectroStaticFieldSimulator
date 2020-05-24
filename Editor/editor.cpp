#include "editor.h"

#include "Editor/Objects/object.h"
#include "Editor/Objects/chargeedit.h"

Editor::Editor(QWidget* parent):
    PlotGridWidget(parent),
    m_has_object_selected(false),
    m_prev_pos(),
    m_objects()
{
    m_objects.push_back(std::make_shared<ChargeEdit>(this));
}

Editor::~Editor()
{
}

void Editor::paintEvent(QPaintEvent * e)
{
    PlotGridWidget::paintEvent(e);
    QPainter painter(this);

    for(std::shared_ptr<Object>& obj : m_objects)
    {
        obj->draw(painter);
    }

    if(m_is_left_mouse_pressed)
    {
        drawSelectingRect(painter);
    }
}

void Editor::mousePressEvent(QMouseEvent * e)
{
    PlotGridWidget::mousePressEvent(e);

    if(e->button() == Qt::LeftButton)
    {
        m_has_object_selected = false;
        for(std::shared_ptr<Object>& obj : m_objects)
        {
            obj->setSelected(false);
        }
    }

    m_prev_pos = e->pos();
    repaint();
}

void Editor::mouseMoveEvent(QMouseEvent * e)
{
    if(!m_has_object_selected)
    {
         PlotGridWidget::mouseMoveEvent(e);
    }
    else
    {
        m_previous_pos_right_mouse_clicked = e->pos();
        m_current_cursor_pos = e->pos();
    }

    if(m_is_left_mouse_pressed)
    {
        QRect rect(m_pos_left_mouse_clicked, m_current_cursor_pos);
        m_has_object_selected = false;

        for(std::shared_ptr<Object>& obj : m_objects)
        {
            if(obj->intersects(rect))
            {
                obj->setSelected(true);
                m_has_object_selected = true;
            }
            else
            {
                obj->setSelected(false);
            }
        }
    }
    else if(m_is_right_mouse_pressed && m_has_object_selected)
    {
        Vector v(e->pos() - m_prev_pos);
        v *= m_scale;
        v = Vector(v.x(), -v.y());

        for(std::shared_ptr<Object>& obj : m_objects)
        {
            obj->movePos(v);
        }
    }

    m_prev_pos = e->pos();
    repaint();
}

void Editor::mouseReleaseEvent(QMouseEvent * e)
{
    PlotGridWidget::mouseReleaseEvent(e);
}

Arrow *Editor::get(ChargeEdit* charge)
{
    return m_mediator.get(charge);
}

ChargeEdit *Editor::get(Arrow* arrow)
{
    return m_mediator.get(arrow);
}

void Editor::drawSelectingRect(QPainter& painter)
{
    painter.setPen(QPen(QColor(0, 0, 255, 120), 2, Qt::SolidLine));
    painter.setBrush(QBrush(QColor(0, 0, 200, 80), Qt::SolidPattern));

    painter.drawRect(QRect(m_pos_left_mouse_clicked, m_current_cursor_pos));
}
