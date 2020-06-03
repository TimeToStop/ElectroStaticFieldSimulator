/********************************************************************************
** Form generated from reading UI file 'ignorechargesdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IGNORECHARGESDIALOG_H
#define UI_IGNORECHARGESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IgnoreChargesDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *main_layout;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *IgnoreChargesDialog)
    {
        if (IgnoreChargesDialog->objectName().isEmpty())
            IgnoreChargesDialog->setObjectName(QStringLiteral("IgnoreChargesDialog"));
        IgnoreChargesDialog->resize(801, 423);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/winicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        IgnoreChargesDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(IgnoreChargesDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        scrollArea = new QScrollArea(IgnoreChargesDialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 779, 372));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        main_layout = new QVBoxLayout();
        main_layout->setObjectName(QStringLiteral("main_layout"));

        verticalLayout_3->addLayout(main_layout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        buttonBox = new QDialogButtonBox(IgnoreChargesDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(IgnoreChargesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), IgnoreChargesDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), IgnoreChargesDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(IgnoreChargesDialog);
    } // setupUi

    void retranslateUi(QDialog *IgnoreChargesDialog)
    {
        IgnoreChargesDialog->setWindowTitle(QApplication::translate("IgnoreChargesDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IgnoreChargesDialog: public Ui_IgnoreChargesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IGNORECHARGESDIALOG_H
