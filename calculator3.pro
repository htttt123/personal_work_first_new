#-------------------------------------------------
#
# Project created by QtCreator 2020-09-27T10:30:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calculator3
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        jc_widget.cpp \
    hanshu_widget.cpp \
    trigo_widget.cpp \
    main_widget.cpp \
    jzzh_widget.cpp \
    jzys_widget.cpp \
    change_widget.cpp

HEADERS += \
        jc_widget.h \
    hanshu_widget.h \
    trigo_widget.h \
    main_widget.h \
    jzzh_widget.h \
    jzys_widget.h \
    change_widget.h

FORMS += \
        jc_widget.ui \
    hanshu_widget.ui \
    trigo_widget.ui \
    main_widget.ui \
    jzzh_widget.ui \
    jzys_widget.ui \
    change_widget.ui

RESOURCES += \
    res.qrc
