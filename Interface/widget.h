#ifndef WIDGET_H
#define WIDGET_H

#include "Interface/enginewidget.h"
#include "Interface/ValueRepresener/valueedit.h"
#include "Interface/ValueRepresener/valuewriter.h"

#include <QWidget>
#include <QCheckBox>
#include <QComboBox>

class Widget : public QWidget
{
    Q_OBJECT

    EngineWidget* m_engine;

    QCheckBox* m_tension_use_cursor;
    ValueEdit* m_tension_pos_x;
    ValueEdit* m_tension_pos_y;

    ValueWriter* m_tension_val;
    ValueWriter* m_tension_val_x;
    ValueWriter* m_tension_val_y;

    QCheckBox* m_potential_use_cursor;
    ValueEdit* m_potential_pos_x;
    ValueEdit* m_potential_pos_y;

    ValueWriter* m_potential_val;

    QComboBox* m_camera_change;

    bool m_use_cursor;


public:
    explicit Widget(QWidget *parent = nullptr);
    virtual ~Widget();

signals:

public slots:
    void play();
    void stop();
    void speed_x_2();
    void edit();

    void addCharge();
    void editCharge();
    void ignoreCharge();
    void rmCharge();

    void showGrid(int);
    void showElectrostaticField(int);

    void calculateTension();
    void calculateTension(float x, float y);
    void calculateTensionByMouse(const QPoint&);
    void calculatePotential();
    void calculatePotential(float x, float y);
    void calculatePotentialByMouse(const QPoint&);

    void scaleChanged(int);

    void changeCamera(int);
    void changeScene(int);

    void useCursorPosition(int);
};

#endif // WIDGET_H
