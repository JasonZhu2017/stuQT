QT += core
QT -= gui

CONFIG += c++11

TARGET = myOpenCVProject
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp
INCLUDEPATH +=  C:\\opencv\\mingw\\include\
                C:\\opencv\\mingw\\include\\opencv\
                C:\\opencv\\mingw\\include\\opencv2\

LIBS += C:\\opencv\\mingw\\lib\\libopencv_calib3d2413.dll.a\
    C:\\opencv\\mingw\\lib\\libopencv_contrib2413.dll.a\
    C:\\opencv\\mingw\\lib\\libopencv_core2413.dll.a\
    C:\\opencv\\mingw\\lib\\libopencv_features2d2413.dll.a\
    C:\\opencv\\mingw\\lib\\libopencv_flann2413.dll.a\
    C:\\opencv\\mingw\\lib\\libopencv_gpu2413.dll.a\
    C:\\opencv\\mingw\\lib\\libopencv_highgui2413.dll.a\
    C:\\opencv\\mingw\\lib\\libopencv_imgproc2413.dll.a\
    C:\\opencv\\mingw\\lib\\libopencv_legacy2413.dll.a\
    C:\\opencv\\mingw\\lib\\libopencv_ml2413.dll.a\
    C:\\opencv\\mingw\\lib\\libopencv_nonfree2413.dll.a\
    C:\\opencv\\mingw\\lib\\libopencv_objdetect2413.dll.a\
    C:\\opencv\\mingw\\lib\\libopencv_ocl2413.dll.a\
    C:\\opencv\\mingw\\lib\\libopencv_photo2413.dll.a\
    C:\\opencv\\mingw\\lib\\libopencv_stitching2413.dll.a\
    C:\\opencv\\mingw\\lib\\libopencv_superres2413.dll.a\
    C:\\opencv\\mingw\\lib\\libopencv_ts2413.dll.a\
    C:\\opencv\\mingw\\lib\\libopencv_video2413.dll.a\
    C:\\opencv\\mingw\\lib\\libopencv_videostab2413.dll.a\

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.-1
