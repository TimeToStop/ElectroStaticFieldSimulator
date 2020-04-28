#include "widget.h"

#include "Interface/Charge/createcharge.h"
#include "Interface/Charge/ignorecharge.h"
#include "Interface/Charge/selectcharge.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QMenuBar>
#include <QMenu>
#include <QTabWidget>

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QComboBox>
#include <QSlider>
#include <QDebug>

Widget::Widget(QWidget *parent):
    QWidget(parent),
    m_tool_bar(nullptr),
    m_engine(nullptr),
    m_tension_use_cursor(nullptr),
    m_tension_pos_x(nullptr),
    m_tension_pos_y(nullptr),
    m_tension_val(nullptr),
    m_tension_val_x(nullptr),
    m_tension_val_y(nullptr),
    m_potential_use_cursor(nullptr),
    m_potential_pos_x(nullptr),
    m_potential_pos_y(nullptr),
    m_potential_val(nullptr),
    m_camera_change(nullptr)
{
    QVBoxLayout* main = new QVBoxLayout(this);
    main->setMargin(5);

    QWidget* size_controller = new QWidget();
    size_controller->setFixedSize(300, 50);
    main->addWidget(size_controller);
    QHBoxLayout* size_controller_layout = new QHBoxLayout();
    size_controller->setLayout(size_controller_layout);
    QMenuBar* bar = new QMenuBar();
    size_controller_layout->addWidget(bar);

    QMenu* file_menu = bar->addMenu("File");

    file_menu->addAction("Open");
    file_menu->addAction("Save");
    file_menu->addAction("Save as");
    file_menu->addSeparator();
    file_menu->addAction("Exit", this, &QWidget::close);

    QMenu* options_menu = bar->addMenu("Options");

    options_menu->addAction("Theme");
    options_menu->addAction("Language");

    QMenu* help_menu = bar->addMenu("Help");

    help_menu->addAction("How to");

    QMenu* credits_menu = bar->addMenu("Credits");

    credits_menu->addAction("TimeToStop");
    credits_menu->addAction("stxmrvge");
    credits_menu->addAction("slayer404");

    QHBoxLayout* widgets = new QHBoxLayout();
    widgets->setMargin(0);
    main->addLayout(widgets);

    // Engine
    EngineWidget* engine = new EngineWidget();
    connect(engine, SIGNAL(cursorMoved(const QPoint&)), this, SLOT(calculateTensionByMouse(const QPoint&)));
    connect(engine, SIGNAL(cursorMoved(const QPoint&)), this, SLOT(calculatePotentialByMouse(const QPoint&)));

    // Main UI Buttons
    QWidget* widget = new QWidget();

    widget->setMaximumSize(500, 600);

    widgets->addWidget(engine);
    widgets->addWidget(widget);

    // Layout
    QVBoxLayout* settings = new QVBoxLayout();
    widget->setLayout(settings);

    // Working with charges
    QGroupBox* charges_box = new QGroupBox("Charges");
    QVBoxLayout* charges_buttons = new QVBoxLayout();

    charges_box->setLayout(charges_buttons);
    settings->addWidget(charges_box);

    // Buttons to work with charges
    QPushButton* add_charge = new QPushButton("Add charge");
    QPushButton* ignore_charges = new QPushButton("Ignore charges");
    QPushButton* edit_charge = new QPushButton("Edit charge");
    QPushButton* rm_charge = new QPushButton("Remove charge");

    charges_buttons->addWidget(add_charge);
    charges_buttons->addWidget(ignore_charges);
    charges_buttons->addWidget(edit_charge);
    charges_buttons->addWidget(rm_charge);

    connect(add_charge, SIGNAL(clicked()), this, SLOT(addCharge()));
    connect(ignore_charges, SIGNAL(clicked()), this, SLOT(ignoreCharge()));
    connect(edit_charge, SIGNAL(clicked()), this, SLOT(editCharge()));
    connect(rm_charge, SIGNAL(clicked()), this, SLOT(rmCharge()));
    // End of working with charges

    // Tab: E Y A W
    QTabWidget* tab = new QTabWidget();
    settings->addWidget(tab);

    QWidget* tension = new QWidget();
    QWidget* potential = new QWidget();
    QWidget* work = new QWidget();
    QWidget* energy = new QWidget();

    tab->addTab(tension, "Tension");
    tab->addTab(potential, "Potential");
    tab->addTab(work, "Work");
    tab->addTab(energy, "Energy");

    // E: tension
    QHBoxLayout* tension_layout = new QHBoxLayout();
    tension->setLayout(tension_layout);

    // Postion of tension to calculate
    QVBoxLayout* tension_pos = new QVBoxLayout();
    tension_layout->addLayout(tension_pos);
    QCheckBox* tension_check = new QCheckBox("Use cursor position");
    tension_pos->addWidget(tension_check);
    connect(tension_check, SIGNAL(stateChanged(int)), this, SLOT(useCursorPosition(int)));

    QGroupBox* tension_pos_box = new QGroupBox("Position");
    QVBoxLayout* tension_position = new QVBoxLayout();
    tension_pos_box->setLayout(tension_position);
    tension_pos->addWidget(tension_pos_box);

    ValueEdit* tension_pos_x = new ValueEdit("X", "м");
    ValueEdit* tension_pos_y = new ValueEdit("Y", "м");
    tension_position->addWidget(tension_pos_x);
    tension_position->addWidget(tension_pos_y);
    connect(tension_pos_x, SIGNAL(valueChanged()), this, SLOT(calculateTension()));
    connect(tension_pos_y, SIGNAL(valueChanged()), this, SLOT(calculateTension()));
    // End of Working with position

    // Calculated Result of tension
    QGroupBox* tension_box = new QGroupBox("Tension");
    tension_layout->addWidget(tension_box);
    QVBoxLayout* tension_res_layout = new QVBoxLayout();
    tension_box->setLayout(tension_res_layout);

    ValueWriter* tension_val = new ValueWriter("E", "Н/м");
    ValueWriter* tension_x = new ValueWriter("Ex", "Н/м");
    ValueWriter* tension_y = new ValueWriter("Ey", "Н/м");
    tension_res_layout->addWidget(tension_val);
    tension_res_layout->addWidget(tension_x);
    tension_res_layout->addWidget(tension_y);
    // End of working with calculated tension
    // End of tension

    // Y: Potential
    QHBoxLayout* potential_layout = new QHBoxLayout();
    potential->setLayout(potential_layout);

    // Postion of Potential to calculate
    QVBoxLayout* potential_pos = new QVBoxLayout();
    potential_layout->addLayout(potential_pos);

    QCheckBox* potential_check = new QCheckBox("Use cursor position");
    potential_pos->addWidget(potential_check);
    connect(potential_check, SIGNAL(stateChanged(int)), this, SLOT(useCursorPosition(int)));

    QGroupBox* potential_pos_box = new QGroupBox("Position");
    potential_pos->addWidget(potential_pos_box);
    QVBoxLayout* potential_position = new QVBoxLayout();
    potential_pos_box->setLayout(potential_position);

    ValueEdit* potential_pos_x = new ValueEdit("X", "м");
    ValueEdit* potential_pos_y = new ValueEdit("Y", "м");
    potential_position->addWidget(potential_pos_x);
    potential_position->addWidget(potential_pos_y);
    connect(potential_pos_x, SIGNAL(valueChanged()), this, SLOT(calculatePotential()));
    connect(potential_pos_y, SIGNAL(valueChanged()), this, SLOT(calculatePotential()));
    // End of Working with position

    QVBoxLayout* potential_value = new QVBoxLayout();
    potential_layout->addLayout(potential_value);

    QSpacerItem* spacer6 = new QSpacerItem(0, 10);
    potential_value->addSpacerItem(spacer6);
    ValueWriter* potential_val = new ValueWriter("φ", "В");
    potential_value->addWidget(potential_val);
    QSpacerItem* spacer1 = new QSpacerItem(1, 40);
    potential_value->addSpacerItem(spacer1);
    // End of potential

    // Work
    QHBoxLayout* work_layout = new QHBoxLayout();
    work->setLayout(work_layout);

    QVBoxLayout* work_start_pos_layout = new QVBoxLayout();
    work_layout->addLayout(work_start_pos_layout);

    QCheckBox* work_check_start_pos = new QCheckBox("Use Cursor Position");
    work_start_pos_layout->addWidget(work_check_start_pos);

    QGroupBox* work_start_position = new QGroupBox("Start");
    work_start_pos_layout->addWidget(work_start_position);

    QVBoxLayout* work_start_position_layout = new QVBoxLayout();

    ValueEdit* work_start_pos_x = new ValueEdit("X", "м");
    work_start_position_layout->addWidget(work_start_pos_x);
    ValueEdit* work_start_pos_y = new ValueEdit("Y", "м");
    work_start_position_layout->addWidget(work_start_pos_y);

    work_start_position->setLayout(work_start_position_layout);


    QVBoxLayout* work_destination_pos_layout = new QVBoxLayout();
    work_layout->addLayout(work_destination_pos_layout);

    QCheckBox* work_check_destination_pos = new QCheckBox("Use Cursor Position");
    work_destination_pos_layout->addWidget(work_check_destination_pos);

    QGroupBox* work_destination_position = new QGroupBox("Destination");
    work_destination_pos_layout->addWidget(work_destination_position);

    QVBoxLayout* work_destination_position_layout = new QVBoxLayout();

    ValueEdit* work_destination_pos_x = new ValueEdit("X", "м");
    work_destination_position_layout->addWidget(work_destination_pos_x);
    ValueEdit* work_destination_pos_y = new ValueEdit("Y", "м");
    work_destination_position_layout->addWidget(work_destination_pos_y);

    work_destination_position->setLayout(work_destination_position_layout);

    QVBoxLayout* calculated =  new QVBoxLayout();

    QSpacerItem* spacer4 = new QSpacerItem(0, 10);
    calculated->addSpacerItem(spacer4);
    ValueEdit* work_charge = new ValueEdit("q", "Кл");
    calculated->addWidget(work_charge);
    ValueWriter* work_calculated = new ValueWriter("A", "Дж");
    calculated->addWidget(work_calculated);
    QSpacerItem* spacer5 = new QSpacerItem(0, 10);
    calculated->addSpacerItem(spacer5);

    work_layout->addLayout(calculated);
    // End of Work

    // Work
    QHBoxLayout* energy_layout = new QHBoxLayout();
    energy->setLayout(energy_layout);

    QVBoxLayout* energy_pos_layout = new QVBoxLayout();
    energy_layout->addLayout(energy_pos_layout);

    QCheckBox* energy_check_pos = new QCheckBox("Use Cursor Position");
    energy_pos_layout->addWidget(energy_check_pos);

    QGroupBox* energy_position = new QGroupBox("Start");
    energy_pos_layout->addWidget(energy_position);

    QVBoxLayout* energy_start_position_layout = new QVBoxLayout();

    ValueEdit* energy_start_pos_x = new ValueEdit("X", "м");
    energy_start_position_layout->addWidget(energy_start_pos_x);
    ValueEdit* energy_start_pos_y = new ValueEdit("Y", "м");
    energy_start_position_layout->addWidget(energy_start_pos_y);

    energy_position->setLayout(energy_start_position_layout);

    QVBoxLayout* energy_val_layout = new QVBoxLayout();

    QSpacerItem* spacer2 = new QSpacerItem(0, 23);
    energy_val_layout->addSpacerItem(spacer2);
    ValueWriter* energy_of_pos = new ValueWriter("W     ", "Дж");
    energy_val_layout->addWidget(energy_of_pos);
    ValueWriter* energy_of_system = new ValueWriter("W sys", "Дж");
    energy_val_layout->addWidget(energy_of_system);
    ValueWriter* kinetic_energy_of_system = new ValueWriter("Wk    ", "Дж");
    energy_val_layout->addWidget(kinetic_energy_of_system);
    QSpacerItem* spacer3 = new QSpacerItem(0, 20);
    energy_val_layout->addSpacerItem(spacer3);

    energy_layout->addLayout(energy_val_layout);
    // End of work

    // Player
    QHBoxLayout* player = new QHBoxLayout();

    QPushButton* play = new QPushButton("Play");
    QPushButton* stop = new QPushButton("Pause");
    QPushButton* speed_x_2 = new QPushButton("Speed x2");
    QPushButton* edit = new QPushButton("Edit");

    player->addWidget(play);
    player->addWidget(stop);
    player->addWidget(speed_x_2);
    player->addWidget(edit);

    connect(play, SIGNAL(clicked()), this, SLOT(play()));
    connect(stop, SIGNAL(clicked()), this, SLOT(stop()));
    connect(speed_x_2, SIGNAL(clicked()), this, SLOT(speed_x_2()));
    connect(edit, SIGNAL(clicked()), this, SLOT(edit()));

    settings->addLayout(player);
    // End of player

    QGroupBox* additional = new QGroupBox("Additional");
    settings->addWidget(additional);
    QVBoxLayout* additional_layout = new QVBoxLayout();
    additional->setLayout(additional_layout);

    QHBoxLayout* camera = new QHBoxLayout();
    additional_layout->addLayout(camera);

    QLabel* camera_at = new QLabel("Camera at:");
    QComboBox* camera_combo = new QComboBox();
    camera->addWidget(camera_at);
    camera->addWidget(camera_combo);

    camera_combo->addItem("Default");
    camera_combo->addItems(engine->chargeNames());

    connect(camera_combo, SIGNAL(currentIndexChanged(int)), this, SLOT(changeCamera(int)));

    QHBoxLayout* scene = new QHBoxLayout();
    additional_layout->addLayout(scene);

    QLabel* scene_at = new QLabel("Change scene:");
    QComboBox* scene_combo = new QComboBox();
    scene->addWidget(scene_at);
    scene->addWidget(scene_combo);

    QHBoxLayout* info = new QHBoxLayout();
    additional_layout->addLayout(info);

    QLabel* scale_label = new QLabel("Scale:");
    QSlider* scale_slider = new QSlider(Qt::Horizontal);
    info->addWidget(scale_label);
    info->addWidget(scale_slider);
    connect(scale_slider, SIGNAL(valueChanged(int)), this, SLOT(scaleChanged(int)));

    QCheckBox* show_grid = new QCheckBox("Show grid");
    QCheckBox* show_tension = new QCheckBox("Show electrostatic field");
    info->addWidget(show_grid);
    info->addWidget(show_tension);
    show_grid->setChecked(true);
    show_tension->setChecked(false);
    connect(show_grid, SIGNAL(stateChanged(int)), this, SLOT(showGrid(int)));
    connect(show_tension, SIGNAL(stateChanged(int)), this, SLOT(showElectrostaticField(int)));

    m_tool_bar = bar;
    m_engine = engine;
    m_tension_use_cursor = tension_check;
    m_tension_pos_x = tension_pos_x;
    m_tension_pos_y = tension_pos_y;
    m_tension_val = tension_val;
    m_tension_val_x = tension_x;
    m_tension_val_y = tension_y;
    m_potential_use_cursor = potential_check;
    m_potential_pos_x = potential_pos_x;
    m_potential_pos_y = potential_pos_y;
    m_potential_val = potential_val;
    m_camera_change = camera_combo;

    m_use_cursor = false;
}

