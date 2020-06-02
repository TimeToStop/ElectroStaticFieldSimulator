#ifndef TRANSLATOR_H
#define TRANSLATOR_H


#include <vector>
#include <memory>
#include <utility>
#include <QString>

#include "Options/container.h"

class Translator
{
    static Translator translator;
    static int m_id;
    static Language m_current_lang;

    typedef typename std::template unique_ptr<AbstractContainer> AbstractContainerPtr;
    typedef typename std::template vector<AbstractContainerPtr> ContainerHolder;

    std::vector<std::pair<int, ContainerHolder>> m_all_containers;

public:
    static Language currentLang();

    template<typename T, Words w>
    static void registerWidget(int id, T* object, void (T::* setText)(const QString&))
    {
        for (std::vector<std::pair<int, Translator::ContainerHolder>>::iterator it = translator.m_all_containers.begin(); it != translator.m_all_containers.end(); ++it)
        {
            if ((it)->first == id)
            {
                (it)->second.push_back(std::make_unique<Container<T>>(w, object, setText));
                return;
            }
        }
    }

    template<Words w>
    static void registerWidget(int indx, int id, QTabWidget* object, void (QTabWidget::* setText)(int, const QString&))
    {
        for (std::vector<std::pair<int, Translator::ContainerHolder>>::iterator it = translator.m_all_containers.begin(); it != translator.m_all_containers.end(); ++it)
        {
            if ((it)->first == id)
            {
                (it)->second.push_back(std::make_unique<Container<QTabWidget>>(indx, w, object, setText));
                return;
            }
        }
    }

    static int addContainer()
    {
        translator.m_all_containers.push_back(std::make_pair(m_id, ContainerHolder()));
        return m_id++;
    }

    static void rmContainer(int id)
    {
        for (std::vector<std::pair<int, Translator::ContainerHolder>>::iterator it = translator.m_all_containers.begin(); it != translator.m_all_containers.end(); ++it)
        {
            if ((it)->first == id)
            {
                translator.m_all_containers.erase(it);
                return;
            }
        }
    }

    static void setLanguage(Language lang = Translator::m_current_lang)
    {
        m_current_lang = lang;
        for (std::pair<int, ContainerHolder>& container_holder : translator.m_all_containers)
        {
            for (AbstractContainerPtr& container : container_holder.second)
            {
                container->call(m_current_lang);
            }
        }
    }

private:
    Translator(): m_all_containers() {}
    ~Translator() { m_all_containers.clear(); }
};

#endif // TRANSLATOR_H
