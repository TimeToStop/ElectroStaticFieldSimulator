#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Interface/Charge/createchargedialog.h"
#include "Interface/Charge/ignorechargesdialog.h"
#include "Interface/Charge/selectcharge.h"
#include "Interface/help.h"
#include "Interface/help_eng.h"
#include "about.h"
#include "Engine/charge.h"

#include "Options/translator.h"
#include "Options/colortheme.h"

#include <QDebug>
#include <QFileDialog>
#include <QtXml/QDomDocument>
#include <QXmlStreamWriter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_use_cursor(false),
    m_pos_x("X", "м"),
    m_pos_y("Y", "м"),
    m_tension_val("E", "В/м"),
    m_tension_x("Ex", "В/м"),
    m_tension_y("Ey", "В/м"),
    m_potential("φ", "В"),
    m_energy("W", "Дж"),
    m_start_pos_x("X", "м"),
    m_start_pos_y("Y", "м"),
    m_dest_pos_x("X", "м"),
    m_dest_pos_y("Y", "м"),
    m_charge("q", "Кл"),
    m_work("A", "Дж"),
    m_info_charge_q("q", "Кл"),
    m_info_charge_mass("m", "кг"),
    m_info_charge_velocity("V", "м/c"),
    m_info_charge_velocity_x("Vx", "м/c"),
    m_info_charge_velocity_y("Vy", "м/c"),
    m_info_charge_acceleration("a", "м/с^2"),
    m_info_charge_acceleration_x("a_x", "м/с^2"),
    m_info_charge_acceleration_y("a_y", "м/c^2"),
    m_info_charge_energy("Ek", "Дж"),
    m_info_system_sum_kenergy("Σ Ek", "Дж"),
    m_info_system_sum_energy("Σ W", "Дж"),
    m_info_system_whole_energy("Wsys", "Дж"),
    filename(""),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->m_show_grid->setChecked(true);

    m_pos_x.setWidgets(ui->m_pos_x_info_label, ui->m_pos_x_info_edit, ui->m_pos_x_info_box);
    m_pos_y.setWidgets(ui->m_pos_y_info_label, ui->m_pos_y_info_edit, ui->m_pos_y_info_box);

    m_tension_val.setWidgets(ui->m_tension_val_label, ui->m_tension_val_label_val, ui->m_tension_val_label_box);
    m_tension_x.setWidgets(ui->m_tension_x_label, ui->m_tension_x_label_val, ui->m_tension_x_label_box);
    m_tension_y.setWidgets(ui->m_tension_y_label, ui->m_tension_y_label_val, ui->m_tension_y_label_box);
    m_potential.setWidgets(ui->m_potential_label, ui->m_potential_label_val, ui->m_potential_label_box);
    m_energy.setWidgets(ui->m_energy_val_label, ui->m_energy_val_label_val, ui->m_energy_val_label_box);

    m_start_pos_x.setWidgets(ui->m_pos_x_start_label, ui->m_pos_x_start_edit, ui->m_pos_x_start_box);
    m_start_pos_y.setWidgets(ui->m_pos_y_start_label, ui->m_pos_y_start_edit, ui->m_pos_y_start_box);
    m_dest_pos_x.setWidgets(ui->m_pos_x_dest_label, ui->m_pos_x_dest_edit, ui->m_pos_x_dest_box);
    m_dest_pos_y.setWidgets(ui->m_pos_y_dest_label, ui->m_pos_y_dest_edit, ui->m_pos_y_dest_box);
    m_charge.setWidgets(ui->m_work_charge_label, ui->m_work_charge_edit, ui->m_work_charge_box);

    m_work.setWidgets(ui->m_work_label, ui->m_work_label_val, ui->m_work_box);

    m_info_charge_q.setWidgets(ui->m_info_charge_q_label, ui->m_info_charge_q_val, ui->m_info_charge_q_box);
    m_info_charge_mass.setWidgets(ui->m_info_charge_mass_label, ui->m_info_charge_mass_val, ui->m_info_charge_mass_box);
    m_info_charge_velocity.setWidgets(ui->m_info_charge_velocity_label, ui->m_info_charge_velocity_val, ui->m_info_charge_velocity_box);
    m_info_charge_velocity_x.setWidgets(ui->m_info_charge_velocity_x_label, ui->m_info_charge_velocity_x_val, ui->m_info_charge_velocity_x_box);
    m_info_charge_velocity_y.setWidgets(ui->m_info_charge_velocity_y_label, ui->m_info_charge_velocity_y_val, ui->m_info_charge_velocity_y_box);
    m_info_charge_acceleration.setWidgets(ui->m_info_charge_acceleration_label, ui->m_info_charge_acceleration_val, ui->m_info_charge_acceleration_box);
    m_info_charge_acceleration_x.setWidgets(ui->m_info_charge_acceleration_x_label, ui->m_info_charge_acceleration_x_val, ui->m_info_charge_acceleration_x_box);
    m_info_charge_acceleration_y.setWidgets(ui->m_info_charge_acceleration_y_label, ui->m_info_charge_acceleration_y_val, ui->m_info_charge_acceleration_y_box);
    m_info_charge_energy.setWidgets(ui->m_info_charge_energy_label, ui->m_info_charge_energy_val, ui->m_info_charge_energy_box);

    m_info_system_sum_kenergy.setWidgets(ui->m_info_system_kenergy_label, ui->m_info_system_kenergy_val, ui->m_info_system_kenergy_box);
    m_info_system_sum_energy.setWidgets(ui->m_info_system_sum_energy_label, ui->m_info_system_sum_energy_val, ui->m_info_system_sum_energy_box);
    m_info_system_whole_energy.setWidgets(ui->m_info_system_whole_energy_label, ui->m_info_system_whole_energy_val, ui->m_info_system_whole_energy_box);

    //widgets register//

    m_id = Translator::addContainer();

    //buttons
    Translator::registerWidget<QPushButton, Words::EDIT_>(m_id, ui->m_edit_button, &QPushButton::setText);
    Translator::registerWidget<QPushButton, Words::PAUSE_>(m_id, ui->m_pause_button, &QPushButton::setText);
    Translator::registerWidget<QPushButton, Words::PLAY_>(m_id, ui->m_play_button, &QPushButton::setText);
    Translator::registerWidget<QPushButton, Words::SPEED>(m_id, ui->m_speed_button, &QPushButton::setText);

    Translator::registerWidget<QPushButton, Words::EDIT_CHARGE>(m_id, ui->m_edit_charge_button, &QPushButton::setText);
    Translator::registerWidget<QPushButton, Words::ADD_CHARGE>(m_id, ui->m_add_charge_button, &QPushButton::setText);
    Translator::registerWidget<QPushButton, Words::REMOVE_CHARGE>(m_id, ui->m_remove_charge_button, &QPushButton::setText);

    //group boxes

    Translator::registerWidget<QGroupBox, Words::CHARGES>(m_id, ui->m_charges_group_box, &QGroupBox::setTitle);
    Translator::registerWidget<QGroupBox, Words::ADDITIONAL>(m_id, ui->m_additional_group_box, &QGroupBox::setTitle);
    Translator::registerWidget<QGroupBox, Words::DESTINATION>(m_id, ui->m_destination_group_box, &QGroupBox::setTitle);
    Translator::registerWidget<QGroupBox, Words::INFO>(m_id, ui->m_info_group_box, &QGroupBox::setTitle);
    Translator::registerWidget<QGroupBox, Words::POSITION>(m_id, ui->m_position_group_box, &QGroupBox::setTitle);
    Translator::registerWidget<QGroupBox, Words::START>(m_id, ui->m_start_group_box, &QGroupBox::setTitle);

    //labels
    Translator::registerWidget<QLabel, Words::CAMERA_AT>(m_id, ui->m_camera_change_label, &QLabel::setText);
    Translator::registerWidget<QLabel, Words::SCALE>(m_id, ui->m_scale_label, &QLabel::setText);
    Translator::registerWidget<QLabel, Words::CHANGE_SCENE>(m_id, ui->m_schange_scene_label, &QLabel::setText);
    Translator::registerWidget<QLabel, Words::CHARGE>(m_id, ui->m_info_charges_label, &QLabel::setText);

    //check boxes
    Translator::registerWidget<QCheckBox, Words::USE_CURSOR_POSITION>(m_id, ui->m_use_cursor_dest, &QCheckBox::setText);
    Translator::registerWidget<QCheckBox, Words::USE_CURSOR_POSITION>(m_id, ui->m_use_cursor_pos_info, &QCheckBox::setText);
    Translator::registerWidget<QCheckBox, Words::USE_CURSOR_POSITION>(m_id, ui->m_use_cursor_start, &QCheckBox::setText);
    Translator::registerWidget<QCheckBox, Words::SHOW_GRID>(m_id, ui->m_show_grid, &QCheckBox::setText);
    Translator::registerWidget<QCheckBox, Words::SHOW_ELECTROSTATIC_FIELD>(m_id, ui->m_show_electro_static_field, &QCheckBox::setText);

    //tabs

    Translator::registerWidget<Words::POSITION_INFO>(0, m_id, ui->m_tab_widget, &QTabWidget::setTabText);
    Translator::registerWidget<Words::WORK>(1, m_id, ui->m_tab_widget, &QTabWidget::setTabText);
    Translator::registerWidget<Words::CHARGE_INFO>(2, m_id, ui->m_tab_widget, &QTabWidget::setTabText);
    Translator::registerWidget<Words::SYSTEM_INFO>(3, m_id, ui->m_tab_widget, &QTabWidget::setTabText);

    //menu
    Translator::registerWidget<QMenu, Words::FILE_>(m_id, ui->menuFile, &QMenu::setTitle);
    Translator::registerWidget<QMenu, Words::OPTIONS>(m_id, ui->menuOptions, &QMenu::setTitle);
    Translator::registerWidget<QMenu, Words::HELP>(m_id, ui->menuHelp, &QMenu::setTitle);
    Translator::registerWidget<QMenu, Words::CREDITS>(m_id, ui->menuCredits, &QMenu::setTitle);
    Translator::registerWidget<QMenu, Words::LANGUAGE>(m_id, ui->menuLanguage, &QMenu::setTitle);

    Translator::registerWidget<QAction, Words::OPEN>(m_id, ui->actionOpen, &QAction::setText);
    Translator::registerWidget<QAction, Words::SAVE>(m_id, ui->actionSave, &QAction::setText);
    Translator::registerWidget<QAction, Words::SAVE_AS>(m_id, ui->actionSave_as, &QAction::setText);
    Translator::registerWidget<QAction, Words::EXIT>(m_id, ui->actionExit, &QAction::setText);
    Translator::registerWidget<QAction, Words::HOW_TO>(m_id, ui->actionHow_To, &QAction::setText);
    Translator::registerWidget<QAction, Words::CREDITS>(m_id, ui->actionAbout_Programm, &QAction::setText);

    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_METRES>(m_id, &m_pos_x, &ValueRepresenter::setMeasure);
    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_METRES>(m_id, &m_pos_y, &ValueRepresenter::setMeasure);

    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_TENSION>(m_id, &m_tension_val, &ValueRepresenter::setMeasure);
    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_TENSION>(m_id, &m_tension_x, &ValueRepresenter::setMeasure);
    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_TENSION>(m_id, &m_tension_y, &ValueRepresenter::setMeasure);
    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_POTENTIAL>(m_id, &m_potential, &ValueRepresenter::setMeasure);
    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_WORK>(m_id, &m_energy, &ValueRepresenter::setMeasure);

    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_METRES>(m_id, &m_start_pos_x, &ValueRepresenter::setMeasure);
    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_METRES>(m_id, &m_start_pos_y, &ValueRepresenter::setMeasure);
    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_METRES>(m_id, &m_dest_pos_x, &ValueRepresenter::setMeasure);
    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_METRES>(m_id, &m_dest_pos_y, &ValueRepresenter::setMeasure);

    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_CHARGE>(m_id, &m_charge, &ValueRepresenter::setMeasure);
    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_WORK>(m_id, &m_work, &ValueRepresenter::setMeasure);
    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_CHARGE>(m_id, &m_info_charge_q, &ValueRepresenter::setMeasure);
    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_MASS>(m_id, &m_info_charge_mass, &ValueRepresenter::setMeasure);

    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_VEL>(m_id, &m_info_charge_velocity, &ValueRepresenter::setMeasure);
    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_VEL>(m_id, &m_info_charge_velocity_x, &ValueRepresenter::setMeasure);
    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_VEL>(m_id, &m_info_charge_velocity_y, &ValueRepresenter::setMeasure);

    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_ACC>(m_id, &m_info_charge_acceleration, &ValueRepresenter::setMeasure);
    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_ACC>(m_id, &m_info_charge_acceleration_x, &ValueRepresenter::setMeasure);
    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_ACC>(m_id, &m_info_charge_acceleration_y, &ValueRepresenter::setMeasure);

    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_WORK>(m_id, &m_info_charge_energy, &ValueRepresenter::setMeasure);
    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_WORK>(m_id, &m_info_system_sum_kenergy, &ValueRepresenter::setMeasure);
    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_WORK>(m_id, &m_info_system_whole_energy, &ValueRepresenter::setMeasure);
    Translator::registerWidget<ValueRepresenter, Words::PHY_VAL_WORK>(m_id, &m_info_system_sum_energy, &ValueRepresenter::setMeasure);

    Translator::setLanguage(Language::EN);

    connect(ui->m_engine, SIGNAL(cursorMoved(const QPoint&)), this, SLOT(cursorMoved(const QPoint&)));
    connect(ui->m_engine, SIGNAL(leftButtonClicked()), this, SLOT(leftButtonClicked()));

    connect(ui->m_use_cursor_pos_info, SIGNAL(stateChanged(int)), this, SLOT(usePosCursor(int)));
    connect(ui->m_use_cursor_start, SIGNAL(stateChanged(int)), this, SLOT(useStartCursor(int)));
    connect(ui->m_use_cursor_dest, SIGNAL(stateChanged(int)), this, SLOT(useDestCursor(int)));

    connect(ui->m_engine, SIGNAL(recountPhysics()), this, SLOT(recountPhysics()));

    connect(ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(open()));
    connect(ui->actionSave, SIGNAL(triggered(bool)), this, SLOT(save()));
    connect(ui->actionSave_as, SIGNAL(triggered(bool)), this, SLOT(saveAs()));
    connect(ui->actionExit, SIGNAL(triggered(bool)), this, SLOT(exit()));

    connect(ui->actionEnglish, SIGNAL(triggered(bool)), this, SLOT(setEnglish()));
    connect(ui->actionRussian, SIGNAL(triggered(bool)), this, SLOT(setRussian()));

    connect(ui->actionAbout_Programm, SIGNAL(triggered(bool)), this, SLOT(about()));
    connect(ui->actionHow_To, SIGNAL(triggered(bool)), this, SLOT(help()));

    setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    Translator::rmContainer(m_id);
    delete ui;
}

