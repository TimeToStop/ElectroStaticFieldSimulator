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
    m_potential_val(nullptr)
{
    QHBoxLayout* main = new QHBoxLayout(this);

    // Engine
    EngineWidget* engine = new EngineWidget();
    // Main UI Buttons
    QWidget* widget = new QWidget();

    widget->setMaximumSize(400, 550);

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

    ValueRepresent* potential_val = new ValueRepresent("Y", "В");
    potential_val->setReadOnly(true);
    QSpacerItem* spacer1 = new QSpacerItem(1, 100);
    potential_value->addWidget(potential_val);
    potential_value->addSpacerItem(spacer1);
    // End of potential

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
}

Widget::~Widget()
{
}

void Widget::addCharge()
{
    CreateCharge d(this);

    if(d.exec() == QDialog::Accepted)
    {
        m_engine->addCharge(std::unique_ptr<Charge>(new Charge(d.name(), d.charge(), d.mass(), d.pos(), m_engine)));
    }
}

void Widget::editCharge()
{
    if(m_engine->hasCharges())
    {
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

void Widget::changeCamera(int)
{
}

void Widget::changeScene(int)
{
}

void Widget::useCursorPosition(int val)
{
    if(m_tension_use_cursor->checkState() != val)
    {
        m_tension_use_cursor->setCheckState((val == Qt::Checked) ? Qt::Checked : Qt::Unchecked);
    }

    if(m_potential_use_cursor->checkState() != val)
    {
        m_potential_use_cursor->setCheckState((val == Qt::Checked) ? Qt::Checked : Qt::Unchecked);
    }

    m_tension_pos_x->setReadOnly(val == Qt::Checked);
    m_tension_pos_y->setReadOnly(val == Qt::Checked);
    m_potential_pos_x->setReadOnly(val == Qt::Checked);
    m_potential_pos_y->setReadOnly(val == Qt::Checked);
}
