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
    m_box(nullptr),
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
    connect(box, SIGNAL(currentIndexChanged(int)), this, SLOT(prefixChanged(int)));

    m_layout = layout;
    m_box = box;
}

ValueRepresenter::~ValueRepresenter()
{
}

void ValueRepresenter::setValue(float val)
{
    int indx = 4;

    if(val > 0.0000000000000001f)
    {
        if(abs(val) < 1.f)
        {
            do
            {
                val *= 1000;
                indx -= 1;
            } while(abs(val) < 1.f && indx != 0);
        }
        else
        {
            while(abs(val) > 1000.f && indx != m_prefix.size())
            {
                val /= 1000;
                indx += 1;
            }
        }
    }

    m_box->setCurrentIndex(indx);
    setValueOnly(val);
}

float ValueRepresenter::value() const
{
    return valueOnly() * power(m_curr_index);
}

void ValueRepresenter::newValueEdited()
{
    emit(valueChanged());
    emit(valueEdited(value()));
}

void ValueRepresenter::prefixChanged(int indx)
{
    setValueOnly(value()/power(indx));
    m_curr_index = indx;
}

float ValueRepresenter::power(int indx)
{
    return pow(10, -12 + indx * 3);
}
