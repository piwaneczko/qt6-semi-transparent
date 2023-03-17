
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickWindow>
#include <QSurfaceFormat>

int main(int argc, char* argv[]) {
    QApplication::setQuitOnLastWindowClosed(false);
    QApplication app(argc, argv);
    QQuickWindow::setDefaultAlphaBuffer(true);
    QSurfaceFormat::defaultFormat().setAlphaBufferSize(1);
    QQmlEngine engine;
    QQmlComponent(&engine, "qml/main.qml").create();

    return app.exec();
}