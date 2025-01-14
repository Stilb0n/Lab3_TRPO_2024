QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += console
 QT += widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp
#    widget.cpp

HEADERS += \
    calculationstrategy.h \
    calculationstrategy.h \
    consoleoutput.h \
    consoloutput.h \
    customlib.h \
    customlib.h \
    extensioncalculationstrategy.h \
    extensioncalculationstrategy.h \
    foldercalculationstrategy.h \
    foldercalculationstrategy.h \
    percentcalculator.h \
    percentcalculator.h
 #    widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
