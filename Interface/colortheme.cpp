#include "Interface/colortheme.h"

ColorTheme::ColorTheme() {
    palette.setColor(QPalette::Window, QColor(238, 233, 230));
    palette.setColor(QPalette::WindowText, Qt::black);
    palette.setColor(QPalette::Base, QColor(248, 243, 240));
    palette.setColor(QPalette::AlternateBase, QColor(100, 53, 53));
    palette.setColor(QPalette::ToolTipBase, Qt::black);
    palette.setColor(QPalette::ToolTipText, Qt::black);
    palette.setColor(QPalette::Text, Qt::black);
    palette.setColor(QPalette::Button, QColor(255, 243, 240));
    palette.setColor(QPalette::ButtonText, Qt::black);
    palette.setColor(QPalette::BrightText, Qt::red);
    palette.setColor(QPalette::Link, QColor(42, 130, 218));
    palette.setColor(QPalette::Highlight, QColor(255, 243, 240));
    palette.setColor(QPalette::HighlightedText, Qt::black);

  /*  palette.setColor(QPalette::Window, QColor(53, 53, 53));
     palette.setColor(QPalette::WindowText, Qt::white);
     palette.setColor(QPalette::Base, QColor(25, 25, 25));
     palette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
     palette.setColor(QPalette::ToolTipBase, Qt::white);
     palette.setColor(QPalette::ToolTipText, Qt::white);
     palette.setColor(QPalette::Text, Qt::white);
     palette.setColor(QPalette::Button, QColor(53, 53, 53));
     palette.setColor(QPalette::ButtonText, Qt::white);
     palette.setColor(QPalette::BrightText, Qt::red);
     palette.setColor(QPalette::Link, QColor(42, 130, 218));
     palette.setColor(QPalette::Highlight, QColor(42, 130, 218));
     palette.setColor(QPalette::HighlightedText, Qt::black); */

}

ColorTheme::~ColorTheme() {

}

QPalette ColorTheme::getPalette() const {
    return palette;
}