void MainWindow::showGrid(int val)
{
    ui->m_engine->setDrawGrid(val == Qt::Checked);
    ui->m_engine->repaint();
}

void MainWindow::showElectroStaticField(int val)
{
    ui->m_engine->setDrawField(val == Qt::Checked);
    ui->m_engine->repaint();
}

void MainWindow::recountPhysics()
{
    Vector v(m_pos_x.value(), m_pos_y.value());
    Vector vStart(m_start_pos_x.value(), m_start_pos_y.value());
    Vector vDest(m_dest_pos_x.value(), m_dest_pos_y.value());
    Vector tension = ui->m_engine->calculateTension(v);
    float potential = ui->m_engine->calculatePotential(v);
    float energy = ui->m_engine->calculateEnergy(v);
    float work = ui->m_engine->calculateWork(vStart, vDest, m_charge.value());
    m_tension_val.setValue(tension.module());
    m_tension_x.setValue(tension.x());
    m_tension_y.setValue(tension.y());
    m_potential.setValue(potential);
    m_energy.setValue(energy);
    m_work.setValue(work);

    if(ui->m_charges_list->currentIndex() >= 0)
    {
      m_info_charge_q.setValue(ui->m_engine->getCharge(ui->m_charges_list->currentIndex())->charge());
      m_info_charge_mass.setValue(ui->m_engine->getCharge(ui->m_charges_list->currentIndex())->mass());
      m_info_charge_velocity.setValue(ui->m_engine->getCharge(ui->m_charges_list->currentIndex())->velocity().module());
      m_info_charge_velocity_x.setValue(ui->m_engine->getCharge(ui->m_charges_list->currentIndex())->velocity().x());
      m_info_charge_velocity_y.setValue(ui->m_engine->getCharge(ui->m_charges_list->currentIndex())->velocity().y());
      m_info_charge_acceleration.setValue(ui->m_engine->getCharge(ui->m_charges_list->currentIndex())->acceleration().module());
      m_info_charge_acceleration_x.setValue(ui->m_engine->getCharge(ui->m_charges_list->currentIndex())->acceleration().x());
      m_info_charge_acceleration_y.setValue(ui->m_engine->getCharge(ui->m_charges_list->currentIndex())->acceleration().y());
      m_info_charge_energy.setValue(ui->m_engine->calculateKineticEnergy(ui->m_charges_list->currentIndex()));
    }

    m_info_system_sum_kenergy.setValue(ui->m_engine->calculateKineticEnergyOfSystem());
    m_info_system_sum_energy.setValue(ui->m_engine->calculateEnergyOfSystem());
    m_info_system_whole_energy.setValue(ui->m_engine->calculateKineticEnergyOfSystem() + ui->m_engine->calculateEnergyOfSystem());

}

