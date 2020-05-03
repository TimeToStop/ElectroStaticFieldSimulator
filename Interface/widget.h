#ifndef WIDGET_H
#define WIDGET_H

#include "Interface/enginewidget.h"
#include "Interface/ValueRepresenter/valueedit.h"
#include "Interface/ValueRepresenter/valuewriter.h"

#include <QMainWindow>
#include <QCheckBox>
#include <QComboBox>
#include <QToolBar>
#include <QMenuBar>
#include <QMenu>

class Widget : public QMainWindow
{
    Q_OBJECT

    bool m_use_cursor;

    QMenuBar* m_tool_bar;
    EngineWidget* m_engine;

    QCheckBox* m_check_use_cursor;
    ValueEdit* m_pos_x;
    ValueEdit* m_pos_y;

    ValueWriter* m_tension_val;
    ValueWriter* m_tension_val_x;
    ValueWriter* m_tension_val_y;
    ValueWriter* m_potential_val;
    ValueWriter* m_energy_of_pos;

    ValueWriter* m_energy_of_system;
    ValueWriter* m_kinetic_energy;

    QComboBox* m_camera_change;

public:
    explicit Widget(QWidget *parent = nullptr);
    virtual ~Widget();

signals:

public slots:
    void play();
    void stop();
    void speed_x_2();
    void edit();

    void toolBarFile();
    void toolBarOptions();
    void toolBarHelp();
    void toolBarCredits();

    void addCharge();
    void editCharge();
    void ignoreCharge();
    void rmCharge();

    void showGrid(int);
    void showElectrostaticField(int);

//    void calculateTension();
//    void calculateTension(float x, float y);
//    void calculateTensionByMouse(const QPoint&);
//    void calculatePotential();
//    void calculatePotential(float x, float y);
//    void calculatePotentialByMouse(const QPoint&);

    void scaleChanged(int);

    void changeCamera(int);
    void changeScene(int);

    void useCursorPosition(int);
    void cursorMoved(const QPoint&);
    void stopUsingCursor();
    void recountPhysics();
};

#endif // WIDGET_H
