
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickWindow>
#include <QSurfaceFormat>

int main(int argc, char* argv[]) {
    QApplication::setQuitOnLastWindowClosed(false);
    QApplication app(argc, argv);
    QQmlEngine engine;
    QQmlComponent(&engine, QUrl("qrc:/qml/main.qml")).create();

    return app.exec();
}