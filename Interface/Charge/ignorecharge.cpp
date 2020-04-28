#include "ignorecharge.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QScrollArea>
#include <QLabel>

IgnoreCharge::IgnoreCharge(const QStringList& names, QWidget *parent):
    QDialog(parent)
{
    QVBoxLayout* main = new QVBoxLayout(this);

    QScrollArea* area = new QScrollArea();
    main->addWidget(area);
    QWidget* widget = new QWidget();
    area->setWidget(widget);
    QVBoxLayout* layout = new QVBoxLayout();
    widget->setLayout(layout);
    widget->show();

    for(const QString& name : names)
    {
        QCheckBox* box = new QCheckBox(name);
        layout->addWidget(box);
    }
}

IgnoreCharge::~IgnoreCharge()
{
}

std::vector<size_t> IgnoreCharge::indexToIgnore() const
{
    return std::vector<size_t>();
}
