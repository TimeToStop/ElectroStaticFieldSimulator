#pragma once
#include "Enums.h"

class Dictionary
{
	static const char* const m_langs[Language::LENGTH_OF_LANGUAGES][Words::LENGTH_OF_WORDS_IN_DICT];
	
public:
    static const char* dict(Words w, Language lang);

private:
	Dictionary();
	~Dictionary();
};
