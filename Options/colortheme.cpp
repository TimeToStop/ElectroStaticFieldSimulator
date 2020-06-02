#include "Options/colortheme.h"

ColorTheme::ColorTheme()
{
    color.setColor(QPalette::Window, QColor(248, 248, 248));
    color.setColor(QPalette::WindowText, Qt::black);
    color.setColor(QPalette::Base, QColor(248, 243, 240));
    color.setColor(QPalette::AlternateBase, QColor(100, 53, 53));
    color.setColor(QPalette::ToolTipBase, Qt::black);
    color.setColor(QPalette::ToolTipText, Qt::black);
    color.setColor(QPalette::Text, Qt::black);
    color.setColor(QPalette::Button, QColor(248, 243, 240));
    color.setColor(QPalette::ButtonText, Qt::black);
    color.setColor(QPalette::BrightText, Qt::red);
    color.setColor(QPalette::Link, QColor(42, 130, 218));
    color.setColor(QPalette::Highlight, QColor(140, 140, 140));
    color.setColor(QPalette::HighlightedText, Qt::white);
}

ColorTheme::~ColorTheme() {}

QPalette ColorTheme::pallete()
{
    return color;
}
