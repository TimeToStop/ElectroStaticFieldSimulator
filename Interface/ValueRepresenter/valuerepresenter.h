#ifndef VALUEREPRESENTER_H
#define VALUEREPRESENTER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLabel>

class ValueRepresenter : public QWidget
{
    Q_OBJECT
    static const QStringList m_prefix;

protected:
    int m_curr_index;
    QLabel* m_header;
    QComboBox* m_box;
    QString m_measure;


public:
    explicit ValueRepresenter(QLabel*, QComboBox*, const QString&, const QString&, QWidget *parent = nullptr);
    virtual ~ValueRepresenter();

    virtual void setValueOnly(float) = 0;
    virtual float valueOnly() const = 0;
    virtual void setFixedEditWidth(int) = 0;
    virtual void setDisabled(bool) = 0;

    void setValue(float);
    float value() const;

protected:
    static float power(int);

signals:
    void valueChanged();
    void valueEdited(float);

public slots:
    virtual void newValueEdited();
    virtual void prefixChanged(int);
};

#endif // VALUEREPRESENTER_H
