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

Widget::Widget(QWidget *parent):
    QWidget(parent)
{
    QHBoxLayout* main = new QHBoxLayout(this);

    Engine* engine = new Engine();
    QVBoxLayout* settings = new QVBoxLayout();

    QGroupBox* charges_box = new QGroupBox();
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

    QTabWidget* tab = new QTabWidget();

    QWidget* tension = new QWidget();

    QHBoxLayout* tension_layout = new QHBoxLayout();

    QVBoxLayout* tension_pos = new QVBoxLayout();
    QCheckBox* check = new QCheckBox("Use cursor position");

    tension_pos->addWidget(check);

    QGroupBox* pos_box = new QGroupBox("Position");
    QVBoxLayout* pos = new QVBoxLayout();

    ValueRepresent* pos_x = new ValueRepresent("X", "м");
    ValueRepresent* pos_y = new ValueRepresent("Y", "м");

    pos->addWidget(pos_x);
    pos->addWidget(pos_y);

    pos_box->setLayout(pos);
    tension_pos->addWidget(pos_box);

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
    tab->addTab(tension, "Tension");

    settings->addWidget(tab);

    main->addWidget(engine);
    main->addLayout(settings);
}

Widget::~Widget()
{

}
