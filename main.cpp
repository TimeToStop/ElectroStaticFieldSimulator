#include "Interface/widget.h"
#include "Interface/colortheme.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    ColorTheme them;
    a.setStyle(QStyleFactory::create("Fusion"));
    a.setPalette(them.getPalette());
    QFont newFont("Cambria", 10, QFont::Medium, false);
    a.setFont(newFont);

    Widget w;
    w.show();
    return a.exec();
}
