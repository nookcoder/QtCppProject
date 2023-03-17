#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QFile>
#include <QBoxLayout>

#include "widget/FileContentWidget.h"
#include "widget/SearchInput.h"
#include "widget/UpdateFile.h"
#include "widget/DeleteFileWidget.h"
#include "widget/ButtonGroup.h"
#include "widget/SaveFileWidget.h"
#include "widget/FindFileWidget.h"
#include "widget/AppendContentWidget.h"
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

private:
    void initLayout();
    void bindButtonGroupEvent();
    void bindMenuButtonEvent(QPushButton *button, QString menu);
    void bindBackToMenuEvent(QPushButton *button);
    void backToMenu();
    void clearMainWidget();

    // Fields
    QWidget *main;
    QVBoxLayout *mainLayout;

    // Widgets
    ButtonGroup *buttonGroup;
    FileContentWidget *fileContentWidget;
    SearchInput *searchWidget;
    UpdateFile *updateFileWidget;
    DeleteFileWidget *deleteFileWidget;
    SaveFileWidget *saveFileWidget;
    FindFileWidget *findFileWidget;
    AppendContentWidget *insertFileWidget;

private slots:
    void changeMenu(QString menu);
};
#endif // MAINWINDOW_H
