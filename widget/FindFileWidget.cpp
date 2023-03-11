//
// Created by 김현욱 on 2023/03/11.
//

#include "FindFileWidget.h"
#include <iostream>
FindFileWidget::FindFileWidget(QWidget *parent) : QWidget(parent){
    initLayout();
    bindEvent();
}

void FindFileWidget::initLayout() {
    QGridLayout *grid = new QGridLayout(this);
    QHBoxLayout *top = new QHBoxLayout;
    QVBoxLayout *main = new QVBoxLayout;
    QWidget *topWidget = new QWidget(this);
    QWidget *mainWidget = new QWidget(this);

    label = new QLabel("Find content : ");
    target = new QLineEdit();
    findButton = new QPushButton("Find");
    contents = new QTextEdit();
    backToMenu = new QPushButton("Back");
    backToMenu->setFixedSize(80,30);

    top->addWidget(label);
    top->addWidget(target);
    top->addWidget(findButton);

    topWidget->setLayout(top);
    main->addWidget(topWidget);
    main->addWidget(contents);
    mainWidget->setLayout(main);

    grid->addWidget(backToMenu, 0,0);
    grid->addWidget(mainWidget, 1,0);

    setLayout(grid);
}

void FindFileWidget::bindEvent() {
    connect(findButton, &QPushButton::clicked, this, [this]() {
        findContents();
    });
}

void FindFileWidget::findContents() {
    QString targetString = target->text();
    QString result = "";
    if(targetString.length() == 0) {
        ResultModal *resultModal = new ResultModal(this, "Please Enter the Text");
        resultModal->openModal();
        return;
    }
    int index = currentFileContents.indexOf(targetString, 0);
    while (index >= 0){
        result.append(currentFileContents.mid(index, targetString.length()));
        index = currentFileContents.indexOf(targetString, index + targetString.length());
    }

    if(result.length() == 0){
        ResultModal *modal = new ResultModal(this, "Not Found");
        modal->openModal();
        return;
    }
    contents->setText(result);
}