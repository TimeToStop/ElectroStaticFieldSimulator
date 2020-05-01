#include "valueedit.h"

ValueEdit::ValueEdit(const QString& name, const QString& measure, int left_diff,  QWidget* parent):
    ValueRepresenter(name, measure,left_diff, parent),
    m_edit(new QLineEdit())
{
    m_edit->setValidator(new QDoubleValidator());
    m_layout->insertWidget(2, m_edit);
    setValue(0.f);
    connect(m_edit, SIGNAL(textChanged(const QString&)), this, SLOT(textChanged(const QString&)));
}

ValueEdit::~ValueEdit()
{
}

void ValueEdit::setValueOnly(float val)
{
    m_edit->setText(QString::number(val));
}

void ValueEdit::setDisabled(bool b)
{
    m_edit->setDisabled(b);
}

float ValueEdit::valueOnly() const
{
    return m_edit->text().toDouble();
}

void ValueEdit::setFixedEditWidth(int w)
{
    m_edit->setFixedWidth(w);
}

void ValueEdit::textChanged(const QString&)
{
    newValueEdited();
}

void ValueEdit::prefixChanged(int indx)
{
    m_curr_index = indx;
}
