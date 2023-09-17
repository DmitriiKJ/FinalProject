QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    autoshop.cpp \
    brand.cpp \
    buy.cpp \
    car.cpp \
    client.cpp \
    dialogaddbrand.cpp \
    dialogaddclients.cpp \
    dialogaddengine.cpp \
    dialogaddmanager.cpp \
    dialogbrand.cpp \
    dialogclient.cpp \
    dialogengine.cpp \
    dialogmanager.cpp \
    human.cpp \
    main.cpp \
    mainwindow.cpp \
    manager.cpp

HEADERS += \
    autoshop.h \
    brand.h \
    buy.h \
    car.h \
    client.h \
    dialogaddbrand.h \
    dialogaddclients.h \
    dialogaddengine.h \
    dialogaddmanager.h \
    dialogbrand.h \
    dialogclient.h \
    dialogengine.h \
    dialogmanager.h \
    human.h \
    mainwindow.h \
    manager.h

FORMS += \
    dialogaddbrand.ui \
    dialogaddclients.ui \
    dialogaddengine.ui \
    dialogaddmanager.ui \
    dialogbrand.ui \
    dialogclient.ui \
    dialogengine.ui \
    dialogmanager.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
