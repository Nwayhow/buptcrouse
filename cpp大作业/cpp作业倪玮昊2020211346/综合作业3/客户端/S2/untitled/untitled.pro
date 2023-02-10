QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    change.cpp \
    changedev.cpp \
    dev.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    mananger.cpp \
    sign.cpp \
    user.cpp \
    user_mon.cpp \
    user_sen.cpp

HEADERS += \
    change.h \
    changedev.h \
    dev.h \
    login.h \
    mainwindow.h \
    mananger.h \
    sign.h \
    user.h \
    user_mon.h \
    user_sen.h

FORMS += \
    change.ui \
    changedev.ui \
    dev.ui \
    login.ui \
    mainwindow.ui \
    mananger.ui \
    sign.ui \
    user.ui \
    user_mon.ui \
    user_sen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
