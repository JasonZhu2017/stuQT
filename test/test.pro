QT += core
QT -= gui

CONFIG += c++11

TARGET = test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp
INCLUDEPATH +=  C:\opencv\mingw\include\
                C:\opencv\mingw\include\opencv\
                C:\opencv\mingw\include\opencv2\

LIBS += C:\opencv\mingw\lib\libopencv_calib3d2413.dll.a\
    C:\opencv\mingw\lib\libopencv_contrib2413.dll.a\
    C:\opencv\mingw\lib\libopencv_core2413.dll.a\
    C:\opencv\mingw\lib\libopencv_features2d2413.dll.a\
    C:\opencv\mingw\lib\libopencv_flann2413.dll.a\
    C:\opencv\mingw\lib\libopencv_gpu2413.dll.a\
    C:\opencv\mingw\lib\libopencv_highgui2413.dll.a\
    C:\opencv\mingw\lib\libopencv_imgproc2413.dll.a\
    C:\opencv\mingw\lib\libopencv_legacy2413.dll.a\
    C:\opencv\mingw\lib\libopencv_ml2413.dll.a\
    C:\opencv\mingw\lib\libopencv_nonfree2413.dll.a\
    C:\opencv\mingw\lib\libopencv_objdetect2413.dll.a\
    C:\opencv\mingw\lib\libopencv_ocl2413.dll.a\
    C:\opencv\mingw\lib\libopencv_photo2413.dll.a\
    C:\opencv\mingw\lib\libopencv_stitching2413.dll.a\
    C:\opencv\mingw\lib\libopencv_superres2413.dll.a\
    C:\opencv\mingw\lib\libopencv_ts2413.dll.a\
    C:\opencv\mingw\lib\libopencv_video2413.dll.a\
    C:\opencv\mingw\lib\libopencv_videostab2413.dll.a
