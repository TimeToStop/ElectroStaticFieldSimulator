#include "widget.h"

#include "Engine/engine.h"
#include "Interface/valuerepresent.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QMenuBar>
#include <QTabWidget>

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QGroupBox>
#include <QComboBox>
#include <QSlider>

Widget::Widget(QWidget *parent):
    QWidget(parent)
{
    QHBoxLayout* main = new QHBoxLayout(this);

    // Engine Widget
    Engine* engine = new Engine();
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
    ValueRepresent* tension_x = new ValueRepresent("Ex", "Н/м");
    ValueRepresent* tension_y = new ValueRepresent("Ey", "Н/м");
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

    QCheckBox* show_grid = new QCheckBox("Show grid");
    QCheckBox* show_tension = new QCheckBox("Show tension lines");
    info->addWidget(show_grid);
    info->addWidget(show_tension);
}

Widget::~Widget()
{
}
