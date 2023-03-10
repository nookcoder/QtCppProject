//
// Created by 김현욱 on 2023/03/10.
//

#include <iostream>
#include "SearchInput.h"

SearchInput::SearchInput(QWidget *parent): QWidget(parent) {
//    m_parent = parent;
    delete layout();
    searchResult = "";
    edit = new QLineEdit(this);
    searchButton = new QPushButton("Search");
    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->addWidget(edit);
    hLayout->addWidget(searchButton);
    setLayout(hLayout);
//    connect(searchButton, &QPushButton::clicked, this, [=]() {
//        const QString &filename = SearchInput::getFilenameFromSearchBox(edit);
////        m_parent->currentFile = loadFile(filename);
//    });
}

void SearchInput::getFilenameFromSearchBox(QLineEdit *edit) {
    searchResult = edit->text();
    std::cout << "From getFilename : "  << edit->text().toStdString() << "\n";
}

QFile *SearchInput::loadFile(QLineEdit *edit) {
    searchResult = edit->text();
    qDebug() << searchResult;
    QFile *file = new QFile(searchResult);
    if(file->open(QIODevice::ReadOnly)) {
        ResultModal *const pModal = new ResultModal(this,"Success Loading File");
        pModal->openModal();
        qDebug() << "Success";
        return file;
    }

    qDebug() << "Fail";
    ResultModal *const pModal = new ResultModal(this,"Fail Loading File");
    pModal->openModal();
    return new QFile();
}
