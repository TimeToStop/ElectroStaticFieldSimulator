#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Interface/ValueRepresenter/valueedit.h"
#include "Interface/ValueRepresenter/valuewriter.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow: public QMainWindow
{
    Q_OBJECT

    bool m_use_cursor;

    int m_id;
    QString filename;

    ValueEdit m_pos_x;
    ValueEdit m_pos_y;

    ValueWriter m_tension_val;
    ValueWriter m_tension_x;
    ValueWriter m_tension_y;
    ValueWriter m_potential;
    ValueWriter m_energy;

    ValueEdit m_start_pos_x;
    ValueEdit m_start_pos_y;
    ValueEdit m_dest_pos_x;
    ValueEdit m_dest_pos_y;
    ValueEdit m_charge;

    ValueWriter m_work;

    ValueWriter m_info_charge_q;
    ValueWriter m_info_charge_mass;
    ValueWriter m_info_charge_velocity;
    ValueWriter m_info_charge_velocity_x;
    ValueWriter m_info_charge_velocity_y;
    ValueWriter m_info_charge_energy;
    ValueWriter m_info_charge_acceleration;
    ValueWriter m_info_charge_acceleration_x;
    ValueWriter m_info_charge_acceleration_y;


    ValueWriter m_info_system_sum_kenergy;
    ValueWriter m_info_system_sum_energy;
    ValueWriter m_info_system_whole_energy;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    // Buttons for edit charges
    void addCharge();
    void editCharge();
    void rmCharge();

    // CheckBox control
    void showGrid(int);
    void showElectroStaticField(int);

    // Main slot for update phisics values
    void recountPhysics();

    void resetCameraChange();
    void resetChargeInfoList();

    // Main menu
    void open();
    void save();
    void saveAs();
    void saveAsMethod();
    void exit();

    void help();
    void about();

    void setRussian();
    void setEnglish();
    void changeLanguage();

    void play();
    void pause();
    void speed_x_2();
    void edit();

    void usePosCursor(int);
    void useStartCursor(int);
    void useDestCursor(int);

    void cursorMoved(const QPoint&);
    void leftButtonClicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
