#ifndef CREATECHARGEDIALOG_H
#define CREATECHARGEDIALOG_H

#include <Engine/vector.h>
#include "Interface/ValueRepresenter/valueedit.h"
#include <QDialog>

namespace Ui {
class CreateChargeDialog;
}

class CreateChargeDialog : public QDialog
{
    Q_OBJECT

    ValueEdit m_pos_x;
    ValueEdit m_pos_y;

    ValueEdit m_vel_x;
    ValueEdit m_vel_y;

    ValueEdit m_mass;
    ValueEdit m_charge;

public:
    explicit CreateChargeDialog(const QStringList&, QWidget *parent = nullptr);
    ~CreateChargeDialog();

    int m_id;

    QString name() const;
    Vector pos() const;
    Vector vel() const;
    float mass() const;
    float charge() const;
    bool is_ignored() const;
    bool is_movable() const;

    void setName(const QString&);
    void setPos(const Vector&);
    void setVel(const Vector&);
    void setMass(float);
    void setCharge(float);
    void setIgnored(bool);
    void setMovable(bool);

private:
    Ui::CreateChargeDialog *ui;
};

#endif // CREATECHARGEDIALOG_H
