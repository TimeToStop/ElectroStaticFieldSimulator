#ifndef IGNORECHARGE_H
#define IGNORECHARGE_H

#include <QDialog>

class IgnoreCharge : public QDialog
{
    Q_OBJECT
public:
    explicit IgnoreCharge(const QStringList&, QWidget *parent = nullptr);
    virtual ~IgnoreCharge();

    std::vector<size_t> indexToIgnore() const;

signals:

};

#endif // IGNORECHARGE_H
