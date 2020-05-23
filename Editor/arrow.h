#ifndef ARROW_H
#define ARROW_H

#include "Editor/object.h"

enum class ArrowColor
{
    RED,
    BLUE
};

class Arrow : public Object
{
    ArrowColor m_color;
    QPoint m_to;

public:
    Arrow(ArrowColor, PlotGridWidget* const);
    virtual ~Arrow();

    virtual void draw(QPainter&) const override;
    virtual bool isClose(const QPoint&) override;
    virtual bool intersects(const QRect&) const override;

    void setDest(const QPoint&);
};

#endif // ARROW_H
