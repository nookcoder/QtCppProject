//
// Created by 김현욱 on 2023/03/10.
//

#ifndef DATABASE_PROJECT_BUTTONGROUP_H
#define DATABASE_PROJECT_BUTTONGROUP_H


#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QMainWindow>
//#include "../mainwindow.h"
#include "../global.h"
#include "SearchInput.h"
#include "FileContentWidget.h"
#include "UpdateFile.h"
#include "DeleteFileWidget.h"
#include "../components/MenuButton.h"

class ButtonGroup : public QWidget {
Q_OBJECT
public:
    ButtonGroup
            (
                    QWidget *parent
//                    MainWindow *parent,
//                    SearchInput *searchWidget,
//                    FileContentWidget *contentWidget
    );

//    MainWindow *m_parent;
    SearchInput *m_searchWidget;
    FileContentWidget *m_contentWidget;
    QPushButton *fileLoad;
    QPushButton *filePrint;
    QPushButton *fileUpdate;
    QPushButton *fileDelete;
    QPushButton *fileFind;
    QPushButton *fileSave;
    QPushButton *insertFile;
    QPushButton *exit;

private:
    void initLayout(); // 초기화
    QVBoxLayout *vBoxLayout;
    QString contents;
};

using namespace std;


#endif //DATABASE_PROJECT_BUTTONGROUP_H
