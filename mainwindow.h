#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QFile>
#include "widget/FileContentWidget.h"
#include "widget/SearchInput.h"
#include "components/MenuButton.h"

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

    // Widgets
    FileContentWidget *fileContentWidget;
    SearchInput *searchWidget;

    // Functions
    void clearMainWidget();
    void bindEventOfSearchButton(SearchInput *searchWidget, MainWindow *context); // Search Button 이벤트 바인딩

private:
    void setInitLayout();

};
#endif // MAINWINDOW_H
