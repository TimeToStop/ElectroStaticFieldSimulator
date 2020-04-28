#ifndef COLORTHEME_H
#define COLORTHEME_H

#include <QWidget>

class ColorTheme {
public:
    ColorTheme();
    ~ColorTheme();
    QPalette getPalette() const;

private:
    QPalette palette;
};

#endif // COLORTHEME_H
