#ifndef CREATECHARGE_H
#define CREATECHARGE_H

#include "Engine/charge.h"
#include "Interface/ValueRepresener/valueedit.h"

#include <QDialog>
#include <QCheckBox>

class CreateCharge : public QDialog
{
    Q_OBJECT

    QStringList m_reserved_names;

    QLineEdit* m_name;
    ValueEdit* m_pos_x;
    ValueEdit* m_pos_y;
    ValueEdit* m_mass;
    ValueEdit* m_charge;
    QCheckBox* m_is_ignored;
    QCheckBox* m_is_movable;

public:
    explicit CreateCharge(const QStringList&, QWidget *parent = nullptr);
    virtual ~CreateCharge();

    QString name() const;
    Vector pos() const;
    float mass() const;
    float charge() const;
    bool is_ignored() const;
    bool is_movable() const;

    void setName(const QString&);
    void setPos(const Vector&);
    void setMass(float);
    void setCharge(float);
    void setIgnored(bool);
    void setMovable(bool);

signals:
public slots:
    void checkForCorrect();

};

#endif // CREATECHARGE_H
