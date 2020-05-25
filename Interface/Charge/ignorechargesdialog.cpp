#include "ignorechargesdialog.h"
#include "ui_ignorechargesdialog.h"
#include "Options/translator.h"

#include <QLabel>
#include <QCheckBox>

IgnoreChargesDialog::IgnoreChargesDialog(const QStringList& names, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IgnoreChargesDialog)
{
    ui->setupUi(this);

    for(const QString& name : names)
    {
        QHBoxLayout* layout = new QHBoxLayout();
        QLabel* label = new QLabel(name);
        QCheckBox* is_ignored = new QCheckBox("is ignored");
        QCheckBox* is_movable = new QCheckBox("is movable");
        layout->addWidget(label);
        layout->addWidget(is_ignored);
        layout->addWidget(is_movable);
        ui->main_layout->addLayout(layout);
    }

    //m_id = Translator::addContainer();

    //CheckBoxes
   // Translator::registerWidget<QCheckBox, Words::IS_IGNORE>(m_id, , &QCheckBox::setText);
    //Translator::registerWidget<QCheckBox, Words::IS_MOVABLE>(m_id, ui->m_is_movable, &QCheckBox::setText);

    //Translator::registerWidget<QCheckBox, Words::IS_IGNORE>(m_id, ui->m_, &QCheckBox::setText);

   // Translator::setLanguage();

}

IgnoreChargesDialog::~IgnoreChargesDialog()
{
    delete ui;
}
