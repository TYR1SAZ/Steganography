QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = opencvtest
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    attacks.cpp \
    haar.cpp \
    main.cpp \
    mainwindow.cpp \
    stegopictures.cpp

HEADERS += \
    attacks.h \
    haar.h \
    mainwindow.h \
    stegopictures.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += D:\Libraries\opencv\build\include

LIBS += D:\Libraries\opencv\build\bin\libopencv_core470.dll
LIBS += D:\Libraries\opencv\build\bin\libopencv_highgui470.dll
LIBS += D:\Libraries\opencv\build\bin\libopencv_imgcodecs470.dll
LIBS += D:\Libraries\opencv\build\bin\libopencv_imgproc470.dll
LIBS += D:\Libraries\opencv\build\bin\libopencv_features2d470.dll
LIBS += D:\Libraries\opencv\build\bin\libopencv_calib3d470.dll
