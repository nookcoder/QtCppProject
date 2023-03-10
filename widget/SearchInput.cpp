//
// Created by 김현욱 on 2023/03/10.
//

#include <iostream>
#include "SearchInput.h"

SearchInput::SearchInput(QWidget *parent): QWidget(parent) {
//    m_parent = parent;
    delete layout();
    searchResult = "";
    edit = new QLineEdit();
    searchButton = new QPushButton("Search");
    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->addWidget(edit);
    hLayout->addWidget(searchButton);
    setLayout(hLayout);
}

QFile *SearchInput::loadFile(QLineEdit *edit) {
    searchResult = edit->text();
    QFile *file = new QFile(searchResult);
    if(file->open(QIODevice::ReadOnly)) {
        ResultModal *const pModal = new ResultModal(this,"Success Loading File");
        pModal->openModal();
        return file;
    }

    ResultModal *const pModal = new ResultModal(this,"Fail Loading File");
    pModal->openModal();
    return new QFile();
}
