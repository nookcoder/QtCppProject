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
    // 현재 파일이 제대로 열려있는 지 확인
    if(!currentFile || !currentFile->isOpen()) {
        ResultModal *modal = new ResultModal(this, "Please, Open a File Before Save");
        modal->openModal();
        return;
    }
    const QString &filename = currentFile->fileName();
    currentFile->close();
    currentFile = new QFile(filename);

    // 쓰기 모드로 파일 다시 열기
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