#include "editor.h"

#include "Editor/Objects/object.h"
#include "Editor/Objects/chargeedit.h"
#include "Interface/Charge/createchargedialog.h"

#include <QMenu>

Editor::Editor(QWidget* parent):
    PlotGridWidget(parent),
    m_has_object_selected(false),
    m_prev_pos(),
    m_current_charge_selected(nullptr),
    m_objects()
{
    setContextMenuPolicy(Qt::CustomContextMenu);
    setFocusPolicy(Qt::StrongFocus);
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
    else if(e->button() == Qt::RightButton)
    {
        m_current_charge_selected = nullptr;

        for(std::vector<std::shared_ptr<Object>>::iterator it = m_objects.begin(); it != m_objects.end(); ++it)
        {
            if((*it)->isClose(e->pos()))
            {
                m_current_charge_selected = dynamic_cast<ChargeEdit*>(it->get());
                showContexMenu(e->pos());
                break;
            }
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
            obj->setSelected(false);
        }

        for(std::shared_ptr<Object>& obj : m_objects)
        {
            if(obj->intersects(rect))
            {
                obj->setSelected(true);
                m_has_object_selected = true;
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
            if(obj->isSelected())
            {
                obj->movePos(v);
            }
        }
    }

    m_prev_pos = e->pos();
    repaint();
}

void Editor::mouseReleaseEvent(QMouseEvent * e)
{
    PlotGridWidget::mouseReleaseEvent(e);
}

void Editor::keyPressEvent(QKeyEvent* e)
{
    if(e->key() == Qt::Key_Delete)
    {
        for(std::vector<std::shared_ptr<Object>>::iterator it = m_objects.begin(); it < m_objects.end(); ++it)
        {
            if((*it)->isSelected())
            {
                rmObject(*it);
                it = m_objects.begin() - 1;
            }
        }
    }

    m_is_left_mouse_pressed = false;
    m_is_right_mouse_pressed = false;
    repaint();
}

void Editor::addObject(const std::shared_ptr<Object>& object)
{
    for(size_t i = 0; i < m_objects.size(); i++)
    {
        if(Object::isLeftGreater(object, m_objects[i]))
        {
            m_objects.insert(m_objects.begin() + i, object);
            return;
        }
    }

    m_objects.push_back(object);
}

void Editor::rmObject(const std::shared_ptr<Object> & object)
{
    for(size_t i = 0; i < m_objects.size(); i++)
    {
        if(m_objects[i] == object)
        {
            m_objects.erase(m_objects.begin() + i);
            return;
        }
    }
}

void Editor::rmObject(Object* obj)
{
    for(size_t i = 0; i < m_objects.size(); i++)
    {
        if(m_objects[i].get() == obj)
        {
            m_objects.erase(m_objects.begin() + i);
            return;
        }
    }
}

void Editor::bind(Arrow * arrow, ChargeEdit * charge)
{
    m_mediator.bindPair(arrow, charge);
}

Arrow *Editor::get(ChargeEdit* charge)
{
    return m_mediator.get(charge);
}

ChargeEdit *Editor::get(Arrow* arrow)
{
    return m_mediator.get(arrow);
}

void Editor::rm(Arrow* arrow)
{
    m_mediator.rm(arrow);
}

void Editor::rm(ChargeEdit* charge)
{
    m_mediator.rm(charge);
}

void Editor::menuOpened()
{
    CreateChargeDialog d1(QStringList(), this);

    d1.setName(m_current_charge_selected->name());
    d1.setPos(m_current_charge_selected->pos());
    d1.setVel(m_current_charge_selected->initVelocity());
    d1.setMass(m_current_charge_selected->mass());
    d1.setCharge(m_current_charge_selected->charge());
    d1.setIgnored(m_current_charge_selected->ignored());
    d1.setMovable(m_current_charge_selected->movable());

    if(d1.exec() == QDialog::Accepted)
    {
        m_current_charge_selected->setName(d1.name());
        m_current_charge_selected->setPos(d1.pos());
        m_current_charge_selected->setInitVelocity(d1.vel());
        m_current_charge_selected->setMass(d1.mass());
        m_current_charge_selected->setCharge(d1.charge());
        m_current_charge_selected->setIgnored(d1.is_ignored());
        m_current_charge_selected->setMovable(d1.is_movable());
    }
}

void Editor::initialVelocity()
{
    m_current_charge_selected->setInitialVelocityArrow(Vector(5, 0));
    repaint();
}

void Editor::rmInitialVelocity()
{
    rmObject(get(m_current_charge_selected));
    repaint();
}

void Editor::drawSelectingRect(QPainter& painter)
{
    painter.setPen(QPen(QColor(0, 0, 255, 120), 2, Qt::SolidLine));
    painter.setBrush(QBrush(QColor(0, 0, 200, 80), Qt::SolidPattern));

    painter.drawRect(QRect(m_pos_left_mouse_clicked, m_current_cursor_pos));
}

void Editor::showContexMenu(const QPoint& pos)
{
    QMenu* menu = new QMenu(this);

    QAction* properites = menu->addAction("Properties");
    connect(properites, SIGNAL(triggered()), this, SLOT(menuOpened()));

    if(get(m_current_charge_selected) != nullptr)
    {
        QAction* rm = menu->addAction("Remove Initial Velocity");
        connect(rm, SIGNAL(triggered()), this, SLOT(rmInitialVelocity()));
    }
    else
    {
        QAction* add = menu->addAction("Add Initial Velocity");
        connect(add, SIGNAL(triggered()), this, SLOT(initialVelocity()));
    }

    menu->popup(mapToGlobal(pos));
    m_is_left_mouse_pressed = false;
    m_is_right_mouse_pressed = false;
}
