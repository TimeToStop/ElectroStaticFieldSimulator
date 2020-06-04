#include "dictionary.h"
#include "Options/translator.h"

const char* const Dictionary::m_langs[Words::LENGTH_OF_WORDS_IN_DICT][Language::LENGTH_OF_LANGUAGES] =
{
    {"File", "Файл"},

    {"Open", "Открыть"},

    {"Save", "Сохранить"},

    {"Save As", "Сохранить Как"},

    {"Exit", "Выход"},

    {"Options", "Настройки"},

    {"Theme", "Тема"},

    {"Language", "Язык"},

    {"Help", "Помощь"},

    {"How To Use", "Инструкция по использованию"},

    {"About", "О Программе"},

    {"Charges", "Заряды"},

    {"Add Charge", "Добавить Заряд"},

    {"Ignore Charge", "Игнорировать Заряд"},

    {"Edit Charge", "Изменить Заряд"},

    {"Remove Charge", "Удалить Заряд"},

    {"Tension", "Напряженность"},

    {"Potential", "Потенциал"},

    {"Work", "Работа"},

    {"Energy", "Энергия"},

    {"Charge", "Заряд"},

    {"Use Cursor Position", "Использовать Позицию Курсора"},

    {"Position", "Позиция"},

    {"Position:", "Позиция:"},

    {"Start Point", "Начальная Точка"},

    {"Destination Point", "Конечная Точка"},

    {"Play", "Запуск"},

    {"Pause", "Пауза"},

    {"Speed x2", "Скорость x2"},

    {"Edit", "Изменить"},

    {"Additional", "Дополнительно"},

    {"Camera", "Камера"},

    {"Default", "По умолчанию"},

    {"Change Scene", "Изменить сцену"},

    {"Scale", "Масштаб"},

    {"Show Grid", "Показать сетку"},

    {"Show Electrostatic Field", "Показать Электростатическое Поле"},

    {"Info", "Информация"},

    {"Position Info", "Информация по позиции"},

    {"Charge Info", "Информация о заряде"},

    {"System Info", "Информация о системе"},

    {"Name:", "Имя заряда:"},

    {"Velocity:", "Скорость:"},

    {"Ignore", "Игнорировать"},

    {"Is Movable", "Динамический заряд"},

    {"English", "Английский"},

    {"Russian", "Русский"},

    {"s", "c"},
    {"m", "м"},
    {"m/s", "м/c"},
    {"m/s^2", "м/c^2"},
    {"V/m", "В/м"},
    {"V", "В"},
    {"J", "Дж"},
    {"C", "Кл"},
    {"kg", "кг"},

    {"Developers:", "Работали Над Проектом:"},
    {"All Rights Reserved.", "Все Права Защищены."}
};

QStringList Dictionary::m_prefixes[Language::LENGTH_OF_LANGUAGES] =
{
    // En default prefixes
    QStringList() << "p" << "n" << "mc" << "m"
                  << ""
                  << "k" << "M" << "G" << "T",
    // Rus default prefixes
    QStringList() << "п" << "н" << "мк" << "м"
                  << ""
                  << "к" << "М" << "Г" << "Т"
};

const char* Dictionary::dict(Words w, Language lang)
{
    return m_langs[w][lang];
}

QStringList Dictionary::prefix()
{
    switch (Translator::currentLang())
    {
    case Language::RUS:
    case Language::EN:
        return m_prefixes[Translator::currentLang()];
    default:
        return QStringList();
    }
}

Dictionary::Dictionary()
{
}

Dictionary::~Dictionary()
{
}

