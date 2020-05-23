#include "Dictionary.h"


const char* const Dictionary::m_langs[Language::LENGTH_OF_LANGUAGES][Words::LENGTH_OF_WORDS_IN_DICT] =
{
	{"Edit"},
	{"Изменить"}
};

const char* Dictionary::dict(Words w, Language lang)
{
	return m_langs[lang][w];
}

Dictionary::Dictionary()
{
}

Dictionary::~Dictionary()
{
}