Widget::~Widget()
{
}

void Widget::play()
{
    m_engine->setEngineState(EngineState::PLAY);
}

void Widget::stop()
{
    m_engine->setEngineState(EngineState::PAUSE);
}

void Widget::speed_x_2()
{
    m_engine->setEngineState(EngineState::SPEED_2);
}

void Widget::edit()
{
    m_engine->setEngineState(EngineState::EDIT);
}

void Widget::toolBarFile()
{

}

void Widget::toolBarOptions()
{

}

void Widget::toolBarHelp()
{

}

void Widget::toolBarCredits()
{

}

void Widget::addCharge()
{
    CreateCharge d(m_engine->chargeNames(), this);
    EngineState e = m_engine->engineState();
    m_engine->setEngineState(EngineState::PAUSE);

    if(d.exec() == QDialog::Accepted)
    {
        m_engine->addCharge(std::unique_ptr<Charge>(new Charge(d.name(), d.charge(), d.mass(), d.pos(), d.is_ignored(), d.is_movable(), m_engine)));
        m_camera_change->addItem(d.name());
    }

    m_engine->setEngineState(e);
}

void Widget::editCharge()
{
    if(m_engine->hasCharges())
    {
        EngineState e = m_engine->engineState();
        m_engine->setEngineState(EngineState::PAUSE);
        SelectCharge d(m_engine->chargeNames(), this);

        if(d.exec() == QDialog::Accepted)
        {
            QStringList names = m_engine->chargeNames();
            names.removeAt(d.getSelected());
            CreateCharge d1(names, this);

            d1.setName(m_engine->getCharge(d.getSelected())->name());
            d1.setPos(m_engine->getCharge(d.getSelected())->pos());
            d1.setMass(m_engine->getCharge(d.getSelected())->mass());
            d1.setCharge(m_engine->getCharge(d.getSelected())->charge());
            d1.setIgnored(m_engine->getCharge(d.getSelected())->is_ignored());
            d1.setMovable(m_engine->getCharge(d.getSelected())->is_movable());

            if(d1.exec() == QDialog::Accepted)
            {
                m_engine->rmCharge(d.getSelected());
                m_engine->addCharge(std::unique_ptr<Charge>(new Charge(d1.name(), d1.charge(), d1.mass(), d1.pos(), d1.is_ignored(), d1.is_movable(), m_engine)));
            }
        }

        m_engine->setEngineState(e);
    }
}

