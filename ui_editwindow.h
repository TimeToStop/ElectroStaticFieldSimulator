/********************************************************************************
** Form generated from reading UI file 'editwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITWINDOW_H
#define UI_EDITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Editor/editor.h"

QT_BEGIN_NAMESPACE

class Ui_EditWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExit;
    QAction *actionRussian;
    QAction *actionEnglish;
    QAction *actionLight;
    QAction *actionDark;
    QAction *actionStandart;
    QAction *actionHow_To;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    Editor *widget;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QPushButton *sumilate;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuOptions;
    QMenu *menuLanguage;
    QMenu *menuTheme;
    QMenu *menuHelp;
    QMenu *menuCredits;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EditWindow)
    {
        if (EditWindow->objectName().isEmpty())
            EditWindow->setObjectName(QString::fromUtf8("EditWindow"));
        EditWindow->resize(1089, 505);
        actionOpen = new QAction(EditWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(EditWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(EditWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionExit = new QAction(EditWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionRussian = new QAction(EditWindow);
        actionRussian->setObjectName(QString::fromUtf8("actionRussian"));
        actionEnglish = new QAction(EditWindow);
        actionEnglish->setObjectName(QString::fromUtf8("actionEnglish"));
        actionLight = new QAction(EditWindow);
        actionLight->setObjectName(QString::fromUtf8("actionLight"));
        actionDark = new QAction(EditWindow);
        actionDark->setObjectName(QString::fromUtf8("actionDark"));
        actionStandart = new QAction(EditWindow);
        actionStandart->setObjectName(QString::fromUtf8("actionStandart"));
        actionHow_To = new QAction(EditWindow);
        actionHow_To->setObjectName(QString::fromUtf8("actionHow_To"));
        centralwidget = new QWidget(EditWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new Editor(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setMinimumSize(QSize(400, 0));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        sumilate = new QPushButton(widget_2);
        sumilate->setObjectName(QString::fromUtf8("sumilate"));

        gridLayout->addWidget(sumilate, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(widget_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_2->addWidget(pushButton_3);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        horizontalLayout->addWidget(widget_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        EditWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EditWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1089, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuLanguage = new QMenu(menuOptions);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        menuTheme = new QMenu(menuOptions);
        menuTheme->setObjectName(QString::fromUtf8("menuTheme"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuCredits = new QMenu(menubar);
        menuCredits->setObjectName(QString::fromUtf8("menuCredits"));
        EditWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(EditWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        EditWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menubar->addAction(menuCredits->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuOptions->addAction(menuTheme->menuAction());
        menuOptions->addAction(menuLanguage->menuAction());
        menuLanguage->addAction(actionRussian);
        menuLanguage->addAction(actionEnglish);
        menuTheme->addAction(actionLight);
        menuTheme->addAction(actionDark);
        menuTheme->addAction(actionStandart);
        menuHelp->addAction(actionHow_To);

        retranslateUi(EditWindow);
        QObject::connect(sumilate, SIGNAL(clicked()), EditWindow, SLOT(simulate()));

        QMetaObject::connectSlotsByName(EditWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EditWindow)
    {
        EditWindow->setWindowTitle(QCoreApplication::translate("EditWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("EditWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("EditWindow", "Save", nullptr));
        actionSave_As->setText(QCoreApplication::translate("EditWindow", "Save As", nullptr));
        actionExit->setText(QCoreApplication::translate("EditWindow", "Exit", nullptr));
        actionRussian->setText(QCoreApplication::translate("EditWindow", "Russian", nullptr));
        actionEnglish->setText(QCoreApplication::translate("EditWindow", "English", nullptr));
        actionLight->setText(QCoreApplication::translate("EditWindow", "Light", nullptr));
        actionDark->setText(QCoreApplication::translate("EditWindow", "Dark", nullptr));
        actionStandart->setText(QCoreApplication::translate("EditWindow", "Standart", nullptr));
        actionHow_To->setText(QCoreApplication::translate("EditWindow", "How To", nullptr));
        sumilate->setText(QCoreApplication::translate("EditWindow", "Simulate", nullptr));
        groupBox->setTitle(QCoreApplication::translate("EditWindow", "Charges", nullptr));
        pushButton_2->setText(QCoreApplication::translate("EditWindow", "Add Charge", nullptr));
        pushButton_3->setText(QCoreApplication::translate("EditWindow", "Edit Charge", nullptr));
        pushButton->setText(QCoreApplication::translate("EditWindow", "Remove Charge", nullptr));
        menuFile->setTitle(QCoreApplication::translate("EditWindow", "File", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("EditWindow", "Options", nullptr));
        menuLanguage->setTitle(QCoreApplication::translate("EditWindow", "Language", nullptr));
        menuTheme->setTitle(QCoreApplication::translate("EditWindow", "Theme", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("EditWindow", "Help", nullptr));
        menuCredits->setTitle(QCoreApplication::translate("EditWindow", "Credits", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditWindow: public Ui_EditWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITWINDOW_H
