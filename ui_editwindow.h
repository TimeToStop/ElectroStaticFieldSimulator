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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "Editor/editor.h"

QT_BEGIN_NAMESPACE

class Ui_EditWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    Editor *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EditWindow)
    {
        if (EditWindow->objectName().isEmpty())
            EditWindow->setObjectName(QString::fromUtf8("EditWindow"));
        EditWindow->resize(1089, 505);
        centralwidget = new QWidget(EditWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new Editor(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        horizontalLayout->addWidget(widget);


        horizontalLayout_2->addLayout(horizontalLayout);

        EditWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EditWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1089, 26));
        EditWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(EditWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        EditWindow->setStatusBar(statusbar);

        retranslateUi(EditWindow);

        QMetaObject::connectSlotsByName(EditWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EditWindow)
    {
        EditWindow->setWindowTitle(QCoreApplication::translate("EditWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditWindow: public Ui_EditWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITWINDOW_H
