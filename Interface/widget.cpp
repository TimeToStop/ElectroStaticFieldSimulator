#include "widget.h"

#include <Engine/engine.h>

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
//    QVBoxLayout* settings = new QVBoxLayout();

//    QGroupBox* charges = new QGroupBox();

//    QPushButton* add_charge = new QPushButton();
//    QPushButton* ignore_cherge = new QPushButton();

    main->addWidget(engine);
//    main->addLayout(settings);
}

Widget::~Widget()
{

}
