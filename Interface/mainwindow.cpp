#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Interface/Charge/createchargedialog.h"
#include "Interface/Charge/ignorechargesdialog.h"
#include "Interface/Charge/selectcharge.h"
#include "Interface/help.h"
#include "about.h"
#include "Engine/charge.h"

#include "Options/translator.h"
#include "Options/colortheme.h"

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
    m_info_charge_mass("Mass", "кг"),
    m_info_charge_speed("Speed", "м/c"),
    m_info_charge_acceleration("Acceleration", "м/с^2"),
    m_info_charge_energy("Energy", "Дж"),
    m_info_system_sum_kenergy("Sum Ek", "Дж"),
    m_info_system_sum_energy("Sum W", "Дж"),
    m_info_system_whole_energy("W system", "Дж"),
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
    m_info_charge_speed.setWidgets(ui->m_info_charge_speed_label, ui->m_info_charge_speed_val, ui->m_info_charge_speed_box);
    m_info_charge_acceleration.setWidgets(ui->m_info_acceleration_label, ui->m_info_charge_acceleration_val, ui->m_info_charge_acceleration_box);
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
    Translator::registerWidget<QPushButton, Words::IGNORE_CHARGE>(m_id, ui->m_ignore_charge_button, &QPushButton::setText);
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

    //check boxes
    Translator::registerWidget<QCheckBox, Words::USE_CURSOR_POSITION>(m_id, ui->m_use_cursor_dest, &QCheckBox::setText);
    Translator::registerWidget<QCheckBox, Words::USE_CURSOR_POSITION>(m_id, ui->m_use_cursor_pos_info, &QCheckBox::setText);
    Translator::registerWidget<QCheckBox, Words::USE_CURSOR_POSITION>(m_id, ui->m_use_cursor_start, &QCheckBox::setText);
    Translator::registerWidget<QCheckBox, Words::SHOW_GRID>(m_id, ui->m_show_grid, &QCheckBox::setText);
    Translator::registerWidget<QCheckBox, Words::SHOW_ELECTROSTATIC_FIELD>(m_id, ui->m_show_electro_static_field, &QCheckBox::setText);

    //tabs

    Translator::registerWidget<Words::POSITION_INFO>(0, m_id, ui->m_tab_widget, &QTabWidget::setTabText);
    Translator::registerWidget<Words::WORK>(1, m_id, ui->m_tab_widget, &QTabWidget::setTabText);

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
    Translator::registerWidget<QAction, Words::ENGLISH>(m_id, ui->actionEnglish, &QAction::setText);
    Translator::registerWidget<QAction, Words::RUSSIAN>(m_id, ui->actionRussian, &QAction::setText);
    Translator::registerWidget<QAction, Words::HOW_TO>(m_id, ui->actionHow_To, &QAction::setText);

    Translator::setLanguage();


  //  ui->m_tab_widget->setTabText(0, Translator::Dict<POSITION_INFO>(lang));
  //  ui->m_tab_widget->setTabText(1, Translator::Dict<WORK>(lang));

    connect(ui->m_engine, SIGNAL(cursorMoved(const QPoint&)), this, SLOT(cursorMoved(const QPoint&)));
    connect(ui->m_engine, SIGNAL(leftButtonClicked()), this, SLOT(leftButtonClicked()));

    connect(ui->m_use_cursor_pos_info, SIGNAL(stateChanged(int)), this, SLOT(usePosCursor(int)));
    connect(ui->m_use_cursor_start, SIGNAL(stateChanged(int)), this, SLOT(useStartCursor(int)));
    connect(ui->m_use_cursor_dest, SIGNAL(stateChanged(int)), this, SLOT(useDestCursor(int)));

    connect(ui->m_engine, SIGNAL(recountPhysics()), this, SLOT(recountPhysics()));

    connect(ui->actionEnglish, SIGNAL(triggered(bool)), this, SLOT(setEnglish()));
    connect(ui->actionRussian, SIGNAL(triggered(bool)), this, SLOT(setRussian()));

    connect(ui->actionDark, SIGNAL(triggered(bool)), this, SLOT(setDarkTheme()));
    connect(ui->actionLight, SIGNAL(triggered(bool)), this, SLOT(setLightTheme()));

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
      m_info_charge_speed.setValue(ui->m_engine->getCharge(ui->m_charges_list->currentIndex())->velocity().module());
      m_info_charge_acceleration.setValue(ui->m_engine->getCharge(ui->m_charges_list->currentIndex())->acceleration().module());
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
}

void MainWindow::ignoreCharges()
{
    if(ui->m_engine->hasCharges())
    {
        EngineState e = ui->m_engine->engineState();
        ui->m_engine->setEngineState(EngineState::PAUSE);
        IgnoreChargesDialog d(ui->m_engine->chargeNames(), this);

        if(d.exec() == QDialog::Accepted)
        {
            recountPhysics();
        }

        ui->m_engine->setEngineState(e);
    }
}

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
}

void MainWindow::resetCameraChange() {
    ui->m_camera_change->clear();
    if(ui->m_engine->hasCharges()){
        ui->m_camera_change->addItems(ui->m_engine->chargeNames());
    }
}

void MainWindow::resetChargeInfoList() {
    ui->m_charges_list->clear();
    if(ui->m_engine->hasCharges()) {
       ui->m_charges_list->addItems(ui->m_engine->chargeNames());
    }
}

void MainWindow::help() {
    EngineState e = ui->m_engine->engineState();
    ui->m_engine->setEngineState(EngineState::PAUSE);
    Help d(this);
    d.exec();
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

void MainWindow::changeLanguage()
{
    //////////MAIN WIDGET/////////



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


