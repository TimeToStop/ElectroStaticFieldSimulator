#ifndef IGNORECHARGESDIALOG_H
#define IGNORECHARGESDIALOG_H

#include <Engine/charge.h>
#include <QDialog>

namespace Ui {
class IgnoreChargesDialog;
}

class IgnoreChargesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IgnoreChargesDialog(const QStringList&, QWidget *parent = nullptr);
    ~IgnoreChargesDialog();


private:
    Ui::IgnoreChargesDialog *ui;
};

#endif // IGNORECHARGESDIALOG_H
