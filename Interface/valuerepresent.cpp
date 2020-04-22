#include "valuerepresent.h"

#include <QHBoxLayout>
#include <QDoubleValidator>
#include <QLabel>

ValueRepresent::ValueRepresent(const QString& name, const QString& measure, double val, QWidget *parent):
    QWidget(parent),
    m_edit(nullptr),
    m_measure_label(nullptr),
    m_name(name),
    m_measure(measure)
{
    QHBoxLayout* layout = new QHBoxLayout(this);

    QLabel* label = new QLabel(name + " = ");
    QLineEdit* edit = new QLineEdit();
    edit->setValidator(new QDoubleValidator());
    QLabel* measure_label = new QLabel(measure);

    layout->addWidget(label);
    layout->addWidget(edit);
    layout->addWidget(measure_label);

    m_edit = edit;
    m_measure_label = measure_label;
    setValue(val);
}

ValueRepresent::~ValueRepresent()
{
}

void ValueRepresent::setReadOnly(bool b)
{
    m_edit->setReadOnly(b);
}

void ValueRepresent::setDefaultMeasure(bool)
{
}

void ValueRepresent::setValue(double d)
{
     m_edit->setText(QString::number(d));
}

void ValueRepresent::editNewValue()
{
    emit(valueEdited(m_edit->text().toDouble()));
}
