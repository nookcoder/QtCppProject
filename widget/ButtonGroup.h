//
// Created by 김현욱 on 2023/03/10.
//

#ifndef DATABASE_PROJECT_BUTTONGROUP_H
#define DATABASE_PROJECT_BUTTONGROUP_H


#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QMainWindow>
#include "../mainwindow.h"
#include "../global.h"
#include "SearchInput.h"
#include "FileContentWidget.h"
#include "UpdateFile.h"
#include "DeleteFileWidget.h"

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

private slots:
    void saveNewFile(); // 파일 저장하기

private:
    void initLayout(); // 초기화
    void bindButtonEvent(); // 버튼 이벤트 바인딩
    void changeMenu(QString type); // 메뉴 전환
    QVBoxLayout *vBoxLayout;
    QString contents;

    QPushButton *fileLoad;
    QPushButton *filePrint;
    QPushButton *fileUpdate;
    QPushButton *fileDelete;
    QPushButton *fileFind;
    QPushButton *fileSave;
    QPushButton *exit;
};


#endif //DATABASE_PROJECT_BUTTONGROUP_H
