#include "valuewriter.h"

ValueWriter::ValueWriter(const QString& name, const QString& measure,QWidget *parent):
    ValueRepresenter(name, measure, parent),
    m_label(nullptr)
{
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

void ValueWriter::setWidgets(QLabel* label, QLabel* val, QComboBox* box)
{
    ValueRepresenter::setWidgets(label, box);
    m_label = val;
    m_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    setValue(0.f);
}

void ValueWriter::prefixChanged(int indx)
{
    setValueOnly(value()/power(indx));
    m_curr_index = indx;
}
