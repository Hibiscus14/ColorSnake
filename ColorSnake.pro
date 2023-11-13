QT       += core gui
QT += concurrent gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = ColorSnake
TEMPLATE = app

CONFIG += c++17


DEFINES += QT_DEPRECATED_WARNINGS

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    getColors.cpp \
    getFileNames.cpp \
    main.cpp \
    mainwindow.cpp \
    saveImages.cpp \
    sort.cpp \
    warnings.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

win32::RC_FILE = icon.rc

LIBS += -LC:\STUFF\opencv\opencv_build\install\x64\vc17\lib -opencv_core480d -lopencv_imgproc480d -lopencv_highgui480d -lopencv_imgcodecs480d -lopencv_videoio480d -lopencv_video480d -lopencv_calib3d480d -lopencv_photo480d -lopencv_features2d480d -opencv_tracking480d
LIBS += -LC:\opencv_build\install\x86\vc15\lib -lopencv_core480 -lopencv_imgproc480 -lopencv_highgui480 -lopencv_imgcodecs480 -lopencv_videoio480 -lopencv_video480 -lopencv_calib3d480 -lopencv_photo480 -lopencv_features2d480 - opencv_tracking480
INCLUDEPATH += C:\STUFF\opencv\opencv_build\install\include
DEPENDPATH += C:\STUFF\opencv\opencv_build\install\include

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resours.qrc