void Widget::ignoreCharge()
{
    if(m_engine->hasCharges())
    {
        EngineState e = m_engine->engineState();
        m_engine->setEngineState(EngineState::PAUSE);
        IgnoreCharge d(m_engine->chargeNames(), this);

        if(d.exec() == QDialog::Accepted)
        {

        }

        m_engine->setEngineState(e);
    }
}

void Widget::rmCharge()
{
    if(m_engine->hasCharges())
    {
        EngineState e = m_engine->engineState();
        m_engine->setEngineState(EngineState::PAUSE);
        SelectCharge d(m_engine->chargeNames(), this);

        if(d.exec() == QDialog::Accepted)
        {
            m_engine->rmCharge(d.getSelected());
            m_camera_change->removeItem(d.getSelected() + 1);
        }

        m_engine->setEngineState(e);
    }
}

void Widget::showGrid(int val)
{
    m_engine->setDrawGrid(val == Qt::Checked);
    m_engine->repaint();
}

void Widget::showElectrostaticField(int val)
{
   m_engine->setDrawField(val == Qt::Checked);
   m_engine->repaint();
}

void Widget::calculateTension()
{
    calculateTension(m_tension_pos_x->value(), m_tension_pos_y->value());
}

void Widget::calculateTension(float x, float y)
{
    Vector tension = m_engine->calculateTension(x, y);
    m_tension_val_x->setValue(tension.x());
    m_tension_val_y->setValue(tension.y());
}

