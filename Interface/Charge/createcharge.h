#ifndef CREATECHARGE_H
#define CREATECHARGE_H

#include "Engine/charge.h"
#include "Interface/ValueRepresener/valueedit.h"

#include <QDialog>

class CreateCharge : public QDialog
{
    Q_OBJECT

    QLineEdit* m_name;
    ValueEdit* m_pos_x;
    ValueEdit* m_pos_y;
    ValueEdit* m_mass;
    ValueEdit* m_charge;

public:
    explicit CreateCharge(QWidget *parent = nullptr);
    virtual ~CreateCharge();

    QString name() const;
    Vector pos() const;
    float mass() const;
    float charge() const;

    void setName(const QString&);
    void setPos(const Vector&);
    void setMass(float);
    void setCharge(float);

signals:

};

#endif // CREATECHARGE_H
