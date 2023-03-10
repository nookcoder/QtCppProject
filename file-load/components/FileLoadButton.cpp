//
// Created by 김현욱 on 2023/03/09.
//
#include <sstream>
#include "FileLoadButton.h"

FileLoadButton::FileLoadButton(QWidget *parent) : QPushButton(parent){
    setText("File Load");
}

using namespace std;
QFile *FileLoadButton::loadFile(QString filename) {
    stringstream ss;
    std::cout << ss.str();
//    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt);;All Files (*.*)"));
    QFile *file = new QFile(filename, this);
    if(file->open(QIODevice::ReadOnly)){
        cout << "Success";
        return file;
    } else {
        cout << "Fail";
        return new QFile();
    }
}
