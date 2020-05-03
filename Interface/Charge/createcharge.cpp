#include "createcharge.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

CreateCharge::CreateCharge(const QStringList& list, QWidget *parent):
    QDialog(parent),
    m_reserved_names(list),
    m_name(nullptr),
    m_pos_x(nullptr),
    m_pos_y(nullptr),
    m_mass(nullptr),
    m_charge(nullptr),
    m_is_ignored(nullptr),
    m_is_movable(nullptr)
{
    QVBoxLayout* main = new QVBoxLayout(this);

    QHBoxLayout* name = new QHBoxLayout();
    QHBoxLayout* pos = new QHBoxLayout();
    ValueEdit* mass = new ValueEdit(nullptr,nullptr,nullptr, "m", "kg");
    ValueEdit* charge = new ValueEdit(nullptr,nullptr,nullptr,"q", "kl");
    QHBoxLayout* checked = new QHBoxLayout();
    QHBoxLayout* buttons = new QHBoxLayout();

    main->addLayout(name);
    main->addLayout(pos);
    main->addWidget(mass);
    main->addWidget(charge);
    main->addLayout(checked);
    main->addLayout(buttons);

    // Name
    QLabel* name_label = new QLabel("Name:");
    QLineEdit* name_edit = new QLineEdit();
    name->addWidget(name_label);
    name->addWidget(name_edit);

    // Position
    QVBoxLayout* position_label_layout = new QVBoxLayout();
    pos->addLayout(position_label_layout);
    QLabel* position_label = new QLabel("Position:");
    QSpacerItem* spacer1 = new QSpacerItem(0, 50);
    position_label_layout->addWidget(position_label);
    position_label_layout->addSpacerItem(spacer1);

    QVBoxLayout* pos_layout = new QVBoxLayout();
    pos->addLayout(pos_layout);
    ValueEdit* position_x = new ValueEdit(nullptr,nullptr,nullptr,"X", "м");
    ValueEdit* position_y = new ValueEdit(nullptr,nullptr,nullptr,"Y", "м");
    pos_layout->addWidget(position_x);
    pos_layout->addWidget(position_y);

    // Buttons
    QSpacerItem* spacer2 = new QSpacerItem(50, 0);
    QPushButton* accept = new QPushButton("Ok");
    QPushButton* exit = new QPushButton("Exit");
    buttons->addSpacerItem(spacer2);
    buttons->addWidget(accept);
    buttons->addWidget(exit);

    connect(accept, SIGNAL(clicked()), this, SLOT(checkForCorrect()));
    connect(exit, SIGNAL(clicked()), this, SLOT(reject()));

    QSpacerItem* spacer3 = new QSpacerItem(120, 0);
    QCheckBox* ignore = new QCheckBox("is ignore");
    QCheckBox* movable = new QCheckBox("is movable");
    checked->addSpacerItem(spacer3);
    checked->addWidget(ignore);
    checked->addWidget(movable);
    ignore->setChecked(false);
    movable->setChecked(true);

    m_name = name_edit;
    m_pos_x = position_x;
    m_pos_y = position_y;
    m_mass = mass;
    m_charge = charge;
    m_is_ignored = ignore;
    m_is_movable = movable;
    setWindowTitle("Create charge");
}

CreateCharge::~CreateCharge()
{
}

QString CreateCharge::name() const
{
    return m_name->text();
}

Vector CreateCharge::pos() const
{
    return Vector(m_pos_x->value(), m_pos_y->value());
}

float CreateCharge::mass() const
{
    return m_mass->value();
}

float CreateCharge::charge() const
{
    return m_charge->value();
}

bool CreateCharge::is_ignored() const
{
    return m_is_ignored->isChecked();
}

bool CreateCharge::is_movable() const
{
    return m_is_movable->isChecked();
}

void CreateCharge::setName(const QString& name)
{
    m_name->setText(name);
}

void CreateCharge::setPos(const Vector& pos)
{
    m_pos_x->setValue(pos.x());
    m_pos_y->setValue(pos.y());
}

void CreateCharge::setMass(float mass)
{
    m_mass->setValue(mass);
}

void CreateCharge::setCharge(float charge)
{
    m_charge->setValue(charge);
}

void CreateCharge::setIgnored(bool b)
{
    m_is_ignored->setChecked(b);
}

void CreateCharge::setMovable(bool b)
{
    m_is_movable->setChecked(b);
}

void CreateCharge::checkForCorrect()
{
    for(const QString& reserve_name : m_reserved_names)
    {
        if(reserve_name == name())
        {
            return;
        }
    }

    accept();
}
