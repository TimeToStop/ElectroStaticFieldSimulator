#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Enums.h"

class Dictionary
{
    static const char* const m_langs[Words::LENGTH_OF_WORDS_IN_DICT][Language::LENGTH_OF_LANGUAGES];

public:
    static const char* const dict(Words w, Language lang);

private:
    Dictionary();
    ~Dictionary();
};
#endif // DICTIONARY_H
