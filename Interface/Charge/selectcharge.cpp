#include "selectcharge.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

SelectCharge::SelectCharge(const QStringList& names, QWidget *parent):
    QDialog(parent),
    m_box(nullptr)
{
    QVBoxLayout* main = new QVBoxLayout(this);

    QHBoxLayout* selecting = new QHBoxLayout();
    QHBoxLayout* buttons = new QHBoxLayout();

    main->addLayout(selecting);
    main->addLayout(buttons);

    QLabel* label = new QLabel("Select:");
    QComboBox* box = new QComboBox();

    selecting->addWidget(label);
    selecting->addWidget(box);

    QSpacerItem* spacer = new QSpacerItem(50, 0);
    QPushButton* accept = new QPushButton("Ok");
    QPushButton* exit = new QPushButton("Exit");

    buttons->addSpacerItem(spacer);
    buttons->addWidget(accept);
    buttons->addWidget(exit);

    connect(accept, SIGNAL(clicked()), this, SLOT(accept()));
    connect(exit, SIGNAL(clicked()), this, SLOT(reject()));

    m_box = box;
    m_box->addItems(names);
}

SelectCharge::~SelectCharge()
{
}

size_t SelectCharge::getSelected() const
{
    return m_box->currentIndex();
}
