#include "dictionary.h"

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

    {"How To", "Мануал"},

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

    {"Use Cursor Position", "Использовать Позицию Курсора"},

    {"Position:", "Позиция:"},

    {"Start Point", "Начальная Точка"},

    {"Destination Point", "Конечная Точка"},

    {"Play", "Запуск"},

    {"Pause", "Пауза"},

    {"Speed x2", "Скорость x2"},

    {"Edit", "Изменить"},

    {"Additional", "Дополнительно"},

    {"Camera:", "Камера:"},

    {"Default", "По умолчанию"},

    {"Change Scene", "Изменить сцену"},

    {"Scale", "Масштаб"},

    {"Show Grid", "Показать сетку"},

    {"Show Electrostatic Field", "Показать Электростатическое Поле"},

    {"Info", "Информация"},

    {"Position Info", "Информация по позиции"},

    {"Name:", "Имя заряда:"},

    {"Velocity:", "Скорость:"},

    {"Ignore:", "Игнорировать:"},

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
    {"kg", "кг"}
};

const char* Dictionary::dict(Words w, Language lang)
{
    return m_langs[w][lang];
}

Dictionary::Dictionary()
{
}

Dictionary::~Dictionary()
{
}

