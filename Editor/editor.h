#ifndef EDITOR_H
#define EDITOR_H

#include "Interface/plotgridwidget.h"
#include "Editor/mediator.h"

#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>

#include <QWidget>

class Object;

class Editor : public PlotGridWidget
{
    Q_OBJECT

    bool m_has_object_selected;
    QPoint m_prev_pos;

    ChargeEdit* m_current_charge_selected;

    Mediator m_mediator;
    std::vector<std::shared_ptr<Object>> m_objects;

public:
    explicit Editor(QWidget *parent = nullptr);
    virtual ~Editor();

    virtual void paintEvent(QPaintEvent*) override;
    virtual void mousePressEvent(QMouseEvent*) override;
    virtual void mouseMoveEvent(QMouseEvent*) override;
    virtual void mouseReleaseEvent(QMouseEvent*) override;

    virtual void keyPressEvent(QKeyEvent*) override;

    void addObject(const std::shared_ptr<Object>&);
    void rmObject(const std::shared_ptr<Object>&);
    void rmObject(Object*);

    void bind(Arrow*, ChargeEdit*);
    Arrow* get(ChargeEdit*);
    ChargeEdit* get(Arrow*);
    void rm(Arrow*);
    void rm(ChargeEdit*);

public slots:
    void menuOpened();
    void initialVelocity();
    void rmInitialVelocity();

private:
    void drawSelectingRect(QPainter&);
    void showContexMenu(const QPoint&);
};

#endif // EDITOR_H
