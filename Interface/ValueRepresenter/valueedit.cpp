#include "valueedit.h"

ValueEdit::ValueEdit(QLabel* header,QLineEdit* val, QComboBox* box,const QString& name, const QString& measure,  QWidget* parent):
    ValueRepresenter(header, box, name, measure, parent),
    m_edit(val)
{
    m_edit->setValidator(new QDoubleValidator());
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
