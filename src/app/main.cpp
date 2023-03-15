
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>

int main(int argc, char* argv[]) {
    QApplication::setQuitOnLastWindowClosed(false);
    QApplication app(argc, argv);
    QQmlEngine engine;
    QQmlComponent(&engine, "qml/main.qml").create();

    return app.exec();
}