void MainWindow::addCharge()
{
    CreateChargeDialog d(ui->m_engine->chargeNames(), this);
    EngineState e = ui->m_engine->engineState();
    ui->m_engine->setEngineState(EngineState::PAUSE);

    if(d.exec() == QDialog::Accepted)
    {
        ui->m_engine->addCharge(std::unique_ptr<Charge>(new Charge(d.name(), d.charge(), d.mass(), d.pos(), d.vel(), d.is_ignored(), d.is_movable(), ui->m_engine)));
        resetCameraChange();
        resetChargeInfoList();
    }

    ui->m_engine->setEngineState(e);
    repaint();
}

void MainWindow::editCharge()
{
    if(ui->m_engine->hasCharges())
    {
        EngineState e = ui->m_engine->engineState();
        ui->m_engine->setEngineState(EngineState::PAUSE);
        SelectCharge d(ui->m_engine->chargeNames(), this);

        if(d.exec() == QDialog::Accepted)
        {
            QStringList names = ui->m_engine->chargeNames();
            names.removeAt(d.getSelected());
            CreateChargeDialog d1(names, this);

            d1.setName(ui->m_engine->getCharge(d.getSelected())->name());
            d1.setPos(ui->m_engine->getCharge(d.getSelected())->pos());
            d1.setVel(ui->m_engine->getCharge(d.getSelected())->velocity());
            d1.setMass(ui->m_engine->getCharge(d.getSelected())->mass());
            d1.setCharge(ui->m_engine->getCharge(d.getSelected())->charge());
            d1.setIgnored(ui->m_engine->getCharge(d.getSelected())->is_ignored());
            d1.setMovable(ui->m_engine->getCharge(d.getSelected())->is_movable());

            if(d1.exec() == QDialog::Accepted)
            {
                ui->m_engine->rmCharge(d.getSelected());
                ui->m_engine->addCharge(std::unique_ptr<Charge>(new Charge(d1.name(), d1.charge(), d1.mass(), d1.pos(), d1.vel(), d1.is_ignored(), d1.is_movable(), ui->m_engine)));
                recountPhysics();
            }
        }

        ui->m_engine->setEngineState(e);
    }
    repaint();
}

