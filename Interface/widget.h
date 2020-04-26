#ifndef WIDGET_H
#define WIDGET_H

#include "Interface/enginewidget.h"
#include "Interface/valuerepresent.h"

#include <QWidget>
#include <QCheckBox>
#include <QComboBox>

class Widget : public QWidget
{
    Q_OBJECT

    EngineWidget* m_engine;

    QCheckBox* m_tension_use_cursor;
    ValueRepresent* m_tension_pos_x;
    ValueRepresent* m_tension_pos_y;

    ValueRepresent* m_tension_val;
    ValueRepresent* m_tension_val_x;
    ValueRepresent* m_tension_val_y;

    QCheckBox* m_potential_use_cursor;
    ValueRepresent* m_potential_pos_x;
    ValueRepresent* m_potential_pos_y;

    ValueRepresent* m_potential_val;

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

    void addCharge();
    void editCharge();
    void ignoreCharge();
    void rmCharge();

    void showGrid(int);
    void showTension(int);

    void scaleChanged(int);

    void changeCamera(int);
    void changeScene(int);

    void useCursorPosition(int);
};

#endif // WIDGET_H
