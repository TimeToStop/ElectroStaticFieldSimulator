#ifndef THEME_H
#define THEME_H

class QPallete {};

enum ThemeType {Dark, Light, LENGTH_OF_PALLETES};

class Themes
{
    static Themes themes;
    QPallete m_pallete[ThemeType::LENGTH_OF_PALLETES];

    static QPallete get(ThemeType type) { return themes.m_pallete[type]; }

private:
    Themes()
    {
        // init m_pallete
    }
    ~Themes() {}
};

#endif // THEME_H
