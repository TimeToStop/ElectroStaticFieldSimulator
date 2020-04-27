#include "valueedit.h"

ValueEdit::ValueEdit(const QString& name, const QString& measure, int left_diff,  QWidget* parent):
    ValueRepresenter(name, measure,left_diff, parent),
    m_edit(new QLineEdit())
{
    m_edit->setValidator(new QDoubleValidator());
    m_layout->insertWidget(2, m_edit);
    setValue(0.f);
    connect(m_edit, SIGNAL(editingFinished()), this, SLOT(newValueEdited()));
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

float ValueEdit::valueOnly() const
{
    return m_edit->text().toDouble();
}
