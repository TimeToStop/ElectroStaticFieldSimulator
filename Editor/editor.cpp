#include "editor.h"

Editor::Editor(QWidget* parent):
    PlotGridWidget(parent)
{
}

Editor::~Editor()
{

}

void Editor::paintEvent(QPaintEvent * e)
{
    PlotGridWidget::paintEvent(e);
    QPainter painter(this);

    for(std::unique_ptr<Object>& obj : m_objects)
    {
        obj->draw(painter);
    }
}

void Editor::mousePressEvent(QMouseEvent * e)
{
    PlotGridWidget::mousePressEvent(e);
}

void Editor::mouseMoveEvent(QMouseEvent * e)
{
    PlotGridWidget::mouseMoveEvent(e);
}

void Editor::mouseReleaseEvent(QMouseEvent * e)
{
    PlotGridWidget::mouseReleaseEvent(e);
}
