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

using namespace std;
class SearchInput : public QWidget{
    Q_OBJECT
public:
    SearchInput(QWidget *parent= nullptr);
    QString searchResult;
    QPushButton *searchButton;
    QLineEdit *edit;
//    MainWindow *m_parent;

public slots:
    void getFilenameFromSearchBox(QLineEdit *edit);
    QFile *loadFile(QLineEdit *edit);
private:
    QWidget *main;
};


#endif //DATABASE_PROJECT_SEARCHINPUT_H
