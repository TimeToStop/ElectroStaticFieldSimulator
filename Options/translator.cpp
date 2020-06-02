#include "translator.h"

Translator Translator::translator;
int Translator::m_id = 0;
Language Translator::m_current_lang = EN;

Language Translator::currentLang()
{
    return m_current_lang;
}
