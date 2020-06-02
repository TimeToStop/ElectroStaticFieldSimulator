#ifndef CONTAINER_H
#define CONTAINER_H

#include "abstractcontainer.h"
#include "enums.h"
#include "dictionary.h"

#include <QTabWidget>
#include <QString>

template<typename T>
class Container : public AbstractContainer
{
    typedef void (T::* Method)(const QString&);

    T* m_object;
    Method m_method;
public:
    Container(Words w, T* obj, Method m) :
        AbstractContainer(w),
        m_object(obj),
        m_method(m)
    {
    }

    virtual ~Container()
    {
    }

    virtual void call(Language lang)
    {
        (m_object->*m_method)(Dictionary::dict(m_word, lang));
    }
};

template<>
class Container<QTabWidget> : public AbstractContainer
{
    typedef void (QTabWidget::* Method)(int, const QString&);

    QTabWidget* m_object;
    Method m_method;

    //New FIELD !!!!!
    int m_index;

public:
    Container(int indx, Words w, QTabWidget* obj, Method m) :
        AbstractContainer(w),
        m_object(obj),
        m_method(m),
        m_index(indx)
    {
    }

    virtual ~Container()
    {
    }

    virtual void call(Language lang) override
    {
        (m_object->*m_method)(m_index, Dictionary::dict(m_word, lang));
    }
};

#endif // CONTAINER_H
