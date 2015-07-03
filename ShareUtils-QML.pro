TEMPLATE = lib

CONFIG += staticlib

QT += qml quick

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

SOURCES += shareutils.cpp
HEADERS += shareutils.h

ios {
    OBJECTIVE_SOURCES += ios/iosshareutils.mm
    HEADERS += ios/iosshareutils.h
}

android {
    QT += androidextras
    OTHER_FILES += android_data/src/com/lasconic/QShareUtils.java
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android_data
    SOURCES += android/androidshareutils.cpp
    HEADERS += android/androidshareutils.h
}

