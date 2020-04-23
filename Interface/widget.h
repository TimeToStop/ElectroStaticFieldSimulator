#ifndef WIDGET_H
#define WIDGET_H

#include "Engine/engine.h"
#include "Interface/valuerepresent.h"

#include <QWidget>
#include <QCheckBox>

class Widget : public QWidget
{
    Q_OBJECT

    Engine* m_engine;

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

public:
    explicit Widget(QWidget *parent = nullptr);
    virtual ~Widget();

signals:

public slots:
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
