//
// Created by 김현욱 on 2023/03/10.
//

#ifndef DATABASE_PROJECT_BUTTONGROUP_H
#define DATABASE_PROJECT_BUTTONGROUP_H


#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QMainWindow>
#include "SearchInput.h"
#include "FileContentWidget.h"
#include "../mainwindow.h"

using namespace std;
class ButtonGroup : public QWidget {
    Q_OBJECT
public:
    ButtonGroup
    (
            MainWindow *parent,
            SearchInput *searchWidget,
            FileContentWidget *contentWidget
    );
    MainWindow *m_parent;
    SearchInput *m_searchWidget;
    FileContentWidget *m_contentWidget;

    void addMenuWidget(QString type);
private:
    QVBoxLayout *vBoxLayout;
};


#endif //DATABASE_PROJECT_BUTTONGROUP_H