TEMPLATE = app

QT += qml quick gui

SOURCES += main.cpp \
    pdfviewer.cpp \
    popplerdoc.cpp

RESOURCES += qml.qrc

INCLUDEPATH += /usr/local/include/poppler/qt5
#INCLUDEPATH += /opt/local/include

LIBS += -L/usr/local/lib -lpoppler-qt5 -lstdc++


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    pdfviewer.h \
    popplerdoc.h
