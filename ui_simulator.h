/********************************************************************************
** Form generated from reading UI file 'simulator.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATOR_H
#define UI_SIMULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Editor/editor.h"

QT_BEGIN_NAMESPACE

class Ui_Simulator
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    Editor *widget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBox;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QComboBox *comboBox_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QLabel *label_8;
    QComboBox *comboBox_3;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_7;
    QLabel *label_9;
    QComboBox *comboBox_7;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_6;
    QLabel *label_10;
    QComboBox *comboBox_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_5;
    QLabel *label_11;
    QComboBox *comboBox_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QLabel *label_12;
    QComboBox *comboBox_4;
    QWidget *widget_3;
    QWidget *tab_2;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_13;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QComboBox *comboBox_8;
    QLabel *label_13;
    QLabel *label_14;
    QSlider *horizontalSlider;

    void setupUi(QDialog *Simulator)
    {
        if (Simulator->objectName().isEmpty())
            Simulator->setObjectName(QString::fromUtf8("Simulator"));
        Simulator->resize(1200, 633);
        gridLayout = new QGridLayout(Simulator);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new Editor(Simulator);
        widget->setObjectName(QString::fromUtf8("widget"));

        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(Simulator);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(widget_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        checkBox = new QCheckBox(tab);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout_3->addWidget(checkBox);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_6->addWidget(label);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_6->addWidget(lineEdit);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_6->addWidget(comboBox);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_7->addWidget(label_2);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_7->addWidget(lineEdit_2);

        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout_7->addWidget(comboBox_2);


        verticalLayout_5->addLayout(horizontalLayout_7);


        horizontalLayout_4->addLayout(verticalLayout_5);


        verticalLayout_3->addWidget(groupBox);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_8->addWidget(label_3);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        comboBox_3 = new QComboBox(groupBox_2);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        horizontalLayout_8->addWidget(comboBox_3);


        verticalLayout_6->addLayout(horizontalLayout_8);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_12->addWidget(label_7);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_12->addWidget(label_9);

        comboBox_7 = new QComboBox(groupBox_2);
        comboBox_7->setObjectName(QString::fromUtf8("comboBox_7"));

        horizontalLayout_12->addWidget(comboBox_7);


        verticalLayout_6->addLayout(horizontalLayout_12);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_11->addWidget(label_6);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_11->addWidget(label_10);

        comboBox_6 = new QComboBox(groupBox_2);
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));

        horizontalLayout_11->addWidget(comboBox_6);


        verticalLayout_6->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_10->addWidget(label_5);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_10->addWidget(label_11);

        comboBox_5 = new QComboBox(groupBox_2);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));

        horizontalLayout_10->addWidget(comboBox_5);


        verticalLayout_6->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_9->addWidget(label_4);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_9->addWidget(label_12);

        comboBox_4 = new QComboBox(groupBox_2);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));

        horizontalLayout_9->addWidget(comboBox_4);


        verticalLayout_6->addLayout(horizontalLayout_9);


        horizontalLayout_5->addLayout(verticalLayout_6);


        verticalLayout_2->addWidget(groupBox_2);


        horizontalLayout_3->addLayout(verticalLayout_2);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        widget_3 = new QWidget(tab);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(widget_3, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        sizePolicy2.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy2);
        widget_4->setMinimumSize(QSize(0, 30));
        widget_4->setMaximumSize(QSize(16777215, 30));
        verticalLayout_7 = new QVBoxLayout(widget_4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        pushButton = new QPushButton(widget_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_14->addWidget(pushButton);

        pushButton_4 = new QPushButton(widget_4);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_14->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(widget_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_14->addWidget(pushButton_2);


        verticalLayout_7->addLayout(horizontalLayout_14);


        verticalLayout->addWidget(widget_4);

        groupBox_3 = new QGroupBox(widget_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_13 = new QHBoxLayout(groupBox_3);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout_3->addWidget(checkBox_2, 0, 4, 1, 1);

        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        gridLayout_3->addWidget(checkBox_3, 2, 4, 1, 1);

        comboBox_8 = new QComboBox(groupBox_3);
        comboBox_8->setObjectName(QString::fromUtf8("comboBox_8"));

        gridLayout_3->addWidget(comboBox_8, 2, 2, 1, 1);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 2, 1, 1, 1);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 0, 1, 1, 1);

        horizontalSlider = new QSlider(groupBox_3);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        sizePolicy.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy);
        horizontalSlider->setMinimumSize(QSize(300, 0));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider, 0, 2, 1, 1);


        horizontalLayout_13->addLayout(gridLayout_3);


        verticalLayout->addWidget(groupBox_3);


        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addWidget(widget_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(Simulator);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Simulator);
    } // setupUi

    void retranslateUi(QDialog *Simulator)
    {
        Simulator->setWindowTitle(QCoreApplication::translate("Simulator", "Dialog", nullptr));
        checkBox->setText(QCoreApplication::translate("Simulator", "Use Cursor Position", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Simulator", "Position", nullptr));
        label->setText(QCoreApplication::translate("Simulator", "X = ", nullptr));
        label_2->setText(QCoreApplication::translate("Simulator", "Y =", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Simulator", "Info", nullptr));
        label_3->setText(QCoreApplication::translate("Simulator", "tension", nullptr));
        label_8->setText(QCoreApplication::translate("Simulator", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("Simulator", "E x", nullptr));
        label_9->setText(QCoreApplication::translate("Simulator", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("Simulator", "E y", nullptr));
        label_10->setText(QCoreApplication::translate("Simulator", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("Simulator", "potential", nullptr));
        label_11->setText(QCoreApplication::translate("Simulator", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("Simulator", "W", nullptr));
        label_12->setText(QCoreApplication::translate("Simulator", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Simulator", "Info", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Simulator", "Tab 2", nullptr));
        pushButton->setText(QCoreApplication::translate("Simulator", "Play", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Simulator", "Pause", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Simulator", "Edit", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Simulator", "Additional", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Simulator", "Show Grid", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Simulator", "Show Electro Static Field", nullptr));
        label_13->setText(QCoreApplication::translate("Simulator", "Camera At:", nullptr));
        label_14->setText(QCoreApplication::translate("Simulator", "Scale", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Simulator: public Ui_Simulator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATOR_H
