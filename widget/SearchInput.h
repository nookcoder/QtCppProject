         //
// Created by 김현욱 on 2023/03/10.
//

#ifndef DATABASE_PROJECT_SEARCHINPUT_H
#define DATABASE_PROJECT_SEARCHINPUT_H


#include <QObject>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QString>
#include <QFile>
#include <QMainWindow>
#include "../modal/ResultModal.h"

#include "../global.h"
using namespace std;
class SearchInput : public QWidget{
    Q_OBJECT
public:
    SearchInput(QWidget *parent= nullptr);
    QString searchResult;
    QPushButton *searchButton;
    QLineEdit *edit;
    QPushButton *backToMenu;
//    MainWindow *m_parent;

public slots:
    QFile *loadFile(QLineEdit *edit);
private:
    void initLayout();
    void bindEvent();
    QWidget *main;
};


#endif //DATABASE_PROJECT_SEARCHINPUT_H
