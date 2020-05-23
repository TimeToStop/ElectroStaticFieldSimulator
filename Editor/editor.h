#ifndef EDITOR_H
#define EDITOR_H

#include "Editor/object.h"
#include "Interface/plotgridwidget.h"

#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>

#include <QWidget>

class Editor : public PlotGridWidget
{
    Q_OBJECT

    std::vector<std::unique_ptr<Object>> m_objects;

public:
    explicit Editor(QWidget *parent = nullptr);
    virtual ~Editor();

    virtual void paintEvent(QPaintEvent*) override;
    virtual void mousePressEvent(QMouseEvent*) override;
    virtual void mouseMoveEvent(QMouseEvent*) override;
    virtual void mouseReleaseEvent(QMouseEvent*) override;

signals:

};

#endif // EDITOR_H
