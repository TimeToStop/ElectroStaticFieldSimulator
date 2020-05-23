#pragma once
#include "Enums.h"

class AbstractContainer
{
protected:
	Words m_word;

public:
	AbstractContainer(Words w);
	virtual ~AbstractContainer();
	virtual void call(Language) = 0;
};
