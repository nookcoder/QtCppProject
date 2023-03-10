//
// Created by 김현욱 on 2023/03/10.
//

#include "FileContentWidget.h"
FileContentWidget::FileContentWidget(QWidget *parent, QString fileContent) : QWidget(parent){
    delete layout();
    QTextEdit *fileTextEdit = new QTextEdit(this);
    QVBoxLayout *layout = new QVBoxLayout(this);

    fileTextEdit->setText(fileContent);
    layout->addWidget(fileTextEdit);
    setLayout(layout);
}