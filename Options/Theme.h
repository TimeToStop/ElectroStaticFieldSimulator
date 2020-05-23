#pragma once
#include <QPalette>

enum ThemeType {Dark, Light, LENGTH_OF_PALLETES};

class Themes
{
	static Themes themes;
    QPalette m_pallete[ThemeType::LENGTH_OF_PALLETES];

    static QPalette get(ThemeType type) { return themes.m_pallete[type]; }

private:
	Themes()
	{
		// init m_pallete
	}
	~Themes() {}
};

