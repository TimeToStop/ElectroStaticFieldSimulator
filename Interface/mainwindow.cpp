#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Interface/Charge/createchargedialog.h"
#include "Interface/Charge/ignorecharge.h"
#include "Interface/Charge/selectcharge.h"
#include "Engine/charge.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
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
}

MainWindow::~MainWindow()
{
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

}

void MainWindow::addCharge()
{
    CreateChargeDialog d(ui->m_engine->chargeNames(), this);
    EngineState e = ui->m_engine->engineState();
    ui->m_engine->setEngineState(EngineState::PAUSE);

    if(d.exec() == QDialog::Accepted)
    {
        ui->m_engine->addCharge(std::unique_ptr<Charge>(new Charge(d.name(), d.charge(), d.mass(), d.pos(), d.vel(), d.is_ignored(), d.is_movable(), ui->m_engine)));
        ui->m_camera_change->addItem(d.name());
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
        IgnoreCharge d(ui->m_engine->chargeNames(), this);

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
            ui->m_camera_change->removeItem(d.getSelected() + 1);
            recountPhysics();
        }

        ui->m_engine->setEngineState(e);
    }
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
