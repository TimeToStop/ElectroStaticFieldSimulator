#include "widget.h"

#include "Engine/engine.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QPushButton>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout* main = new QVBoxLayout(this);

    Engine* engine = new Engine(400, 400);

    main->addWidget(engine);
}

Widget::~Widget()
{
}

