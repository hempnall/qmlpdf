#include <QtQuick/QQuickView>
#include <QGuiApplication>
#include "popplerdoc.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<PopplerDoc>("PdfTools", 1, 0, "Poppler");

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:///main.qml"));
    view.show();
    return app.exec();
}
