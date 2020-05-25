QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Editor/Objects/arrow.cpp \
    Editor/Objects/chargeedit.cpp \
    Editor/Objects/object.cpp \
    Editor/editor.cpp \
    Editor/editwindow.cpp \
    Editor/mediator.cpp \
    Interface/plotgridwidget.cpp \
    Interface/simulator.cpp \
    Options/AbstractContainer.cpp \
    Options/Dictionary.cpp \
    Options/Theme.cpp \
    Options/Translater.cpp \
    Engine/charge.cpp \
    Engine/engine.cpp \
    Engine/vector.cpp \
    Interface/Charge/createchargedialog.cpp \
    Interface/Charge/ignorechargesdialog.cpp \
    Interface/Charge/selectcharge.cpp \
    Interface/ValueRepresenter/valueedit.cpp \
    Interface/ValueRepresenter/valuerepresenter.cpp \
    Interface/ValueRepresenter/valuewriter.cpp \
    Interface/enginewidget.cpp \
    main.cpp

HEADERS += \
    Editor/Objects/arrow.h \
    Editor/Objects/chargeedit.h \
    Editor/Objects/object.h \
    Editor/editor.h \
    Editor/editwindow.h \
    Editor/mediator.h \
    Interface/plotgridwidget.h \
    Interface/simulator.h \
    Options/AbstractContainer.h \
    Options/Container.h \
    Options/Dictionary.h \
    Options/Enums.h \
    Options/Theme.h \
    Options/Translater.h \
    Engine/charge.h \
    Engine/engine.h \
    Engine/vector.h \
    Interface/Charge/createchargedialog.h \
    Interface/Charge/ignorechargesdialog.h \
    Interface/Charge/selectcharge.h \
    Interface/ValueRepresenter/valueedit.h \
    Interface/ValueRepresenter/valuerepresenter.h \
    Interface/ValueRepresenter/valuewriter.h \
    Interface/enginewidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    Editor/editwindow.ui \
    Interface/Charge/createchargedialog.ui \
    Interface/Charge/ignorechargesdialog.ui \
    Interface/simulator.ui
