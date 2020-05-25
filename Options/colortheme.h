#ifndef COLORTHEME_H
#define COLORTHEME_H

#include <QWidget>

class ColorTheme {

private:
    QPalette color;

public:
    ColorTheme();
    ~ColorTheme();

    QPalette pallete();
};

#endif // COLORTHEME_H