//void MainWindow::ignoreCharges()
//{
//    if(ui->m_engine->hasCharges())
//    {
//        EngineState e = ui->m_engine->engineState();
//        ui->m_engine->setEngineState(EngineState::PAUSE);
//        IgnoreChargesDialog d(ui->m_engine->chargeNames(), this);

//        if(d.exec() == QDialog::Accepted)
//        {
//            recountPhysics();
//        }

//        ui->m_engine->setEngineState(e);
//    }
//}

void MainWindow::rmCharge()
{
    if(ui->m_engine->hasCharges())
    {
        EngineState e = ui->m_engine->engineState();
        ui->m_engine->setEngineState(EngineState::PAUSE);
        SelectCharge d(ui->m_engine->chargeNames(), this);

        if(d.exec() == QDialog::Accepted)
        {
            ui->m_engine->rmCharge(d.getSelected());
            resetCameraChange();
            resetChargeInfoList();
            recountPhysics();
        }

        ui->m_engine->setEngineState(e);
    }
    repaint();
}

void MainWindow::resetCameraChange()
{
    ui->m_camera_change->clear();
    if(ui->m_engine->hasCharges())
    {
        ui->m_camera_change->addItems(ui->m_engine->chargeNames());
    }
}

void MainWindow::resetChargeInfoList()
{
    ui->m_charges_list->clear();
    if(ui->m_engine->hasCharges())
    {
       ui->m_charges_list->addItems(ui->m_engine->chargeNames());
    }
}


