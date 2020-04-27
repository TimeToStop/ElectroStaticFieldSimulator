#include "valuerepresenter.h"

#include <QLabel>
#include <QComboBox>
#include <cmath>

const QStringList m_prefix = QStringList()
        << "п" << "н" << "мк" << "м"
        << ""
        << "к" << "М" << "Г" << "Т";

ValueRepresenter::ValueRepresenter(const QString& name, const QString& measure, QWidget *parent):
    QWidget(parent),
    m_curr_index(4),
    m_layout(nullptr),
    m_measure(measure)
{
    QHBoxLayout* layout = new QHBoxLayout(this);

    QLabel* name_label = new QLabel(name + " = ");
    layout->addWidget(name_label);
    QComboBox* box = new QComboBox();
    layout->addWidget(box);
    connect(box, SIGNAL(currentIndexChanged(int)), this, SLOT(prefixChanged(int)));

    for(const QString& prefix : m_prefix)
    {
       box->addItem(prefix + m_measure);
    }

    m_layout = layout;
}

ValueRepresenter::~ValueRepresenter()
{
}

void ValueRepresenter::prefixChanged(int indx)
{
    setValue(value() * power(m_curr_index)/power(indx));
    newValueEdited();
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
