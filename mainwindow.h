#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QFile>
#include "widget/FileContentWidget.h"
#include "widget/SearchInput.h"
#include "components/MenuButton.h"
#include "global.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);

public:
    // Fields
    QWidget *rightWidget;
    QVBoxLayout *rightLayout;
    QFile *currentFile;
    QString currentFileContents;

    // Widgets
    FileContentWidget *fileContentWidget;
    SearchInput *searchWidget;

    // Functions
    void clearMainWidget();

private:
    void setInitLayout();

};
#endif // MAINWINDOW_H