void MainWindow::open()
{
    QString selected = QFileDialog::getOpenFileName(this, "Open XML", "", tr("XML Files (*.xml)"));
    if(selected == "")
    {
        return;
    }

    QFile file(selected);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Error: Cannot read file";
        return;
    }

    filename = selected;
    ui->m_engine->clearCharges();

    QXmlStreamReader Rxml;

    Rxml.setDevice(&file);
    Rxml.readNext();

    Charge chargeObject(ui->m_engine);
    size_t size = 0;
    QString name = "default";
    bool is_ignored = false;
    bool is_movable = false;
    double charge = 0;
    double mass;
    double xPos;
    double yPos;
    double xVel;
    double yVel;
    Vector vectorPos;
    Vector vectorVel = Vector(0, 0);

    while (!Rxml.atEnd()) {
        if (Rxml.isStartElement()) {
            if (Rxml.name() == "Charges") {
                qDebug() << "CHARGES: ";
            }

            else if (Rxml.name() == "Charge") {
                size++;
                while (!Rxml.atEnd()) {
                    if (Rxml.isEndElement()) {
                        Rxml.readNext();
                        break;
                    }
                    else if (Rxml.isCharacters()) {
                        Rxml.readNext();
                    }
                    else if (Rxml.isStartElement()) {
                        if (Rxml.name() == "name") {
                            name = Rxml.readElementText();
                        }
                        else if (Rxml.name() == "is_ignored") {
                            is_ignored = (Rxml.readElementText() == "true");
                        }
                        else if (Rxml.name() == "is_movable") {
                            is_movable = (Rxml.readElementText() == "true");
                        }
                        else if (Rxml.name() == "charge") {
                            charge = Rxml.readElementText().toDouble();
                        }
                        else if (Rxml.name() == "mass") {
                            mass = Rxml.readElementText().toDouble();
                        }

                        else if (Rxml.name() == "pos") {
                            while (!Rxml.atEnd()) {
                                if (Rxml.isEndElement()) {
                                    Rxml.readNext();
                                    break;
                                }

                                else if (Rxml.isCharacters()) {
                                    Rxml.readNext();
                                }

                                else if (Rxml.isStartElement()) {
                                    if (Rxml.name() == "x") {
                                        xPos = Rxml.readElementText().toDouble();
                                        qDebug() << "x: " << xPos;
                                    }
                                    else if (Rxml.name() == "y") {
                                        yPos = Rxml.readElementText().toDouble();
                                        qDebug() << "y: " << yPos;
                                    }
                                    Rxml.readNext();
                                }
                                else {
                                    Rxml.readNext();
                                }
                            }
                        }

                        else if (Rxml.name() == "vel") {
                            while (!Rxml.atEnd()) {
                                if (Rxml.isEndElement()) {
                                    Rxml.readNext();
                                    break;
                                }

                                else if (Rxml.isCharacters()) {
                                    Rxml.readNext();
                                }

                                else if (Rxml.isStartElement()) {
                                    if (Rxml.name() == "x") {
                                        xVel = Rxml.readElementText().toDouble();
                                    }
                                    else if (Rxml.name() == "y") {
                                        yVel = Rxml.readElementText().toDouble();
                                    }
                                    Rxml.readNext();
                                }
                                else {
                                    Rxml.readNext();
                                }
                            }
                        }

                        vectorPos = Vector(xPos, yPos);
                        vectorVel = Vector(xVel, yVel);

                        Rxml.readNext();
                    }
                    else {
                        Rxml.readNext();
                    }
                }
                if (name == "") {
                    name = "Charge " + QString::number(size);
                }
                if (mass <= 0) {
                    mass = 1;
                }

                qDebug() << "charge: " << charge;
                ui->m_engine->addCharge(std::unique_ptr<Charge>(new Charge(name, charge, mass, vectorPos,
                                                                           vectorVel, is_ignored, is_movable, ui->m_engine)));
            }
        }
        Rxml.readNext();
    }

    qDebug() << "end";
    file.close();
}

