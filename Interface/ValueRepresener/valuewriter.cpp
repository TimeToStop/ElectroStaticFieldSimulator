#include "valuewriter.h"

ValueWriter::ValueWriter(const QString& name, const QString& measure, int left_diff, QWidget *parent):
    ValueRepresenter(name, measure,left_diff, parent),
    m_label(new QLabel())
{
    m_layout->insertWidget(2, m_label);
    m_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    setValue(0.f);
}

ValueWriter::~ValueWriter()
{
}

void ValueWriter::setValueOnly(float val)
{
    m_label->setNum(val);
}

float ValueWriter::valueOnly() const
{
    return m_label->text().toDouble();
}

void ValueWriter::setFixedEditWidth(int w)
{
    m_label->setFixedWidth(w);
}

void ValueWriter::setDisabled(bool)
{
}

void ValueWriter::prefixChanged(int indx)
{
    setValueOnly(value()/power(indx));
    m_curr_index = indx;
}
