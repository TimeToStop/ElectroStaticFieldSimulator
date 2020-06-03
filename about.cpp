#include "about.h"
#include "ui_about.h"
#include "Options/translator.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);

    m_id = Translator::addContainer();

    Translator::registerWidget<QWidget, Words::CREDITS>(m_id, this, &QWidget::setWindowTitle);
    Translator::registerWidget<QLabel, Words::DEVS>(m_id, ui->m_devs_label, &QLabel::setText);
    Translator::registerWidget<QLabel, Words::RIGHTS>(m_id, ui->m_rights_label, &QLabel::setText);

    Translator::setLanguage();
}

About::~About()
{
    Translator::rmContainer(m_id);
    delete ui;
}