void MainWindow::save()
{
    if (filename == "") {
        saveAsMethod();
    }

    else {
        QFile file(filename);
        if (!file.open(QFile::WriteOnly | QFile::Text))
        {
            qDebug() << "Error saving XML file.";
            file.close();
            return;
        }
        file.open(QIODevice::WriteOnly);

        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();


        xmlWriter.writeStartElement("Charges");

        for (size_t i = 0; i < ui->m_engine->chargesNum(); i++) {
            xmlWriter.writeStartElement("Charge");

            xmlWriter.writeTextElement("name", ui->m_engine->getCharge(i)->name());

            xmlWriter.writeTextElement("is_ignored", ui->m_engine->getCharge(i)->is_ignored() ? "true" : "false");
            xmlWriter.writeTextElement("is_movable", ui->m_engine->getCharge(i)->is_movable() ? "true" : "false");

            xmlWriter.writeTextElement("charge", QString::number(ui->m_engine->getCharge(i)->charge()));
            xmlWriter.writeTextElement("mass", QString::number(ui->m_engine->getCharge(i)->mass()));


            Vector pos = ui->m_engine->getCharge(i)->pos();
            xmlWriter.writeStartElement("pos");
            xmlWriter.writeTextElement("x", QString::number(pos.x()));
            xmlWriter.writeTextElement("y", QString::number(pos.y()));
            xmlWriter.writeEndElement();

            Vector vel = ui->m_engine->getCharge(i)->velocity();
            xmlWriter.writeStartElement("vel");
            xmlWriter.writeTextElement("x", QString::number(vel.x()));
            xmlWriter.writeTextElement("y", QString::number(vel.y()));
            xmlWriter.writeEndElement();

            Vector acc = ui->m_engine->getCharge(i)->acceleration();
            xmlWriter.writeStartElement("acc");
            xmlWriter.writeTextElement("x", QString::number(acc.x()));
            xmlWriter.writeTextElement("y", QString::number(acc.y()));
            xmlWriter.writeEndElement();

            xmlWriter.writeEndElement();
        }

        xmlWriter.writeEndElement();

        file.close();
    }
}

