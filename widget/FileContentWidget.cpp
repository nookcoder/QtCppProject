//
// Created by 김현욱 on 2023/03/10.
//

#include "FileContentWidget.h"
FileContentWidget::FileContentWidget(QWidget *parent, QString fileContent) : QWidget(parent){
    delete layout();
    fileContentBox = new QTextEdit(this);
    QVBoxLayout *layout = new QVBoxLayout(this);

    fileContentBox->setText(fileContent);
    layout->addWidget(fileContentBox);
    setLayout(layout);
}

void FileContentWidget::printFileContent(QFile *file) {
    QTextStream in(file);
    QString fileContents = in.readAll();
    fileContentBox->setText(fileContents);
}