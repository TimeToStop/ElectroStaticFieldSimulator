#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Options/enums.h"
#include <QStringList>

class Dictionary
{
    static const char* const m_langs[Words::LENGTH_OF_WORDS_IN_DICT][Language::LENGTH_OF_LANGUAGES];
    static QStringList m_prefixes[Language::LENGTH_OF_LANGUAGES];

public:
    static const char* dict(Words w, Language lang);
    static QStringList prefix();

private:
    Dictionary();
    ~Dictionary();
};
#endif // DICTIONARY_H
