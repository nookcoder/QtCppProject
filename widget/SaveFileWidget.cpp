//
// Created by 김현욱 on 2023/03/11.
//

#include "SaveFileWidget.h"
SaveFileWidget::SaveFileWidget(QWidget *parent) : QWidget(parent){
    initLayout();
    bindEvent();
}

void SaveFileWidget::initLayout() {
    QGridLayout *grid = new QGridLayout;
    QHBoxLayout *mainLayout = new QHBoxLayout;
    QWidget *main = new QWidget(this);

    newFilename = new QLineEdit();
    backToMenu->setFixedSize(80,30);

    mainLayout->addWidget(label);
    mainLayout->addWidget(newFilename);
    mainLayout->addWidget(save);

    main->setLayout(mainLayout);
    grid->addWidget(backToMenu, 0,0);
    grid->addWidget(main, 1,0);
    setLayout(grid);
}

void SaveFileWidget::bindEvent() {
    connect(save, &QPushButton::clicked, this, [this]() {
        saveFile();
    });
}

void SaveFileWidget::saveFile() {
    const QString &filename = currentFile->fileName();
    currentFile->close();
    currentFile = new QFile(filename);
    if(currentFile->open(QIODevice::ReadWrite)) {
        currentFile->resize(0); // 파일 내용 초기화
        QTextStream stream(currentFile); // 파일 작업 시작

        stream << currentFileContents; // 파일 내용 추가
        currentFile->rename(newFilename->text());
        currentFile->flush(); // 파일 내용 저장
        currentFile->close();
        currentFileContents = "No Contents";

        ResultModal *modal = new ResultModal(this, "Success Save The File");
        modal->openModal();
    }
}