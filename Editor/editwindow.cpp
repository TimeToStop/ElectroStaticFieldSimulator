#include "editwindow.h"
#include "ui_editwindow.h"

#include "Interface/simulator.h"

EditWindow::EditWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);
}

EditWindow::~EditWindow()
{
    delete ui;
}

void EditWindow::simulate()
{
    Simulator s(this);
    s.exec();
}
