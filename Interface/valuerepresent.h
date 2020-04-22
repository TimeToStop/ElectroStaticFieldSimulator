#ifndef VALUEREPRESENT_H
#define VALUEREPRESENT_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>

// ToDo:

class ValueRepresent : public QWidget
{
    Q_OBJECT

    QLineEdit* m_edit;
    QLabel* m_measure_label;
    QString m_name;
    QString m_measure;


public:
    ValueRepresent(const QString& name, const QString& measure, double val = 0.0, QWidget *parent = nullptr);
    virtual ~ValueRepresent();

    void setReadOnly(bool);
    void setDefaultMeasure(bool);

    void setValue(double);

signals:
    void valueEdited(double);

public slots:
    void editNewValue();
};

#endif // VALUEREPRESENT_H
