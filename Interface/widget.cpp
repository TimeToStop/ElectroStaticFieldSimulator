#include "widget.h"

#include "Interface/Charge/createcharge.h"
#include "Interface/Charge/ignorecharge.h"
#include "Interface/Charge/selectcharge.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QMenuBar>
#include <QTabWidget>

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QComboBox>
#include <QSlider>

Widget::Widget(QWidget *parent):
    QWidget(parent),
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
    QHBoxLayout* main = new QHBoxLayout(this);

    // Engine
    EngineWidget* engine = new EngineWidget();
    // Main UI Buttons
    QWidget* widget = new QWidget();

    widget->setMaximumSize(500, 600);

    main->addWidget(engine);
    main->addWidget(widget);

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

    ValueRepresent* tension_pos_x = new ValueRepresent("X", "м");
    ValueRepresent* tension_pos_y = new ValueRepresent("Y", "м");
    tension_position->addWidget(tension_pos_x);
    tension_position->addWidget(tension_pos_y);
    // End of Working with position

    // Calculated Result of tension
    QGroupBox* tension_box = new QGroupBox("Tension");
    tension_layout->addWidget(tension_box);
    QVBoxLayout* tension_res_layout = new QVBoxLayout();
    tension_box->setLayout(tension_res_layout);

    ValueRepresent* tension_val = new ValueRepresent("E", "Н/м");
    ValueRepresent* tension_x = new ValueRepresent("Ex", "Н/м", 50);
    ValueRepresent* tension_y = new ValueRepresent("Ey", "Н/м", 50);
    tension_val->setReadOnly(true);
    tension_x->setReadOnly(true);
    tension_y->setReadOnly(true);
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

    ValueRepresent* potential_pos_x = new ValueRepresent("X", "м");
    ValueRepresent* potential_pos_y = new ValueRepresent("Y", "м");
    potential_position->addWidget(potential_pos_x);
    potential_position->addWidget(potential_pos_y);
    // End of Working with position

    QVBoxLayout* potential_value = new QVBoxLayout();
    potential_layout->addLayout(potential_value);

    QSpacerItem* spacer6 = new QSpacerItem(0, 10);
    potential_value->addSpacerItem(spacer6);
    ValueRepresent* potential_val = new ValueRepresent("Y", "В");
    potential_val->setReadOnly(true);
    potential_value->addWidget(potential_val);
    QSpacerItem* spacer1 = new QSpacerItem(1, 100);
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

    ValueRepresent* work_start_pos_x = new ValueRepresent("X", "м");
    work_start_position_layout->addWidget(work_start_pos_x);
    ValueRepresent* work_start_pos_y = new ValueRepresent("Y", "м");
    work_start_position_layout->addWidget(work_start_pos_y);

    work_start_position->setLayout(work_start_position_layout);


    QVBoxLayout* work_destination_pos_layout = new QVBoxLayout();
    work_layout->addLayout(work_destination_pos_layout);

    QCheckBox* work_check_destination_pos = new QCheckBox("Use Cursor Position");
    work_destination_pos_layout->addWidget(work_check_destination_pos);

    QGroupBox* work_destination_position = new QGroupBox("Destination");
    work_destination_pos_layout->addWidget(work_destination_position);

    QVBoxLayout* work_destination_position_layout = new QVBoxLayout();

    ValueRepresent* work_destination_pos_x = new ValueRepresent("X", "м");
    work_destination_position_layout->addWidget(work_destination_pos_x);
    ValueRepresent* work_destination_pos_y = new ValueRepresent("Y", "м");
    work_destination_position_layout->addWidget(work_destination_pos_y);

    work_destination_position->setLayout(work_destination_position_layout);

    QVBoxLayout* calculated =  new QVBoxLayout();

    QSpacerItem* spacer4 = new QSpacerItem(0, 10);
    calculated->addSpacerItem(spacer4);
    ValueRepresent* work_charge = new ValueRepresent("q", "Кл");
    calculated->addWidget(work_charge);
    ValueRepresent* work_calculated = new ValueRepresent("A", "Дж");
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

    ValueRepresent* energy_start_pos_x = new ValueRepresent("X", "м");
    energy_start_position_layout->addWidget(energy_start_pos_x);
    ValueRepresent* energy_start_pos_y = new ValueRepresent("Y", "м");
    energy_start_position_layout->addWidget(energy_start_pos_y);

    energy_position->setLayout(energy_start_position_layout);

    QVBoxLayout* energy_val_layout = new QVBoxLayout();

    QSpacerItem* spacer2 = new QSpacerItem(0, 23);
    energy_val_layout->addSpacerItem(spacer2);
    ValueRepresent* energy_of_pos = new ValueRepresent("W", "Дж");
    energy_val_layout->addWidget(energy_of_pos);
    ValueRepresent* energy_of_system = new ValueRepresent("W sys", "Дж");
    energy_val_layout->addWidget(energy_of_system);
    ValueRepresent* kinetic_energy_of_system = new ValueRepresent("Ek", "Дж");
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
    QCheckBox* show_tension = new QCheckBox("Show tension lines");
    info->addWidget(show_grid);
    info->addWidget(show_tension);
    show_grid->setChecked(true);
    show_tension->setChecked(false);
    connect(show_grid, SIGNAL(stateChanged(int)), this, SLOT(showGrid(int)));
    connect(show_tension, SIGNAL(stateChanged(int)), this, SLOT(showTension(int)));

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

