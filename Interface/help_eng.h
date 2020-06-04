#ifndef HELP_ENG_H
#define HELP_ENG_H

#include <QDialog>

namespace Ui {
class Help_eng;
}

class Help_eng : public QDialog
{
    Q_OBJECT

public:
    explicit Help_eng(QWidget *parent = 0);
    ~Help_eng();

private:
    Ui::Help_eng *ui;
};

#endif // HELP_ENG_H
