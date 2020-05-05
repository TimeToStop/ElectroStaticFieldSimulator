#ifndef VALUEEDIT_H
#define VALUEEDIT_H

#include "Interface/ValueRepresenter/valuerepresenter.h"

#include <QLineEdit>
#include <QValidator>

class ValueEdit: public ValueRepresenter
{
    Q_OBJECT

    QLineEdit* m_edit;

public:
    explicit ValueEdit(const QString&, const QString&, QWidget* parent = nullptr);
    virtual ~ValueEdit();

    virtual void setValueOnly(float) override;
    virtual float valueOnly() const override;
    virtual void setFixedEditWidth(int) override;
    virtual void setDisabled(bool) override;

    void setWidgets(QLabel*, QLineEdit*, QComboBox*);

public slots:
    void textChanged(const QString&);
    virtual void prefixChanged(int) override;

};

#endif // VALUEEDIT_H
