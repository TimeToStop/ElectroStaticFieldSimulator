#ifndef VALUEEDIT_H
#define VALUEEDIT_H

#include "Interface/ValueRepresener/valuerepresenter.h"

#include <QLineEdit>
#include <QValidator>

class ValueEdit: public ValueRepresenter
{
    Q_OBJECT

    QLineEdit* m_edit;

public:
    explicit ValueEdit(const QString&, const QString&, QWidget* parent = nullptr);
    virtual ~ValueEdit();

    virtual void setValue(float) override;
    virtual void setDisabled(bool) override;
    virtual float value() const override;
};

#endif // VALUEEDIT_H
