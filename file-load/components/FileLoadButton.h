//
// Created by 김현욱 on 2023/03/09.
//

#ifndef DATABASE_PROJECT_FILELOADBUTTON_H
#define DATABASE_PROJECT_FILELOADBUTTON_H


#include <QPushButton>
#include <QFileDialog>
#include <iostream>
#include <fstream>

using namespace std;
class FileLoadButton : public QPushButton{
    Q_OBJECT
public:
    FileLoadButton(QWidget *parent = nullptr);
public slots:
    QFile *loadFile(QString filename);
};


#endif //DATABASE_PROJECT_FILELOADBUTTON_H