void MainWindow::saveAs()
{
    saveAsMethod();
}

void MainWindow::saveAsMethod()
{
    QString selected = QFileDialog::getSaveFileName(this, "", "", "");
    if(selected == "")
    {
        return;
    }

    QFile file(selected);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "Error saving XML file.";
        file.close();
        return;
    }
    filename = selected;
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();


    xmlWriter.writeStartElement("Charges");

    for (size_t i = 0; i < ui->m_engine->chargesNum(); i++) {
        xmlWriter.writeStartElement("Charge");

        xmlWriter.writeTextElement("name", ui->m_engine->getCharge(i)->name());

        xmlWriter.writeTextElement("is_ignored", ui->m_engine->getCharge(i)->is_ignored() ? "true" : "false");
        xmlWriter.writeTextElement("is_movable", ui->m_engine->getCharge(i)->is_movable() ? "true" : "false");

        xmlWriter.writeTextElement("charge", QString::number(ui->m_engine->getCharge(i)->charge()));
        xmlWriter.writeTextElement("mass", QString::number(ui->m_engine->getCharge(i)->mass()));


        Vector pos = ui->m_engine->getCharge(i)->pos();
        xmlWriter.writeStartElement("pos");
        xmlWriter.writeTextElement("x", QString::number(pos.x()));
        xmlWriter.writeTextElement("y", QString::number(pos.y()));
        xmlWriter.writeEndElement();

        Vector vel = ui->m_engine->getCharge(i)->velocity();
        xmlWriter.writeStartElement("vel");
        xmlWriter.writeTextElement("x", QString::number(vel.x()));
        xmlWriter.writeTextElement("y", QString::number(vel.y()));
        xmlWriter.writeEndElement();

        Vector acc = ui->m_engine->getCharge(i)->acceleration();
        xmlWriter.writeStartElement("acc");
        xmlWriter.writeTextElement("x", QString::number(acc.x()));
        xmlWriter.writeTextElement("y", QString::number(acc.y()));
        xmlWriter.writeEndElement();

        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();

    file.close();
}

void MainWindow::exit()
{
    close();
}

void MainWindow::help() {
    EngineState e = ui->m_engine->engineState();
    ui->m_engine->setEngineState(EngineState::PAUSE);
    if (Translator::currentLang() == EN) {
        Help_eng d(this);
        d.exec();
    }
    else {
      Help d(this);
      d.exec();
    }

    ui->m_engine->setEngineState(e);
}

void MainWindow::about() {
    EngineState e = ui->m_engine->engineState();
    ui->m_engine->setEngineState(EngineState::PAUSE);
    About d(this);
    d.exec();
    ui->m_engine->setEngineState(e);
}

void MainWindow::setEnglish()
{
  Translator::setLanguage(EN);
}

