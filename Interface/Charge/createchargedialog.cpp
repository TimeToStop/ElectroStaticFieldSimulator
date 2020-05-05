#include "createchargedialog.h"
#include "ui_createchargedialog.h"

CreateChargeDialog::CreateChargeDialog(const QStringList&, QWidget *parent) :
    QDialog(parent),
    m_pos_x("X ", "м"),
    m_pos_y("Y ", "м"),
    m_vel_x("Vx", "м/c"),
    m_vel_y("Vy", "м/c"),
    m_mass("m", "кг"),
    m_charge("q", "Кл"),
    ui(new Ui::CreateChargeDialog)
{
    ui->setupUi(this);
    m_pos_x.setWidgets(ui->m_pos_x_label, ui->m_pos_x_edit, ui->m_pos_x_box);
    m_pos_y.setWidgets(ui->m_pos_y_label, ui->m_pos_y_edit, ui->m_pos_y_box);
    m_vel_x.setWidgets(ui->m_vel_x_label, ui->m_vel_x_edit, ui->m_vel_x_box);
    m_vel_y.setWidgets(ui->m_vel_y_label, ui->m_vel_y_edit, ui->m_vel_y_box);
    m_mass.setWidgets(ui->m_mass_label, ui->m_mass_edit, ui->m_mass_box);
    m_charge.setWidgets(ui->m_charge_label, ui->m_charge_edit, ui->m_charge_box);

    ui->m_err->setText("");
    ui->m_name_label->setText("Name:");
    ui->m_pos_label->setText("Position:");
    ui->m_vel_label->setText("Velocity:");
    ui->m_is_ignored->setText("Is Ignored");
    ui->m_is_movable->setText("Is Movable");

    ui->m_is_movable->setChecked(true);
}

CreateChargeDialog::~CreateChargeDialog()
{
    delete ui;
}

QString CreateChargeDialog::name() const
{
    return ui->m_name_edit->text();
}

Vector CreateChargeDialog::pos() const
{
    return Vector(m_pos_x.value(), m_pos_y.value());
}

Vector CreateChargeDialog::vel() const
{
    return Vector(m_vel_x.value(), m_vel_y.value());
}

float CreateChargeDialog::mass() const
{
    return m_mass.value();
}

float CreateChargeDialog::charge() const
{
    return m_charge.value();
}

bool CreateChargeDialog::is_ignored() const
{
    return ui->m_is_ignored->isChecked();
}

bool CreateChargeDialog::is_movable() const
{
    return ui->m_is_movable->isChecked();
}

void CreateChargeDialog::setName(const QString& name)
{
    ui->m_name_edit->setText(name);
}

void CreateChargeDialog::setPos(const Vector& pos)
{
    m_pos_x.setValue(pos.x());
    m_pos_y.setValue(pos.y());
}

void CreateChargeDialog::setVel(const Vector& vel)
{
    m_vel_x.setValue(vel.x());
    m_vel_y.setValue(vel.y());
}

void CreateChargeDialog::setMass(float m)
{
    m_mass.setValue(m);
}

void CreateChargeDialog::setCharge(float q)
{
    m_charge.setValue(q);
}

void CreateChargeDialog::setIgnored(bool ignore)
{
    ui->m_is_ignored->setChecked(ignore);
}

void CreateChargeDialog::setMovable(bool movable)
{
    ui->m_is_movable->setChecked(movable);
}
