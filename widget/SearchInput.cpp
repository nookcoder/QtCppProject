//
// Created by 김현욱 on 2023/03/10.
//

#include <iostream>
#include "SearchInput.h"

SearchInput::SearchInput(QWidget *parent): QWidget(parent) {
    initLayout();
    bindEvent();
}

void SearchInput::initLayout() {
    QWidget *main = new QWidget(this);
    QLabel *label = new QLabel("File name : ");
    edit = new QLineEdit();
    searchButton = new QPushButton("Search");
    backToMenu = new QPushButton("Back");
    backToMenu->setFixedSize(100,50);
    QGridLayout *grid = new QGridLayout;

    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->addWidget(label);
    hLayout->addWidget(edit);
    hLayout->addWidget(searchButton);
    main->setLayout(hLayout);

    grid->addWidget(backToMenu, 0,0 );
    grid->addWidget(main,1,0);

    setLayout(grid);
}

void SearchInput::bindEvent(){
    connect(searchButton, &QPushButton::clicked, this, [this](){
        if(edit->text().length() == 0){
            ResultModal *const pModal = new ResultModal(this,"Please Enter filename");
            pModal->openModal();
            return;
        }
        currentFile = loadFile(edit);
    });
}

QFile *SearchInput::loadFile(QLineEdit *edit) {
    searchResult = edit->text();
    qDebug() << searchResult;
    QFile *file = new QFile(searchResult);
    if(file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        ResultModal *const pModal = new ResultModal(this,"Success Loading File");
        pModal->openModal();
        QTextStream in(file);
        in.setEncoding(QStringConverter::Utf8);
        currentFileContents = in.readAll();
        return file;
    }

    currentFileContents = "Fail Loading File";
    ResultModal *const pModal = new ResultModal(this,"Fail Loading File");
    pModal->openModal();
    return new QFile();
}