void Widget::calculateTensionByMouse(const QPoint& point)
{
    if (m_use_cursor)
    {
        Vector cursor_pos(m_engine->toXOY(Vector(point.x(), point.y())));
        m_tension_pos_x->setValue(cursor_pos.x());
        m_tension_pos_y->setValue(cursor_pos.y());
        Vector tension(m_engine->calculateTension(cursor_pos.x(), cursor_pos.y()));
        m_tension_val_x->setValue(tension.x());
        m_tension_val_y->setValue(tension.y());
    }
}

void Widget::calculatePotential()
{
    calculatePotential(m_potential_pos_x->value(), m_potential_pos_y->value());
}

void Widget::calculatePotential(float x, float y)
{
    m_potential_val->setValue(m_engine->calculatePotential(x, y));
}

void Widget::calculatePotentialByMouse(const QPoint& point)
{
    if (m_use_cursor)
    {
        Vector cursor_pos(point.x(), point.y());
        m_potential_pos_x->setValue(m_engine->toXOY(cursor_pos).x());
        m_potential_pos_y->setValue(m_engine->toXOY(cursor_pos).y());
        m_potential_val->setValue(m_engine->calculatePotential(cursor_pos.x(), cursor_pos.y()));
    }
}

void Widget::scaleChanged(int)
{
}

void Widget::changeCamera(int indx)
{
    m_engine->setCamera(indx - 1);
}

void Widget::changeScene(int)
{
}

void Widget::useCursorPosition(int val)
{
    bool is_checked = (val == Qt::Checked);
    m_use_cursor = is_checked;

    if(m_tension_use_cursor->checkState() != val)
    {
        m_tension_use_cursor->setChecked(is_checked);
    }

    if(m_potential_use_cursor->checkState() != val)
    {
        m_potential_use_cursor->setChecked(is_checked);
    }

    m_tension_pos_x->setDisabled(is_checked);
    m_tension_pos_y->setDisabled(is_checked);
    m_potential_pos_x->setDisabled(is_checked);
    m_potential_pos_y->setDisabled(is_checked);
}

