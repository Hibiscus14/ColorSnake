#include "mainwindow.h"
#include <QStyleFactory>
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    qApp->setStyle(QStyleFactory::create("Fusion"));

    MainWindow w;
    w.show();
    return a.exec();
}