void MainWindow::setRussian()
{
  Translator::setLanguage(RUS);
}

void MainWindow::play()
{
    ui->m_engine->setEngineState(EngineState::PLAY);
}

void MainWindow::pause()
{
    ui->m_engine->setEngineState(EngineState::PAUSE);
}

void MainWindow::speed_x_2()
{
    ui->m_engine->setEngineState(EngineState::SPEED_2);
}

void MainWindow::edit()
{
    ui->m_engine->setEngineState(EngineState::EDIT);
}

void MainWindow::usePosCursor(int val)
{
    m_pos_x.setDisabled(val == Qt::Checked);
    m_pos_y.setDisabled(val == Qt::Checked);

    if(val == Qt::Checked)
    {
      ui->m_engine->setCursor(Qt::CrossCursor);

      if(ui->m_use_cursor_dest->isChecked()) {
          ui->m_use_cursor_dest->setChecked(false);
      }

      if(ui->m_use_cursor_start->isChecked()) {
          ui->m_use_cursor_start->setChecked(false);
      }
    }
    else
    {
        if(!ui->m_use_cursor_dest->isChecked() && !ui->m_use_cursor_start->isChecked())
        {
           ui->m_engine->setCursor(Qt::ArrowCursor);
        }
    }
}

void MainWindow::useStartCursor(int val)
{
    m_start_pos_x.setDisabled(val == Qt::Checked);
    m_start_pos_y.setDisabled(val == Qt::Checked);

    if(val == Qt::Checked)
    {
      ui->m_engine->setCursor(Qt::CrossCursor);

      if(ui->m_use_cursor_dest->isChecked()) {
          ui->m_use_cursor_dest->setChecked(false);
      }

      if(ui->m_use_cursor_pos_info->isChecked()) {
          ui->m_use_cursor_pos_info->setChecked(false);
      }
    }
    else
    {
        if(!ui->m_use_cursor_dest->isChecked() && !ui->m_use_cursor_pos_info->isChecked())
        {
           ui->m_engine->setCursor(Qt::ArrowCursor);
        }
    }
}

void MainWindow::useDestCursor(int val)
{
    m_dest_pos_x.setDisabled(val == Qt::Checked);
    m_dest_pos_y.setDisabled(val == Qt::Checked);

    if(val == Qt::Checked)
    {
      ui->m_engine->setCursor(Qt::CrossCursor);

      if(ui->m_use_cursor_pos_info->isChecked()) {
          ui->m_use_cursor_pos_info->setChecked(false);
      }

      if(ui->m_use_cursor_start->isChecked()) {
          ui->m_use_cursor_start->setChecked(false);
      }
    }
    else
    {
        if(!ui->m_use_cursor_pos_info->isChecked() && !ui->m_use_cursor_start->isChecked())
        {
           ui->m_engine->setCursor(Qt::ArrowCursor);
        }
    }
}

void MainWindow::cursorMoved(const QPoint& pos)
{
    Vector v = ui->m_engine->toXOY(pos);

    if(ui->m_use_cursor_pos_info->isChecked())
    {
        m_pos_x.setValue(v.x());
        m_pos_y.setValue(v.y());
    }

    if(ui->m_use_cursor_start->isChecked())
    {
        m_start_pos_x.setValue(v.x());
        m_start_pos_y.setValue(v.y());
    }

    if(ui->m_use_cursor_dest->isChecked())
    {
        m_dest_pos_x.setValue(v.x());
        m_dest_pos_y.setValue(v.y());
    }

    recountPhysics();
}

void MainWindow::leftButtonClicked()
{
    if(ui->m_use_cursor_pos_info->isChecked())
    {
        ui->m_use_cursor_pos_info->setChecked(false);
        ui->m_engine->setCursor(Qt::ArrowCursor);
    }

    if(ui->m_use_cursor_start->isChecked())
    {
        ui->m_use_cursor_start->setChecked(false);
        ui->m_engine->setCursor(Qt::ArrowCursor);
    }

    if(ui->m_use_cursor_dest->isChecked())
    {
        ui->m_use_cursor_dest->setChecked(false);
        ui->m_engine->setCursor(Qt::ArrowCursor);
    }
}

void MainWindow::scaleChanged(int indx)
{
    ui->m_engine->setLambda(0.1f * pow(10, -12 + 3 * indx));
    repaint();
}
