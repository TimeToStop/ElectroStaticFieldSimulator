#include "Interface/mainwindow.h"
#include "Options/colortheme.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    ColorTheme theme;
    a.setStyle(QStyleFactory::create("Fusion"));
    a.setPalette(theme.pallete());
    QFont newFont("Cambria", 10, QFont::Medium, false);
    a.setFont(newFont);

    w.show();
    return a.exec();
}
