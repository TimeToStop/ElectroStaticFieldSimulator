#ifndef ENUMS_H
#define ENUMS_H

enum Words
{
    FILE_,
    OPEN, SAVE, SAVE_AS,
    EXIT, OPTIONS, THEME, LANGUAGE,
    HELP, HOW_TO, CREDITS,

    CHARGES, ADD_CHARGE, IGNORE_CHARGE,
    EDIT_CHARGE, REMOVE_CHARGE,

    TENSION, POTENTIAL, WORK, ENERGY,

    USE_CURSOR_POSITION, POSITION, START, DESTINATION,

    PLAY_, PAUSE_, SPEED, EDIT_, ADDITIONAL, CAMERA_AT,
    DEFAULT, CHANGE_SCENE, SCALE, SHOW_GRID,
    SHOW_ELECTROSTATIC_FIELD, INFO, POSITION_INFO,

    NAME, VELOCITY, IS_IGNORE,  IS_MOVABLE,

    ENGLISH, RUSSIAN,

    PHY_VAL_TIME,
    PHY_VAL_METRES,
    PHY_VAL_VEL,
    PHY_VAL_ACC,
    PHY_VAL_TENSION,
    PHY_VAL_POTENTIAL,
    PHY_VAL_WORK,

    LENGTH_OF_WORDS_IN_DICT
};

enum Language {EN, RUS, LENGTH_OF_LANGUAGES};

#endif // ENUMS_H
