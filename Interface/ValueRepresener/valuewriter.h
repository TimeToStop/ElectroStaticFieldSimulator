#ifndef VALUEWRITER_H
#define VALUEWRITER_H

#include "Interface/ValueRepresener/valuerepresenter.h"
#include <QLabel>

class ValueWriter : public ValueRepresenter
{
    Q_OBJECT

    QLabel* m_label;

public:
    explicit ValueWriter(const QString&, const QString&, int left_diff =0, QWidget* parent = nullptr);
    virtual ~ValueWriter();

    virtual void setValueOnly(float) override;
    virtual float valueOnly() const override;
    virtual void setFixedEditWidth(int) override;
    virtual void setDisabled(bool) override;

public slots:
    virtual void prefixChanged(int) override;

};

#endif // VALUEWRITER_H
