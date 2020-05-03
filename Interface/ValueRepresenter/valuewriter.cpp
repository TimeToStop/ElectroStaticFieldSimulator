#include "valuewriter.h"

ValueWriter::ValueWriter(QLabel* header, QLabel* val, QComboBox* box,const QString& name, const QString& measure,QWidget *parent):
    ValueRepresenter(header, box, name, measure, parent),
    m_label(val)
{
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
