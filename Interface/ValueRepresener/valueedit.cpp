#include "valueedit.h"

ValueEdit::ValueEdit(const QString& name, const QString& measure, QWidget* parent):
    ValueRepresenter(name, measure, parent),
    m_edit(new QLineEdit())
{
    m_edit->setValidator(new QDoubleValidator());
    m_layout->insertWidget(1, m_edit);
    setValue(0.f);
}

ValueEdit::~ValueEdit()
{
}

void ValueEdit::setValue(float val)
{
    m_edit->setText(QString::number(val));
}

void ValueEdit::setDisabled(bool b)
{
    m_edit->setDisabled(b);
}

float ValueEdit::value() const
{
    return m_edit->text().toDouble() * power(m_curr_index);
}
