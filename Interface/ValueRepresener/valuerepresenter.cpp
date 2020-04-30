#include "valuerepresenter.h"

#include <QLabel>
#include <QComboBox>
#include <cmath>
#include <QDebug>

const QStringList ValueRepresenter::m_prefix = QStringList()
        << "п" << "н" << "мк" << "м"
        << ""
        << "к" << "М" << "Г" << "Т";

ValueRepresenter::ValueRepresenter(const QString& name, const QString& measure, int left_diff, QWidget *parent):
    QWidget(parent),
    m_curr_index(4),
    m_layout(nullptr),
    m_measure(measure)
{
    QHBoxLayout* layout = new QHBoxLayout(this);

    QSpacerItem* spacer = new QSpacerItem(left_diff, 0);
    layout->addSpacerItem(spacer);
    QLabel* name_label = new QLabel(name + " = ");
    layout->addWidget(name_label);
    QComboBox* box = new QComboBox();
    layout->addWidget(box);

    for(const QString& prefix : m_prefix)
    {
        box->addItem(prefix + m_measure);
    }
    box->setCurrentIndex(m_curr_index);

    m_layout = layout;
    connect(box, SIGNAL(currentIndexChanged(int)), this, SLOT(prefixChanged(int)));
}

ValueRepresenter::~ValueRepresenter()
{
}

float ValueRepresenter::value() const
{
    return valueOnly() * power(m_curr_index);
}

void ValueRepresenter::prefixChanged(int indx)
{
    setValue(value()/power(indx));
    newValueEdited();
    m_curr_index = indx;
}

void ValueRepresenter::newValueEdited()
{
    emit(valueChanged());
    emit(valueEdited(value()));
}

float ValueRepresenter::power(int indx)
{
    return pow(10, -12 + indx * 3);
}