void Widget::addCharge()
{
    CreateCharge d(this);

    if(d.exec() == QDialog::Accepted)
    {
        m_engine->addCharge(std::unique_ptr<Charge>(new Charge(d.name(), d.charge(), d.mass(), d.pos(), m_engine)));
        m_camera_change->addItem(d.name());
    }
}

void Widget::editCharge()
{
    if(m_engine->hasCharges())
    {
        m_engine->setEngineState(EngineState::PAUSE);
        SelectCharge d(m_engine->chargeNames(), this);

        if(d.exec() == QDialog::Accepted)
        {
            CreateCharge d1(this);

            d1.setName(m_engine->getCharge(d.getSelected())->name());
            d1.setPos(m_engine->getCharge(d.getSelected())->pos());
            d1.setMass(m_engine->getCharge(d.getSelected())->mass());
            d1.setCharge(m_engine->getCharge(d.getSelected())->charge());

            if(d1.exec() == QDialog::Accepted)
            {
                m_engine->rmCharge(d.getSelected());
                m_engine->addCharge(std::unique_ptr<Charge>(new Charge(d1.name(), d1.charge(), d1.mass(), d1.pos(), m_engine)));
            }
        }
        m_engine->setEngineState(EngineState::PLAY);
    }
}

void Widget::ignoreCharge()
{

}

void Widget::rmCharge()
{
    if(m_engine->hasCharges())
    {
        SelectCharge d(m_engine->chargeNames(), this);

        if(d.exec() == QDialog::Accepted)
        {
            m_engine->rmCharge(d.getSelected());
            m_camera_change->removeItem(d.getSelected() + 1);
        }
    }
}

void Widget::showGrid(int val)
{
    m_engine->setDrawGrid(val == Qt::Checked);
    m_engine->repaint();
}

void Widget::showTension(int)
{
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

    if(m_tension_use_cursor->checkState() != val)
    {
        m_tension_use_cursor->setChecked(is_checked);
    }

    if(m_potential_use_cursor->checkState() != val)
    {
        m_potential_use_cursor->setChecked(is_checked);
    }

    m_tension_pos_x->setReadOnly(is_checked);
    m_tension_pos_y->setReadOnly(is_checked);
    m_potential_pos_x->setReadOnly(is_checked);
    m_potential_pos_y->setReadOnly(is_checked);
}
