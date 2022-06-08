#include "src/mainwindow.h"
#include <QApplication>
#include <QWidget>

#include <QFileSystemModel>
#include <QTreeView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
