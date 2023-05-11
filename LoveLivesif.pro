QT       += core gui multimedia multimediawidgets
RC_ICONS=icon.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cards.cpp \
    gamepanel.cpp \
    main.cpp \
    randompic.cpp \
    widget.cpp

HEADERS += \
    cards.h \
    gamepanel.h \
    randompic.h \
    widget.h

FORMS += \
    cards.ui \
    gamepanel.ui \
    randompic.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
