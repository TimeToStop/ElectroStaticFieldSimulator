#pragma once

#include <vector>
#include <memory>
#include <utility>

#include "Container.h"

class Translater
{
	static Translater translater;
	static int m_id;

	typedef typename std::template unique_ptr<AbstractContainer> AbstractContainerPtr;
	typedef typename std::template vector<AbstractContainerPtr> ContainerHolder;

	std::vector<std::pair<int, ContainerHolder>> m_all_containers;

public:

	template<typename T, Words w>
    static void registerWidget(int id, T* object, void (T::* setText)(const QString&))
	{
		for (std::vector<std::pair<int, Translater::ContainerHolder>>::iterator it = translater.m_all_containers.begin(); it != translater.m_all_containers.end(); ++it)
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
		for (std::vector<std::pair<int, Translater::ContainerHolder>>::iterator it = translater.m_all_containers.begin(); it != translater.m_all_containers.end(); ++it)
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
		translater.m_all_containers.push_back(std::make_pair(m_id, ContainerHolder()));
		return m_id++;
	}

	static void rmContainer(int id)
	{
		for (std::vector<std::pair<int, Translater::ContainerHolder>>::iterator it = translater.m_all_containers.begin(); it != translater.m_all_containers.end(); ++it)
		{
			if ((it)->first == id)
			{
				translater.m_all_containers.erase(it);
				return;
			}
		}
	}

	static void setLanguage(Language lang = EN)
	{
		for (std::pair<int, ContainerHolder>& container_holder : translater.m_all_containers)
		{
			for (AbstractContainerPtr& container : container_holder.second)
			{
				container->call(lang);
			}
		}
	}

private:
	Translater(): m_all_containers() {}
	~Translater() { m_all_containers.clear(); }
};

