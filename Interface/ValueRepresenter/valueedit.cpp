#include "valueedit.h"

ValueEdit::ValueEdit(const QString& name, const QString& measure, QWidget* parent):
    ValueRepresenter(name, measure, parent),
    m_edit(nullptr)
{
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

void ValueEdit::setWidgets(QLabel* label, QLineEdit* edit, QComboBox* box)
{
    ValueRepresenter::setWidgets(label, box);
    m_edit = edit;
    m_edit->setValidator(new QDoubleValidator());
    setValue(0.f);
    connect(m_edit, SIGNAL(textChanged(const QString&)), this, SLOT(textChanged(const QString&)));
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
