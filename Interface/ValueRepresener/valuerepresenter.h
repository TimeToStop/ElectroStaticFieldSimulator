#ifndef VALUEREPRESENTER_H
#define VALUEREPRESENTER_H

#include <QWidget>
#include <QHBoxLayout>

class ValueRepresenter : public QWidget
{
    Q_OBJECT
    static const QStringList m_prefix;

protected:
    int m_curr_index;
    QHBoxLayout* m_layout;
    QString m_measure;


public:
    explicit ValueRepresenter(const QString&, const QString&, QWidget *parent = nullptr);
    virtual ~ValueRepresenter();

    virtual void setValue(float) = 0;
    virtual void setDisabled(bool) = 0;
    virtual float value() const = 0;

signals:
    void valueChanged();
    void valueEdited(float);

public slots:
    void prefixChanged(int);
    void newValueEdited();

protected:
    static float power(int);
};

#endif // VALUEREPRESENTER_H
