#ifndef EDITOR_H
#define EDITOR_H

#include "Editor/object.h"
#include "Editor/chargeedit.h"
#include "Editor/arrow.h"

#include "Editor/mediator.h"
#include "Interface/plotgridwidget.h"

#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>

#include <QWidget>

class Editor : public PlotGridWidget
{
    Q_OBJECT

    bool m_has_object_selected;
    QPoint m_prev_pos;

    Mediator m_mediator;
    std::vector<std::shared_ptr<Object>> m_objects;

public:
    explicit Editor(QWidget *parent = nullptr);
    virtual ~Editor();

    virtual void paintEvent(QPaintEvent*) override;
    virtual void mousePressEvent(QMouseEvent*) override;
    virtual void mouseMoveEvent(QMouseEvent*) override;
    virtual void mouseReleaseEvent(QMouseEvent*) override;

    void addCharge(const std::shared_ptr<ChargeEdit>&);
    void addArrow(const std::shared_ptr<Arrow>&);

    std::shared_ptr<Arrow> get(std::shared_ptr<ChargeEdit>);

private:
    void drawSelectingRect(QPainter&);
};

#endif // EDITOR_H
