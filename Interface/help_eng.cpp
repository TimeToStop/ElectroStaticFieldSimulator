#include "help_eng.h"
#include "ui_help_eng.h"

Help_eng::Help_eng(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Help_eng)
{
    ui->setupUi(this);
}

Help_eng::~Help_eng()
{
    delete ui;
}
