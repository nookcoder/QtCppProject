#include <QApplication>
#include <QGraphicsView>
#include <QPushButton>
#include <QWindow>
#include <QWidget>
#include <QStandardItemModel>
#include <QListView>
#include <QGridLayout>
#include "mainwindow.h"
#include <iostream>


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.resize(800,600);
    mainWindow.show();
    return a.exec();
}

