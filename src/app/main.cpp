#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char* argv[]) {
    QApplication::setQuitOnLastWindowClosed(false);
    QApplication app(argc, argv);
    QQmlApplicationEngine engine("qrc:/qml/main.qml");
    return app.exec();
}