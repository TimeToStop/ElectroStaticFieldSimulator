#include "valuewriter.h"

ValueWriter::ValueWriter(const QString& name, const QString& measure, QWidget *parent):
    ValueRepresenter(name, measure, parent),
    m_label(new QLabel())
{
    m_layout->insertWidget(1, m_label);
    setValue(0.f);
}

ValueWriter::~ValueWriter()
{
}

void ValueWriter::setValue(float val)
{
    m_label->setNum(val);
}

void ValueWriter::setDisabled(bool)
{
}

float ValueWriter::value() const
{
    return m_label->text().toDouble() * power(m_curr_index);
}
