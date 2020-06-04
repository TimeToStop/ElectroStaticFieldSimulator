/********************************************************************************
** Form generated from reading UI file 'createchargedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECHARGEDIALOG_H
#define UI_CREATECHARGEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateChargeDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *m_name_label;
    QLineEdit *m_name_edit;
    QLabel *m_err;
    QGridLayout *gridLayout_3;
    QLabel *m_pos_label;
    QLabel *m_vel_label;
    QLabel *m_pos_y_label;
    QLabel *m_vel_y_label;
    QLineEdit *m_pos_x_edit;
    QComboBox *m_vel_y_box;
    QLineEdit *m_pos_y_edit;
    QLabel *m_pos_x_label;
    QLabel *m_vel_x_label;
    QComboBox *m_vel_x_box;
    QLineEdit *m_vel_x_edit;
    QComboBox *m_pos_x_box;
    QComboBox *m_pos_y_box;
    QLineEdit *m_vel_y_edit;
    QGridLayout *gridLayout_2;
    QComboBox *m_charge_box;
    QLabel *m_charge_label;
    QLineEdit *m_charge_edit;
    QLabel *m_mass_label;
    QComboBox *m_mass_box;
    QLineEdit *m_mass_edit;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *m_is_movable;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CreateChargeDialog)
    {
        if (CreateChargeDialog->objectName().isEmpty())
            CreateChargeDialog->setObjectName(QString::fromUtf8("CreateChargeDialog"));
        CreateChargeDialog->resize(545, 297);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/winicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        CreateChargeDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(CreateChargeDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        m_name_label = new QLabel(CreateChargeDialog);
        m_name_label->setObjectName(QString::fromUtf8("m_name_label"));

        horizontalLayout_2->addWidget(m_name_label);

        m_name_edit = new QLineEdit(CreateChargeDialog);
        m_name_edit->setObjectName(QString::fromUtf8("m_name_edit"));

        horizontalLayout_2->addWidget(m_name_edit);

        m_err = new QLabel(CreateChargeDialog);
        m_err->setObjectName(QString::fromUtf8("m_err"));

        horizontalLayout_2->addWidget(m_err);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        m_pos_label = new QLabel(CreateChargeDialog);
        m_pos_label->setObjectName(QString::fromUtf8("m_pos_label"));

        gridLayout_3->addWidget(m_pos_label, 0, 0, 1, 1);

        m_vel_label = new QLabel(CreateChargeDialog);
        m_vel_label->setObjectName(QString::fromUtf8("m_vel_label"));

        gridLayout_3->addWidget(m_vel_label, 2, 0, 1, 1);

        m_pos_y_label = new QLabel(CreateChargeDialog);
        m_pos_y_label->setObjectName(QString::fromUtf8("m_pos_y_label"));

        gridLayout_3->addWidget(m_pos_y_label, 1, 1, 1, 1);

        m_vel_y_label = new QLabel(CreateChargeDialog);
        m_vel_y_label->setObjectName(QString::fromUtf8("m_vel_y_label"));

        gridLayout_3->addWidget(m_vel_y_label, 3, 1, 1, 1);

        m_pos_x_edit = new QLineEdit(CreateChargeDialog);
        m_pos_x_edit->setObjectName(QString::fromUtf8("m_pos_x_edit"));

        gridLayout_3->addWidget(m_pos_x_edit, 0, 2, 1, 1);

        m_vel_y_box = new QComboBox(CreateChargeDialog);
        m_vel_y_box->setObjectName(QString::fromUtf8("m_vel_y_box"));

        gridLayout_3->addWidget(m_vel_y_box, 3, 3, 1, 1);

        m_pos_y_edit = new QLineEdit(CreateChargeDialog);
        m_pos_y_edit->setObjectName(QString::fromUtf8("m_pos_y_edit"));

        gridLayout_3->addWidget(m_pos_y_edit, 1, 2, 1, 1);

        m_pos_x_label = new QLabel(CreateChargeDialog);
        m_pos_x_label->setObjectName(QString::fromUtf8("m_pos_x_label"));

        gridLayout_3->addWidget(m_pos_x_label, 0, 1, 1, 1);

        m_vel_x_label = new QLabel(CreateChargeDialog);
        m_vel_x_label->setObjectName(QString::fromUtf8("m_vel_x_label"));

        gridLayout_3->addWidget(m_vel_x_label, 2, 1, 1, 1);

        m_vel_x_box = new QComboBox(CreateChargeDialog);
        m_vel_x_box->setObjectName(QString::fromUtf8("m_vel_x_box"));

        gridLayout_3->addWidget(m_vel_x_box, 2, 3, 1, 1);

        m_vel_x_edit = new QLineEdit(CreateChargeDialog);
        m_vel_x_edit->setObjectName(QString::fromUtf8("m_vel_x_edit"));

        gridLayout_3->addWidget(m_vel_x_edit, 2, 2, 1, 1);

        m_pos_x_box = new QComboBox(CreateChargeDialog);
        m_pos_x_box->setObjectName(QString::fromUtf8("m_pos_x_box"));

        gridLayout_3->addWidget(m_pos_x_box, 0, 3, 1, 1);

        m_pos_y_box = new QComboBox(CreateChargeDialog);
        m_pos_y_box->setObjectName(QString::fromUtf8("m_pos_y_box"));

        gridLayout_3->addWidget(m_pos_y_box, 1, 3, 1, 1);

        m_vel_y_edit = new QLineEdit(CreateChargeDialog);
        m_vel_y_edit->setObjectName(QString::fromUtf8("m_vel_y_edit"));

        gridLayout_3->addWidget(m_vel_y_edit, 3, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        m_charge_box = new QComboBox(CreateChargeDialog);
        m_charge_box->setObjectName(QString::fromUtf8("m_charge_box"));

        gridLayout_2->addWidget(m_charge_box, 1, 2, 1, 1);

        m_charge_label = new QLabel(CreateChargeDialog);
        m_charge_label->setObjectName(QString::fromUtf8("m_charge_label"));

        gridLayout_2->addWidget(m_charge_label, 1, 0, 1, 1);

        m_charge_edit = new QLineEdit(CreateChargeDialog);
        m_charge_edit->setObjectName(QString::fromUtf8("m_charge_edit"));

        gridLayout_2->addWidget(m_charge_edit, 1, 1, 1, 1);

        m_mass_label = new QLabel(CreateChargeDialog);
        m_mass_label->setObjectName(QString::fromUtf8("m_mass_label"));

        gridLayout_2->addWidget(m_mass_label, 0, 0, 1, 1);

        m_mass_box = new QComboBox(CreateChargeDialog);
        m_mass_box->setObjectName(QString::fromUtf8("m_mass_box"));

        gridLayout_2->addWidget(m_mass_box, 0, 2, 1, 1);

        m_mass_edit = new QLineEdit(CreateChargeDialog);
        m_mass_edit->setObjectName(QString::fromUtf8("m_mass_edit"));

        gridLayout_2->addWidget(m_mass_edit, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        m_is_movable = new QCheckBox(CreateChargeDialog);
        m_is_movable->setObjectName(QString::fromUtf8("m_is_movable"));

        horizontalLayout_7->addWidget(m_is_movable);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(CreateChargeDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_7->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_7);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(CreateChargeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateChargeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateChargeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateChargeDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateChargeDialog)
    {
        CreateChargeDialog->setWindowTitle(QCoreApplication::translate("CreateChargeDialog", "Charge Constructor", nullptr));
        m_name_label->setText(QCoreApplication::translate("CreateChargeDialog", "TextLabel", nullptr));
        m_err->setText(QCoreApplication::translate("CreateChargeDialog", "TextLabel", nullptr));
        m_pos_label->setText(QCoreApplication::translate("CreateChargeDialog", "TextLabel", nullptr));
        m_vel_label->setText(QCoreApplication::translate("CreateChargeDialog", "TextLabel", nullptr));
        m_pos_y_label->setText(QCoreApplication::translate("CreateChargeDialog", "TextLabel", nullptr));
        m_vel_y_label->setText(QCoreApplication::translate("CreateChargeDialog", "TextLabel", nullptr));
        m_pos_x_label->setText(QCoreApplication::translate("CreateChargeDialog", "TextLabel", nullptr));
        m_vel_x_label->setText(QCoreApplication::translate("CreateChargeDialog", "TextLabel", nullptr));
        m_charge_label->setText(QCoreApplication::translate("CreateChargeDialog", "TextLabel", nullptr));
        m_mass_label->setText(QCoreApplication::translate("CreateChargeDialog", "TextLabel", nullptr));
        m_is_movable->setText(QCoreApplication::translate("CreateChargeDialog", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateChargeDialog: public Ui_CreateChargeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECHARGEDIALOG_H
