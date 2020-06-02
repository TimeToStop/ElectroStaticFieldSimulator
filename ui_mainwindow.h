/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Interface/enginewidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionExit;
    QAction *actionHow_To;
    QAction *actionDark;
    QAction *actionLight;
    QAction *actionEnglish;
    QAction *actionRussian;
    QAction *actionAbout_Programm;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    EngineWidget *m_engine;
    QWidget *widget_2;
    QGridLayout *gridLayout_4;
    QGroupBox *m_additional_group_box;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_10;
    QLabel *m_scale_label;
    QSlider *horizontalSlider;
    QCheckBox *m_show_grid;
    QCheckBox *m_show_electro_static_field;
    QLabel *m_camera_change_label;
    QComboBox *m_camera_change;
    QLabel *m_schange_scene_label;
    QComboBox *m_change_scene;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *m_play_button;
    QPushButton *m_pause_button;
    QPushButton *m_speed_button;
    QPushButton *m_edit_button;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *m_charges_group_box;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *m_add_charge_button;
    QPushButton *m_edit_charge_button;
    QPushButton *m_remove_charge_button;
    QTabWidget *m_tab_widget;
    QWidget *m_position_info_tab;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *m_use_cursor_pos_info;
    QGroupBox *m_position_group_box;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_7;
    QLabel *m_pos_x_info_label;
    QLabel *m_pos_y_info_label;
    QLineEdit *m_pos_y_info_edit;
    QLineEdit *m_pos_x_info_edit;
    QComboBox *m_pos_x_info_box;
    QComboBox *m_pos_y_info_box;
    QGroupBox *m_info_group_box;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_8;
    QComboBox *m_tension_y_label_box;
    QLabel *m_tension_y_label;
    QLabel *m_potential_label_val;
    QLabel *m_tension_x_label;
    QLabel *m_tension_y_label_val;
    QLabel *m_tension_x_label_val;
    QComboBox *m_potential_label_box;
    QLabel *m_tension_val_label_val;
    QComboBox *m_tension_val_label_box;
    QComboBox *m_tension_x_label_box;
    QLabel *m_potential_label;
    QLabel *m_tension_val_label;
    QLabel *m_energy_val_label;
    QLabel *m_energy_val_label_val;
    QComboBox *m_energy_val_label_box;
    QWidget *m_work_tab;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *m_use_cursor_start;
    QGroupBox *m_start_group_box;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_12;
    QLabel *m_pos_x_start_label;
    QLabel *m_pos_y_start_label;
    QLineEdit *m_pos_y_start_edit;
    QLineEdit *m_pos_x_start_edit;
    QComboBox *m_pos_x_start_box;
    QComboBox *m_pos_y_start_box;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *m_use_cursor_dest;
    QGroupBox *m_destination_group_box;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayout_14;
    QLabel *m_pos_x_dest_label;
    QLabel *m_pos_y_dest_label;
    QLineEdit *m_pos_y_dest_edit;
    QLineEdit *m_pos_x_dest_edit;
    QComboBox *m_pos_x_dest_box;
    QComboBox *m_pos_y_dest_box;
    QGridLayout *gridLayout_15;
    QLineEdit *m_work_charge_edit;
    QComboBox *m_work_charge_box;
    QComboBox *m_work_box;
    QLabel *m_work_label;
    QLabel *m_work_charge_label;
    QLabel *m_work_label_val;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab;
    QVBoxLayout *verticalLayout_16;
    QSpacerItem *verticalSpacer_5;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_12;
    QLabel *m_info_charges_label;
    QComboBox *m_charges_list;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *m_info_charge_q_label;
    QLabel *m_info_charge_mass_label;
    QLabel *m_info_charge_energy_label;
    QVBoxLayout *verticalLayout_3;
    QLabel *m_info_charge_q_val;
    QLabel *m_info_charge_mass_val;
    QLabel *m_info_charge_energy_val;
    QVBoxLayout *verticalLayout_8;
    QComboBox *m_info_charge_q_box;
    QComboBox *m_info_charge_mass_box;
    QComboBox *m_info_charge_energy_box;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_11;
    QLabel *m_info_charge_velocity_label;
    QLabel *m_info_charge_velocity_x_label;
    QLabel *m_info_charge_velocity_y_label;
    QVBoxLayout *verticalLayout_10;
    QLabel *m_info_charge_velocity_val;
    QLabel *m_info_charge_velocity_x_val;
    QLabel *m_info_charge_velocity_y_val;
    QVBoxLayout *verticalLayout_9;
    QComboBox *m_info_charge_velocity_box;
    QComboBox *m_info_charge_velocity_x_box;
    QComboBox *m_info_charge_velocity_y_box;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_12;
    QLabel *m_info_charge_acceleration_label;
    QLabel *m_info_charge_acceleration_x_label;
    QLabel *m_info_charge_acceleration_y_label;
    QVBoxLayout *verticalLayout_13;
    QLabel *m_info_charge_acceleration_val;
    QLabel *m_info_charge_acceleration_x_val;
    QLabel *m_info_charge_acceleration_y_val;
    QVBoxLayout *verticalLayout_14;
    QComboBox *m_info_charge_acceleration_box;
    QComboBox *m_info_charge_acceleration_x_box;
    QComboBox *m_info_charge_acceleration_y_box;
    QSpacerItem *verticalSpacer_4;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_20;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_17;
    QLabel *m_info_system_kenergy_label;
    QLabel *m_info_system_sum_energy_label;
    QLabel *m_info_system_whole_energy_label;
    QVBoxLayout *verticalLayout_18;
    QLabel *m_info_system_kenergy_val;
    QLabel *m_info_system_sum_energy_val;
    QLabel *m_info_system_whole_energy_val;
    QVBoxLayout *verticalLayout_19;
    QComboBox *m_info_system_kenergy_box;
    QComboBox *m_info_system_sum_energy_box;
    QComboBox *m_info_system_whole_energy_box;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuOptions;
    QMenu *menuLanguage;
    QMenu *menuHelp;
    QMenu *menuCredits;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1172, 638);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        MainWindow->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icons/pcharge.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionHow_To = new QAction(MainWindow);
        actionHow_To->setObjectName(QString::fromUtf8("actionHow_To"));
        actionDark = new QAction(MainWindow);
        actionDark->setObjectName(QString::fromUtf8("actionDark"));
        actionLight = new QAction(MainWindow);
        actionLight->setObjectName(QString::fromUtf8("actionLight"));
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName(QString::fromUtf8("actionEnglish"));
        actionRussian = new QAction(MainWindow);
        actionRussian->setObjectName(QString::fromUtf8("actionRussian"));
        actionAbout_Programm = new QAction(MainWindow);
        actionAbout_Programm->setObjectName(QString::fromUtf8("actionAbout_Programm"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        m_engine = new EngineWidget(centralwidget);
        m_engine->setObjectName(QString::fromUtf8("m_engine"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_engine->sizePolicy().hasHeightForWidth());
        m_engine->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(m_engine);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        widget_2->setMaximumSize(QSize(600, 600));
        gridLayout_4 = new QGridLayout(widget_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        m_additional_group_box = new QGroupBox(widget_2);
        m_additional_group_box->setObjectName(QString::fromUtf8("m_additional_group_box"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_additional_group_box->sizePolicy().hasHeightForWidth());
        m_additional_group_box->setSizePolicy(sizePolicy2);
        m_additional_group_box->setMaximumSize(QSize(16777215, 100));
        gridLayout_3 = new QGridLayout(m_additional_group_box);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        m_scale_label = new QLabel(m_additional_group_box);
        m_scale_label->setObjectName(QString::fromUtf8("m_scale_label"));

        gridLayout_10->addWidget(m_scale_label, 0, 0, 1, 1);

        horizontalSlider = new QSlider(m_additional_group_box);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy3);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(horizontalSlider, 0, 1, 1, 1);

        m_show_grid = new QCheckBox(m_additional_group_box);
        m_show_grid->setObjectName(QString::fromUtf8("m_show_grid"));

        gridLayout_10->addWidget(m_show_grid, 0, 2, 1, 1);

        m_show_electro_static_field = new QCheckBox(m_additional_group_box);
        m_show_electro_static_field->setObjectName(QString::fromUtf8("m_show_electro_static_field"));

        gridLayout_10->addWidget(m_show_electro_static_field, 0, 3, 1, 1);

        m_camera_change_label = new QLabel(m_additional_group_box);
        m_camera_change_label->setObjectName(QString::fromUtf8("m_camera_change_label"));

        gridLayout_10->addWidget(m_camera_change_label, 1, 0, 1, 1);

        m_camera_change = new QComboBox(m_additional_group_box);
        m_camera_change->setObjectName(QString::fromUtf8("m_camera_change"));

        gridLayout_10->addWidget(m_camera_change, 1, 1, 1, 1);

        m_schange_scene_label = new QLabel(m_additional_group_box);
        m_schange_scene_label->setObjectName(QString::fromUtf8("m_schange_scene_label"));

        gridLayout_10->addWidget(m_schange_scene_label, 1, 2, 1, 1);

        m_change_scene = new QComboBox(m_additional_group_box);
        m_change_scene->setObjectName(QString::fromUtf8("m_change_scene"));

        gridLayout_10->addWidget(m_change_scene, 1, 3, 1, 1);


        gridLayout_3->addLayout(gridLayout_10, 0, 0, 1, 1);


        gridLayout_4->addWidget(m_additional_group_box, 4, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        m_play_button = new QPushButton(widget_2);
        m_play_button->setObjectName(QString::fromUtf8("m_play_button"));

        horizontalLayout_3->addWidget(m_play_button);

        m_pause_button = new QPushButton(widget_2);
        m_pause_button->setObjectName(QString::fromUtf8("m_pause_button"));

        horizontalLayout_3->addWidget(m_pause_button);

        m_speed_button = new QPushButton(widget_2);
        m_speed_button->setObjectName(QString::fromUtf8("m_speed_button"));

        horizontalLayout_3->addWidget(m_speed_button);

        m_edit_button = new QPushButton(widget_2);
        m_edit_button->setObjectName(QString::fromUtf8("m_edit_button"));

        horizontalLayout_3->addWidget(m_edit_button);


        gridLayout_4->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        m_charges_group_box = new QGroupBox(widget_2);
        m_charges_group_box->setObjectName(QString::fromUtf8("m_charges_group_box"));
        m_charges_group_box->setMaximumSize(QSize(16777215, 175));
        gridLayout_2 = new QGridLayout(m_charges_group_box);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        m_add_charge_button = new QPushButton(m_charges_group_box);
        m_add_charge_button->setObjectName(QString::fromUtf8("m_add_charge_button"));

        verticalLayout_2->addWidget(m_add_charge_button);

        m_edit_charge_button = new QPushButton(m_charges_group_box);
        m_edit_charge_button->setObjectName(QString::fromUtf8("m_edit_charge_button"));

        verticalLayout_2->addWidget(m_edit_charge_button);

        m_remove_charge_button = new QPushButton(m_charges_group_box);
        m_remove_charge_button->setObjectName(QString::fromUtf8("m_remove_charge_button"));

        verticalLayout_2->addWidget(m_remove_charge_button);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(m_charges_group_box);


        gridLayout_4->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        m_tab_widget = new QTabWidget(widget_2);
        m_tab_widget->setObjectName(QString::fromUtf8("m_tab_widget"));
        sizePolicy2.setHeightForWidth(m_tab_widget->sizePolicy().hasHeightForWidth());
        m_tab_widget->setSizePolicy(sizePolicy2);
        m_tab_widget->setMaximumSize(QSize(16777215, 220));
        m_position_info_tab = new QWidget();
        m_position_info_tab->setObjectName(QString::fromUtf8("m_position_info_tab"));
        gridLayout_5 = new QGridLayout(m_position_info_tab);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        m_use_cursor_pos_info = new QCheckBox(m_position_info_tab);
        m_use_cursor_pos_info->setObjectName(QString::fromUtf8("m_use_cursor_pos_info"));

        verticalLayout_5->addWidget(m_use_cursor_pos_info);

        m_position_group_box = new QGroupBox(m_position_info_tab);
        m_position_group_box->setObjectName(QString::fromUtf8("m_position_group_box"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(m_position_group_box->sizePolicy().hasHeightForWidth());
        m_position_group_box->setSizePolicy(sizePolicy4);
        gridLayout_6 = new QGridLayout(m_position_group_box);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        m_pos_x_info_label = new QLabel(m_position_group_box);
        m_pos_x_info_label->setObjectName(QString::fromUtf8("m_pos_x_info_label"));

        gridLayout_7->addWidget(m_pos_x_info_label, 0, 0, 1, 1);

        m_pos_y_info_label = new QLabel(m_position_group_box);
        m_pos_y_info_label->setObjectName(QString::fromUtf8("m_pos_y_info_label"));

        gridLayout_7->addWidget(m_pos_y_info_label, 1, 0, 1, 1);

        m_pos_y_info_edit = new QLineEdit(m_position_group_box);
        m_pos_y_info_edit->setObjectName(QString::fromUtf8("m_pos_y_info_edit"));

        gridLayout_7->addWidget(m_pos_y_info_edit, 1, 1, 1, 1);

        m_pos_x_info_edit = new QLineEdit(m_position_group_box);
        m_pos_x_info_edit->setObjectName(QString::fromUtf8("m_pos_x_info_edit"));

        gridLayout_7->addWidget(m_pos_x_info_edit, 0, 1, 1, 1);

        m_pos_x_info_box = new QComboBox(m_position_group_box);
        m_pos_x_info_box->setObjectName(QString::fromUtf8("m_pos_x_info_box"));

        gridLayout_7->addWidget(m_pos_x_info_box, 0, 2, 1, 1);

        m_pos_y_info_box = new QComboBox(m_position_group_box);
        m_pos_y_info_box->setObjectName(QString::fromUtf8("m_pos_y_info_box"));

        gridLayout_7->addWidget(m_pos_y_info_box, 1, 2, 1, 1);


        gridLayout_6->addLayout(gridLayout_7, 0, 0, 1, 1);


        verticalLayout_5->addWidget(m_position_group_box);


        horizontalLayout_6->addLayout(verticalLayout_5);

        m_info_group_box = new QGroupBox(m_position_info_tab);
        m_info_group_box->setObjectName(QString::fromUtf8("m_info_group_box"));
        m_info_group_box->setCheckable(false);
        m_info_group_box->setChecked(false);
        gridLayout_9 = new QGridLayout(m_info_group_box);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        m_tension_y_label_box = new QComboBox(m_info_group_box);
        m_tension_y_label_box->setObjectName(QString::fromUtf8("m_tension_y_label_box"));

        gridLayout_8->addWidget(m_tension_y_label_box, 2, 2, 1, 1);

        m_tension_y_label = new QLabel(m_info_group_box);
        m_tension_y_label->setObjectName(QString::fromUtf8("m_tension_y_label"));

        gridLayout_8->addWidget(m_tension_y_label, 2, 0, 1, 1);

        m_potential_label_val = new QLabel(m_info_group_box);
        m_potential_label_val->setObjectName(QString::fromUtf8("m_potential_label_val"));

        gridLayout_8->addWidget(m_potential_label_val, 3, 1, 1, 1);

        m_tension_x_label = new QLabel(m_info_group_box);
        m_tension_x_label->setObjectName(QString::fromUtf8("m_tension_x_label"));

        gridLayout_8->addWidget(m_tension_x_label, 1, 0, 1, 1);

        m_tension_y_label_val = new QLabel(m_info_group_box);
        m_tension_y_label_val->setObjectName(QString::fromUtf8("m_tension_y_label_val"));

        gridLayout_8->addWidget(m_tension_y_label_val, 2, 1, 1, 1);

        m_tension_x_label_val = new QLabel(m_info_group_box);
        m_tension_x_label_val->setObjectName(QString::fromUtf8("m_tension_x_label_val"));

        gridLayout_8->addWidget(m_tension_x_label_val, 1, 1, 1, 1);

        m_potential_label_box = new QComboBox(m_info_group_box);
        m_potential_label_box->setObjectName(QString::fromUtf8("m_potential_label_box"));

        gridLayout_8->addWidget(m_potential_label_box, 3, 2, 1, 1);

        m_tension_val_label_val = new QLabel(m_info_group_box);
        m_tension_val_label_val->setObjectName(QString::fromUtf8("m_tension_val_label_val"));

        gridLayout_8->addWidget(m_tension_val_label_val, 0, 1, 1, 1);

        m_tension_val_label_box = new QComboBox(m_info_group_box);
        m_tension_val_label_box->setObjectName(QString::fromUtf8("m_tension_val_label_box"));

        gridLayout_8->addWidget(m_tension_val_label_box, 0, 2, 1, 1);

        m_tension_x_label_box = new QComboBox(m_info_group_box);
        m_tension_x_label_box->setObjectName(QString::fromUtf8("m_tension_x_label_box"));

        gridLayout_8->addWidget(m_tension_x_label_box, 1, 2, 1, 1);

        m_potential_label = new QLabel(m_info_group_box);
        m_potential_label->setObjectName(QString::fromUtf8("m_potential_label"));

        gridLayout_8->addWidget(m_potential_label, 3, 0, 1, 1);

        m_tension_val_label = new QLabel(m_info_group_box);
        m_tension_val_label->setObjectName(QString::fromUtf8("m_tension_val_label"));

        gridLayout_8->addWidget(m_tension_val_label, 0, 0, 1, 1);

        m_energy_val_label = new QLabel(m_info_group_box);
        m_energy_val_label->setObjectName(QString::fromUtf8("m_energy_val_label"));

        gridLayout_8->addWidget(m_energy_val_label, 4, 0, 1, 1);

        m_energy_val_label_val = new QLabel(m_info_group_box);
        m_energy_val_label_val->setObjectName(QString::fromUtf8("m_energy_val_label_val"));

        gridLayout_8->addWidget(m_energy_val_label_val, 4, 1, 1, 1);

        m_energy_val_label_box = new QComboBox(m_info_group_box);
        m_energy_val_label_box->setObjectName(QString::fromUtf8("m_energy_val_label_box"));

        gridLayout_8->addWidget(m_energy_val_label_box, 4, 2, 1, 1);


        gridLayout_9->addLayout(gridLayout_8, 0, 0, 1, 1);


        horizontalLayout_6->addWidget(m_info_group_box);


        gridLayout_5->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        m_tab_widget->addTab(m_position_info_tab, QString());
        m_work_tab = new QWidget();
        m_work_tab->setObjectName(QString::fromUtf8("m_work_tab"));
        horizontalLayout_9 = new QHBoxLayout(m_work_tab);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        m_use_cursor_start = new QCheckBox(m_work_tab);
        m_use_cursor_start->setObjectName(QString::fromUtf8("m_use_cursor_start"));

        verticalLayout_6->addWidget(m_use_cursor_start);

        m_start_group_box = new QGroupBox(m_work_tab);
        m_start_group_box->setObjectName(QString::fromUtf8("m_start_group_box"));
        gridLayout_11 = new QGridLayout(m_start_group_box);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        m_pos_x_start_label = new QLabel(m_start_group_box);
        m_pos_x_start_label->setObjectName(QString::fromUtf8("m_pos_x_start_label"));

        gridLayout_12->addWidget(m_pos_x_start_label, 0, 0, 1, 1);

        m_pos_y_start_label = new QLabel(m_start_group_box);
        m_pos_y_start_label->setObjectName(QString::fromUtf8("m_pos_y_start_label"));

        gridLayout_12->addWidget(m_pos_y_start_label, 1, 0, 1, 1);

        m_pos_y_start_edit = new QLineEdit(m_start_group_box);
        m_pos_y_start_edit->setObjectName(QString::fromUtf8("m_pos_y_start_edit"));

        gridLayout_12->addWidget(m_pos_y_start_edit, 1, 1, 1, 1);

        m_pos_x_start_edit = new QLineEdit(m_start_group_box);
        m_pos_x_start_edit->setObjectName(QString::fromUtf8("m_pos_x_start_edit"));

        gridLayout_12->addWidget(m_pos_x_start_edit, 0, 1, 1, 1);

        m_pos_x_start_box = new QComboBox(m_start_group_box);
        m_pos_x_start_box->setObjectName(QString::fromUtf8("m_pos_x_start_box"));

        gridLayout_12->addWidget(m_pos_x_start_box, 0, 2, 1, 1);

        m_pos_y_start_box = new QComboBox(m_start_group_box);
        m_pos_y_start_box->setObjectName(QString::fromUtf8("m_pos_y_start_box"));

        gridLayout_12->addWidget(m_pos_y_start_box, 1, 2, 1, 1);


        gridLayout_11->addLayout(gridLayout_12, 0, 0, 1, 1);


        verticalLayout_6->addWidget(m_start_group_box);


        horizontalLayout_7->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        m_use_cursor_dest = new QCheckBox(m_work_tab);
        m_use_cursor_dest->setObjectName(QString::fromUtf8("m_use_cursor_dest"));

        verticalLayout_7->addWidget(m_use_cursor_dest);

        m_destination_group_box = new QGroupBox(m_work_tab);
        m_destination_group_box->setObjectName(QString::fromUtf8("m_destination_group_box"));
        gridLayout_13 = new QGridLayout(m_destination_group_box);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_14 = new QGridLayout();
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        m_pos_x_dest_label = new QLabel(m_destination_group_box);
        m_pos_x_dest_label->setObjectName(QString::fromUtf8("m_pos_x_dest_label"));

        gridLayout_14->addWidget(m_pos_x_dest_label, 0, 0, 1, 1);

        m_pos_y_dest_label = new QLabel(m_destination_group_box);
        m_pos_y_dest_label->setObjectName(QString::fromUtf8("m_pos_y_dest_label"));

        gridLayout_14->addWidget(m_pos_y_dest_label, 1, 0, 1, 1);

        m_pos_y_dest_edit = new QLineEdit(m_destination_group_box);
        m_pos_y_dest_edit->setObjectName(QString::fromUtf8("m_pos_y_dest_edit"));

        gridLayout_14->addWidget(m_pos_y_dest_edit, 1, 1, 1, 1);

        m_pos_x_dest_edit = new QLineEdit(m_destination_group_box);
        m_pos_x_dest_edit->setObjectName(QString::fromUtf8("m_pos_x_dest_edit"));

        gridLayout_14->addWidget(m_pos_x_dest_edit, 0, 1, 1, 1);

        m_pos_x_dest_box = new QComboBox(m_destination_group_box);
        m_pos_x_dest_box->setObjectName(QString::fromUtf8("m_pos_x_dest_box"));

        gridLayout_14->addWidget(m_pos_x_dest_box, 0, 2, 1, 1);

        m_pos_y_dest_box = new QComboBox(m_destination_group_box);
        m_pos_y_dest_box->setObjectName(QString::fromUtf8("m_pos_y_dest_box"));

        gridLayout_14->addWidget(m_pos_y_dest_box, 1, 2, 1, 1);


        gridLayout_13->addLayout(gridLayout_14, 0, 0, 1, 1);


        verticalLayout_7->addWidget(m_destination_group_box);


        horizontalLayout_7->addLayout(verticalLayout_7);

        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        m_work_charge_edit = new QLineEdit(m_work_tab);
        m_work_charge_edit->setObjectName(QString::fromUtf8("m_work_charge_edit"));

        gridLayout_15->addWidget(m_work_charge_edit, 1, 1, 1, 1);

        m_work_charge_box = new QComboBox(m_work_tab);
        m_work_charge_box->setObjectName(QString::fromUtf8("m_work_charge_box"));

        gridLayout_15->addWidget(m_work_charge_box, 1, 2, 1, 1);

        m_work_box = new QComboBox(m_work_tab);
        m_work_box->setObjectName(QString::fromUtf8("m_work_box"));

        gridLayout_15->addWidget(m_work_box, 2, 2, 1, 1);

        m_work_label = new QLabel(m_work_tab);
        m_work_label->setObjectName(QString::fromUtf8("m_work_label"));

        gridLayout_15->addWidget(m_work_label, 2, 0, 1, 1);

        m_work_charge_label = new QLabel(m_work_tab);
        m_work_charge_label->setObjectName(QString::fromUtf8("m_work_charge_label"));

        gridLayout_15->addWidget(m_work_charge_label, 1, 0, 1, 1);

        m_work_label_val = new QLabel(m_work_tab);
        m_work_label_val->setObjectName(QString::fromUtf8("m_work_label_val"));

        gridLayout_15->addWidget(m_work_label_val, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 85, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_15->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_15->addItem(verticalSpacer_2, 3, 1, 1, 1);


        horizontalLayout_7->addLayout(gridLayout_15);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        horizontalLayout_9->addLayout(horizontalLayout_8);

        m_tab_widget->addTab(m_work_tab, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_16 = new QVBoxLayout(tab);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_5);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        m_info_charges_label = new QLabel(tab);
        m_info_charges_label->setObjectName(QString::fromUtf8("m_info_charges_label"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(m_info_charges_label->sizePolicy().hasHeightForWidth());
        m_info_charges_label->setSizePolicy(sizePolicy5);

        horizontalLayout_12->addWidget(m_info_charges_label);

        m_charges_list = new QComboBox(tab);
        m_charges_list->setObjectName(QString::fromUtf8("m_charges_list"));

        horizontalLayout_12->addWidget(m_charges_list);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);


        verticalLayout_15->addLayout(horizontalLayout_12);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_15->addItem(verticalSpacer_3);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_info_charge_q_label = new QLabel(tab);
        m_info_charge_q_label->setObjectName(QString::fromUtf8("m_info_charge_q_label"));
        m_info_charge_q_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(m_info_charge_q_label);

        m_info_charge_mass_label = new QLabel(tab);
        m_info_charge_mass_label->setObjectName(QString::fromUtf8("m_info_charge_mass_label"));
        m_info_charge_mass_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(m_info_charge_mass_label);

        m_info_charge_energy_label = new QLabel(tab);
        m_info_charge_energy_label->setObjectName(QString::fromUtf8("m_info_charge_energy_label"));
        m_info_charge_energy_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(m_info_charge_energy_label);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        m_info_charge_q_val = new QLabel(tab);
        m_info_charge_q_val->setObjectName(QString::fromUtf8("m_info_charge_q_val"));
        m_info_charge_q_val->setFrameShadow(QFrame::Plain);
        m_info_charge_q_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        m_info_charge_q_val->setWordWrap(false);

        verticalLayout_3->addWidget(m_info_charge_q_val);

        m_info_charge_mass_val = new QLabel(tab);
        m_info_charge_mass_val->setObjectName(QString::fromUtf8("m_info_charge_mass_val"));
        m_info_charge_mass_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(m_info_charge_mass_val);

        m_info_charge_energy_val = new QLabel(tab);
        m_info_charge_energy_val->setObjectName(QString::fromUtf8("m_info_charge_energy_val"));
        m_info_charge_energy_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(m_info_charge_energy_val);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        m_info_charge_q_box = new QComboBox(tab);
        m_info_charge_q_box->setObjectName(QString::fromUtf8("m_info_charge_q_box"));

        verticalLayout_8->addWidget(m_info_charge_q_box);

        m_info_charge_mass_box = new QComboBox(tab);
        m_info_charge_mass_box->setObjectName(QString::fromUtf8("m_info_charge_mass_box"));

        verticalLayout_8->addWidget(m_info_charge_mass_box);

        m_info_charge_energy_box = new QComboBox(tab);
        m_info_charge_energy_box->setObjectName(QString::fromUtf8("m_info_charge_energy_box"));

        verticalLayout_8->addWidget(m_info_charge_energy_box);


        horizontalLayout_4->addLayout(verticalLayout_8);


        horizontalLayout_11->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        m_info_charge_velocity_label = new QLabel(tab);
        m_info_charge_velocity_label->setObjectName(QString::fromUtf8("m_info_charge_velocity_label"));
        m_info_charge_velocity_label->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(m_info_charge_velocity_label);

        m_info_charge_velocity_x_label = new QLabel(tab);
        m_info_charge_velocity_x_label->setObjectName(QString::fromUtf8("m_info_charge_velocity_x_label"));
        m_info_charge_velocity_x_label->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(m_info_charge_velocity_x_label);

        m_info_charge_velocity_y_label = new QLabel(tab);
        m_info_charge_velocity_y_label->setObjectName(QString::fromUtf8("m_info_charge_velocity_y_label"));
        m_info_charge_velocity_y_label->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(m_info_charge_velocity_y_label);


        horizontalLayout_5->addLayout(verticalLayout_11);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        m_info_charge_velocity_val = new QLabel(tab);
        m_info_charge_velocity_val->setObjectName(QString::fromUtf8("m_info_charge_velocity_val"));
        m_info_charge_velocity_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_10->addWidget(m_info_charge_velocity_val);

        m_info_charge_velocity_x_val = new QLabel(tab);
        m_info_charge_velocity_x_val->setObjectName(QString::fromUtf8("m_info_charge_velocity_x_val"));
        m_info_charge_velocity_x_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_10->addWidget(m_info_charge_velocity_x_val);

        m_info_charge_velocity_y_val = new QLabel(tab);
        m_info_charge_velocity_y_val->setObjectName(QString::fromUtf8("m_info_charge_velocity_y_val"));
        m_info_charge_velocity_y_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_10->addWidget(m_info_charge_velocity_y_val);


        horizontalLayout_5->addLayout(verticalLayout_10);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        m_info_charge_velocity_box = new QComboBox(tab);
        m_info_charge_velocity_box->setObjectName(QString::fromUtf8("m_info_charge_velocity_box"));

        verticalLayout_9->addWidget(m_info_charge_velocity_box);

        m_info_charge_velocity_x_box = new QComboBox(tab);
        m_info_charge_velocity_x_box->setObjectName(QString::fromUtf8("m_info_charge_velocity_x_box"));

        verticalLayout_9->addWidget(m_info_charge_velocity_x_box);

        m_info_charge_velocity_y_box = new QComboBox(tab);
        m_info_charge_velocity_y_box->setObjectName(QString::fromUtf8("m_info_charge_velocity_y_box"));

        verticalLayout_9->addWidget(m_info_charge_velocity_y_box);


        horizontalLayout_5->addLayout(verticalLayout_9);


        horizontalLayout_11->addLayout(horizontalLayout_5);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        m_info_charge_acceleration_label = new QLabel(tab);
        m_info_charge_acceleration_label->setObjectName(QString::fromUtf8("m_info_charge_acceleration_label"));
        m_info_charge_acceleration_label->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(m_info_charge_acceleration_label);

        m_info_charge_acceleration_x_label = new QLabel(tab);
        m_info_charge_acceleration_x_label->setObjectName(QString::fromUtf8("m_info_charge_acceleration_x_label"));
        m_info_charge_acceleration_x_label->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(m_info_charge_acceleration_x_label);

        m_info_charge_acceleration_y_label = new QLabel(tab);
        m_info_charge_acceleration_y_label->setObjectName(QString::fromUtf8("m_info_charge_acceleration_y_label"));
        m_info_charge_acceleration_y_label->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(m_info_charge_acceleration_y_label);


        horizontalLayout_10->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        m_info_charge_acceleration_val = new QLabel(tab);
        m_info_charge_acceleration_val->setObjectName(QString::fromUtf8("m_info_charge_acceleration_val"));
        m_info_charge_acceleration_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_13->addWidget(m_info_charge_acceleration_val);

        m_info_charge_acceleration_x_val = new QLabel(tab);
        m_info_charge_acceleration_x_val->setObjectName(QString::fromUtf8("m_info_charge_acceleration_x_val"));
        m_info_charge_acceleration_x_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_13->addWidget(m_info_charge_acceleration_x_val);

        m_info_charge_acceleration_y_val = new QLabel(tab);
        m_info_charge_acceleration_y_val->setObjectName(QString::fromUtf8("m_info_charge_acceleration_y_val"));
        m_info_charge_acceleration_y_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_13->addWidget(m_info_charge_acceleration_y_val);


        horizontalLayout_10->addLayout(verticalLayout_13);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        m_info_charge_acceleration_box = new QComboBox(tab);
        m_info_charge_acceleration_box->setObjectName(QString::fromUtf8("m_info_charge_acceleration_box"));

        verticalLayout_14->addWidget(m_info_charge_acceleration_box);

        m_info_charge_acceleration_x_box = new QComboBox(tab);
        m_info_charge_acceleration_x_box->setObjectName(QString::fromUtf8("m_info_charge_acceleration_x_box"));

        verticalLayout_14->addWidget(m_info_charge_acceleration_x_box);

        m_info_charge_acceleration_y_box = new QComboBox(tab);
        m_info_charge_acceleration_y_box->setObjectName(QString::fromUtf8("m_info_charge_acceleration_y_box"));

        verticalLayout_14->addWidget(m_info_charge_acceleration_y_box);


        horizontalLayout_10->addLayout(verticalLayout_14);


        horizontalLayout_11->addLayout(horizontalLayout_10);


        verticalLayout_15->addLayout(horizontalLayout_11);


        verticalLayout_16->addLayout(verticalLayout_15);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_4);

        m_tab_widget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_20 = new QVBoxLayout(tab_2);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_2);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        m_info_system_kenergy_label = new QLabel(tab_2);
        m_info_system_kenergy_label->setObjectName(QString::fromUtf8("m_info_system_kenergy_label"));
        m_info_system_kenergy_label->setAlignment(Qt::AlignCenter);

        verticalLayout_17->addWidget(m_info_system_kenergy_label);

        m_info_system_sum_energy_label = new QLabel(tab_2);
        m_info_system_sum_energy_label->setObjectName(QString::fromUtf8("m_info_system_sum_energy_label"));
        m_info_system_sum_energy_label->setAlignment(Qt::AlignCenter);

        verticalLayout_17->addWidget(m_info_system_sum_energy_label);

        m_info_system_whole_energy_label = new QLabel(tab_2);
        m_info_system_whole_energy_label->setObjectName(QString::fromUtf8("m_info_system_whole_energy_label"));
        m_info_system_whole_energy_label->setAlignment(Qt::AlignCenter);

        verticalLayout_17->addWidget(m_info_system_whole_energy_label);


        horizontalLayout_13->addLayout(verticalLayout_17);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        m_info_system_kenergy_val = new QLabel(tab_2);
        m_info_system_kenergy_val->setObjectName(QString::fromUtf8("m_info_system_kenergy_val"));
        m_info_system_kenergy_val->setAlignment(Qt::AlignCenter);

        verticalLayout_18->addWidget(m_info_system_kenergy_val);

        m_info_system_sum_energy_val = new QLabel(tab_2);
        m_info_system_sum_energy_val->setObjectName(QString::fromUtf8("m_info_system_sum_energy_val"));
        m_info_system_sum_energy_val->setAlignment(Qt::AlignCenter);

        verticalLayout_18->addWidget(m_info_system_sum_energy_val);

        m_info_system_whole_energy_val = new QLabel(tab_2);
        m_info_system_whole_energy_val->setObjectName(QString::fromUtf8("m_info_system_whole_energy_val"));
        m_info_system_whole_energy_val->setAlignment(Qt::AlignCenter);

        verticalLayout_18->addWidget(m_info_system_whole_energy_val);


        horizontalLayout_13->addLayout(verticalLayout_18);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        m_info_system_kenergy_box = new QComboBox(tab_2);
        m_info_system_kenergy_box->setObjectName(QString::fromUtf8("m_info_system_kenergy_box"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(m_info_system_kenergy_box->sizePolicy().hasHeightForWidth());
        m_info_system_kenergy_box->setSizePolicy(sizePolicy6);

        verticalLayout_19->addWidget(m_info_system_kenergy_box);

        m_info_system_sum_energy_box = new QComboBox(tab_2);
        m_info_system_sum_energy_box->setObjectName(QString::fromUtf8("m_info_system_sum_energy_box"));

        verticalLayout_19->addWidget(m_info_system_sum_energy_box);

        m_info_system_whole_energy_box = new QComboBox(tab_2);
        m_info_system_whole_energy_box->setObjectName(QString::fromUtf8("m_info_system_whole_energy_box"));

        verticalLayout_19->addWidget(m_info_system_whole_energy_box);


        horizontalLayout_13->addLayout(verticalLayout_19);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_3);


        verticalLayout_20->addLayout(horizontalLayout_13);

        m_tab_widget->addTab(tab_2, QString());

        gridLayout_4->addWidget(m_tab_widget, 2, 0, 1, 1);


        horizontalLayout->addWidget(widget_2);


        verticalLayout_4->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1172, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuLanguage = new QMenu(menuOptions);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuCredits = new QMenu(menubar);
        menuCredits->setObjectName(QString::fromUtf8("menuCredits"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menubar->addAction(menuCredits->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuOptions->addAction(menuLanguage->menuAction());
        menuLanguage->addAction(actionEnglish);
        menuLanguage->addAction(actionRussian);
        menuHelp->addAction(actionHow_To);
        menuCredits->addAction(actionAbout_Programm);

        retranslateUi(MainWindow);
        QObject::connect(m_show_grid, SIGNAL(stateChanged(int)), MainWindow, SLOT(showGrid(int)));
        QObject::connect(m_show_electro_static_field, SIGNAL(stateChanged(int)), MainWindow, SLOT(showElectroStaticField(int)));
        QObject::connect(m_add_charge_button, SIGNAL(clicked()), MainWindow, SLOT(addCharge()));
        QObject::connect(m_edit_charge_button, SIGNAL(clicked()), MainWindow, SLOT(editCharge()));
        QObject::connect(m_remove_charge_button, SIGNAL(clicked()), MainWindow, SLOT(rmCharge()));
        QObject::connect(m_play_button, SIGNAL(clicked()), MainWindow, SLOT(play()));
        QObject::connect(m_pause_button, SIGNAL(clicked()), MainWindow, SLOT(pause()));
        QObject::connect(m_speed_button, SIGNAL(clicked()), MainWindow, SLOT(speed_x_2()));
        QObject::connect(m_edit_button, SIGNAL(clicked()), MainWindow, SLOT(edit()));

        m_tab_widget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Charges Simulator", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionHow_To->setText(QCoreApplication::translate("MainWindow", "How To", nullptr));
        actionDark->setText(QCoreApplication::translate("MainWindow", "Dark", nullptr));
        actionLight->setText(QCoreApplication::translate("MainWindow", "Light", nullptr));
        actionEnglish->setText(QCoreApplication::translate("MainWindow", "English", nullptr));
        actionRussian->setText(QCoreApplication::translate("MainWindow", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));
        actionAbout_Programm->setText(QCoreApplication::translate("MainWindow", "About Programm", nullptr));
        m_additional_group_box->setTitle(QCoreApplication::translate("MainWindow", "Additional", nullptr));
        m_scale_label->setText(QCoreApplication::translate("MainWindow", "Scale:", nullptr));
        m_show_grid->setText(QCoreApplication::translate("MainWindow", "Show Grid", nullptr));
        m_show_electro_static_field->setText(QCoreApplication::translate("MainWindow", "Show Electro Static Field ", nullptr));
        m_camera_change_label->setText(QCoreApplication::translate("MainWindow", "Camera at:", nullptr));
        m_schange_scene_label->setText(QCoreApplication::translate("MainWindow", "Change scene:", nullptr));
        m_play_button->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        m_pause_button->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        m_speed_button->setText(QCoreApplication::translate("MainWindow", "Speed x 2", nullptr));
        m_edit_button->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        m_charges_group_box->setTitle(QCoreApplication::translate("MainWindow", "Charges", nullptr));
        m_add_charge_button->setText(QCoreApplication::translate("MainWindow", "Add Charge", nullptr));
        m_edit_charge_button->setText(QCoreApplication::translate("MainWindow", "Edit Charge", nullptr));
        m_remove_charge_button->setText(QCoreApplication::translate("MainWindow", "Remove Charge", nullptr));
        m_use_cursor_pos_info->setText(QCoreApplication::translate("MainWindow", "Use Cursor Position", nullptr));
        m_position_group_box->setTitle(QCoreApplication::translate("MainWindow", "Position", nullptr));
        m_pos_x_info_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_pos_y_info_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_info_group_box->setTitle(QCoreApplication::translate("MainWindow", "Info", nullptr));
        m_tension_y_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_potential_label_val->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_tension_x_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_tension_y_label_val->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_tension_x_label_val->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_tension_val_label_val->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_potential_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_tension_val_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_energy_val_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_energy_val_label_val->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_tab_widget->setTabText(m_tab_widget->indexOf(m_position_info_tab), QCoreApplication::translate("MainWindow", "Position Info", nullptr));
        m_use_cursor_start->setText(QCoreApplication::translate("MainWindow", "Use Cursor Position", nullptr));
        m_start_group_box->setTitle(QCoreApplication::translate("MainWindow", "Start", nullptr));
        m_pos_x_start_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_pos_y_start_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_use_cursor_dest->setText(QCoreApplication::translate("MainWindow", "Use Cursor Position", nullptr));
        m_destination_group_box->setTitle(QCoreApplication::translate("MainWindow", "Destination", nullptr));
        m_pos_x_dest_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_pos_y_dest_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_work_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_work_charge_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_work_label_val->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        m_tab_widget->setTabText(m_tab_widget->indexOf(m_work_tab), QCoreApplication::translate("MainWindow", "Work", nullptr));
        m_info_charges_label->setText(QCoreApplication::translate("MainWindow", "Charge", nullptr));
        m_info_charge_q_label->setText(QCoreApplication::translate("MainWindow", "q", nullptr));
        m_info_charge_mass_label->setText(QCoreApplication::translate("MainWindow", "m", nullptr));
        m_info_charge_energy_label->setText(QCoreApplication::translate("MainWindow", "Ek", nullptr));
        m_info_charge_q_val->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        m_info_charge_mass_val->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        m_info_charge_energy_val->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        m_info_charge_velocity_label->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        m_info_charge_velocity_x_label->setText(QCoreApplication::translate("MainWindow", "Vx", nullptr));
        m_info_charge_velocity_y_label->setText(QCoreApplication::translate("MainWindow", "Vy", nullptr));
        m_info_charge_velocity_val->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        m_info_charge_velocity_x_val->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        m_info_charge_velocity_y_val->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        m_info_charge_acceleration_label->setText(QCoreApplication::translate("MainWindow", "a", nullptr));
        m_info_charge_acceleration_x_label->setText(QCoreApplication::translate("MainWindow", "a_x", nullptr));
        m_info_charge_acceleration_y_label->setText(QCoreApplication::translate("MainWindow", "a_y", nullptr));
        m_info_charge_acceleration_val->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        m_info_charge_acceleration_x_val->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        m_info_charge_acceleration_y_val->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        m_tab_widget->setTabText(m_tab_widget->indexOf(tab), QCoreApplication::translate("MainWindow", "Charge Info", nullptr));
        m_info_system_kenergy_label->setText(QCoreApplication::translate("MainWindow", "S Ek", nullptr));
        m_info_system_sum_energy_label->setText(QCoreApplication::translate("MainWindow", "S W", nullptr));
        m_info_system_whole_energy_label->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        m_info_system_kenergy_val->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        m_info_system_sum_energy_val->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        m_info_system_whole_energy_val->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        m_tab_widget->setTabText(m_tab_widget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "System Info", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
        menuLanguage->setTitle(QCoreApplication::translate("MainWindow", "Language", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuCredits->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
