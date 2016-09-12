QMAKE_CXXFLAGS += -std=c++11 -pthread -lpthread
LIBS += -pthread
LIBS += -lboost_system
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    buffer.cpp \
    merge_frames.cpp \
    threadfunctions.cpp \
    gcd.cpp


LIBS += -L/usr/local/lib \
-lopencv_core \
-lopencv_imgproc \
-lopencv_highgui \
-lopencv_ml \
-lopencv_video \
-lopencv_videoio \
-lopencv_features2d \
-lopencv_calib3d \
-lopencv_objdetect \
-lopencv_flann \
-lopencv_imgcodecs

HEADERS += \
    buffer.h \
    merge_frames.h \
    threadfunctions.h \
    gcd.h
