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

    QVBoxLayout* settings = new QVBoxLayout();

    // Working with charges
    QGroupBox* charges_box = new QGroupBox("Charges");
    QVBoxLayout* charges_buttons = new QVBoxLayout();

    QPushButton* add_charge = new QPushButton("Add charge");
    QPushButton* ignore_charges = new QPushButton("Ignore charges");
    QPushButton* edit_charge = new QPushButton("Edit charge");
    QPushButton* rm_charge = new QPushButton("Remove charge");

    charges_buttons->addWidget(add_charge);
    charges_buttons->addWidget(ignore_charges);
    charges_buttons->addWidget(edit_charge);
    charges_buttons->addWidget(rm_charge);

    charges_box->setLayout(charges_buttons);
    settings->addWidget(charges_box);
    // End of working with charges

    // Tab: E Y A W
    QTabWidget* tab = new QTabWidget();

    // E: tension
    QWidget* tension = new QWidget();

    QHBoxLayout* tension_layout = new QHBoxLayout();

    // Postion of tension to calculate
    QVBoxLayout* tension_pos = new QVBoxLayout();
    QCheckBox* tension_check = new QCheckBox("Use cursor position");

    tension_pos->addWidget(tension_check);

    QGroupBox* tension_pos_box = new QGroupBox("Position");
    QVBoxLayout* tension_position = new QVBoxLayout();

    ValueRepresent* tension_pos_x = new ValueRepresent("X", "м");
    ValueRepresent* tension_pos_y = new ValueRepresent("Y", "м");

    tension_position->addWidget(tension_pos_x);
    tension_position->addWidget(tension_pos_y);

    tension_pos_box->setLayout(tension_position);
    tension_pos->addWidget(tension_pos_box);
    // End of Working with position

    // Calculated Result of tension
    QGroupBox* tension_box = new QGroupBox("Tension");
    QVBoxLayout* tension_res_layout = new QVBoxLayout();

    ValueRepresent* tension_val = new ValueRepresent("E", "Н/м");
    ValueRepresent* tension_x = new ValueRepresent("Ex", "Н/м");
    ValueRepresent* tension_y = new ValueRepresent("Ey", "Н/м");

    tension_res_layout->addWidget(tension_val);
    tension_res_layout->addWidget(tension_x);
    tension_res_layout->addWidget(tension_y);

    tension_box->setLayout(tension_res_layout);

    tension_layout->addLayout(tension_pos);
    tension_layout->addWidget(tension_box);
    tension->setLayout(tension_layout);
    // End of working with calculated tension
    tab->addTab(tension, "Tension");
    // End of tension

    // Y: Potential
    QWidget* potential = new QWidget();

    QHBoxLayout* potential_layout = new QHBoxLayout();

    // Postion of Potential to calculate
    QVBoxLayout* potential_pos = new QVBoxLayout();
    QCheckBox* potential_check = new QCheckBox("Use cursor position");

    potential_pos->addWidget(potential_check);

    QGroupBox* potential_pos_box = new QGroupBox("Position");
    QVBoxLayout* potential_position = new QVBoxLayout();

    ValueRepresent* potential_pos_x = new ValueRepresent("X", "м");
    ValueRepresent* potential_pos_y = new ValueRepresent("Y", "м");

    potential_position->addWidget(potential_pos_x);
    potential_position->addWidget(potential_pos_y);

    potential_pos_box->setLayout(potential_position);
    potential_pos->addWidget(potential_pos_box);
    potential_layout->addLayout(potential_pos);
    // End of Working with position

    QVBoxLayout* potential_value = new QVBoxLayout();

    ValueRepresent* potential_val = new ValueRepresent("Y", "В");
    QSpacerItem* spacer1 = new QSpacerItem(1, 100);
    potential_value->addWidget(potential_val);
    potential_value->addSpacerItem(spacer1);

    potential_layout->addLayout(potential_value);
    potential->setLayout(potential_layout);

    tab->addTab(potential, "Potential");
    // End of potential

    settings->addWidget(tab);
    // End tab

    QGroupBox* additional = new QGroupBox("Additional");
    QVBoxLayout* additional_layout = new QVBoxLayout();

    QHBoxLayout* camera = new QHBoxLayout();

    QLabel* camera_at = new QLabel("Camera at:");
    QComboBox* camera_combo = new QComboBox();

    camera->addWidget(camera_at);
    camera->addWidget(camera_combo);
    additional_layout->addLayout(camera);

    QHBoxLayout* scene = new QHBoxLayout();

    QLabel* scene_at = new QLabel("Change scene:");
    QComboBox* scene_combo = new QComboBox();

    camera->addWidget(scene_at);
    camera->addWidget(scene_combo);
    additional_layout->addLayout(scene);

    QHBoxLayout* info = new QHBoxLayout();

    QLabel* scale_label = new QLabel("Scale:");
    QSlider* scale_slider = new QSlider(Qt::Horizontal);

    QCheckBox* show_grid = new QCheckBox("Show grid");
    QCheckBox* show_tension = new QCheckBox("Show tension lines");

    info->addWidget(scale_label);
    info->addWidget(scale_slider);
    info->addWidget(show_grid);
    info->addWidget(show_tension);
    additional_layout->addLayout(info);

    additional->setLayout(additional_layout);
    settings->addWidget(additional);

    widget->setLayout(settings);
    widget->setMaximumSize(400, 525);
    main->addWidget(engine);
    main->addWidget(widget);
}

Widget::~Widget()
{
}
