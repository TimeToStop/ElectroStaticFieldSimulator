#ifndef SELECTCHARGE_H
#define SELECTCHARGE_H

#include <QDialog>
#include <QComboBox>

class SelectCharge : public QDialog
{
    Q_OBJECT

    QComboBox* m_box;

public:
    explicit SelectCharge(const QStringList&, QWidget *parent = nullptr);
    virtual ~SelectCharge();

    size_t getSelected() const;

signals:

};

#endif // SELECTCHARGE_H
