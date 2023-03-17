//
// Created by 김현욱 on 2023/03/17.
//

#include "AppendContentWidget.h"
AppendContentWidget::AppendContentWidget(QWidget *parent) : QWidget(parent){
    initLayout();
    connect(insert, &QPushButton::clicked, this, [this](){
        this-> insertNewContents();
    });
}

void AppendContentWidget::initLayout() {
    contents->setText(currentFileContents);
    contents->setReadOnly(true);
    back->setFixedSize(80, 30);

    QWidget *inputWidget = new QWidget;
    QHBoxLayout *inputLayout = new QHBoxLayout;
    QWidget *mainWidget = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QWidget *root = new QWidget;
    QGridLayout *grid = new QGridLayout;

    // 입력하는 곳 레이아웃 설정
    inputLayout->addWidget(label);
    inputLayout->addWidget(value);
    inputLayout->addWidget(insert);
    inputWidget->setLayout(inputLayout);

    // input Widget 과 파일 내용 표시할 레이아웃 설정
    mainLayout->addWidget(inputWidget);
    mainLayout->addWidget(contents);
    mainWidget->setLayout(mainLayout);

    // 메인 화면 설정
    grid->addWidget(back, 0, 0);
    grid->addWidget(mainWidget, 1, 0);
    setLayout(grid);
}

void AppendContentWidget::insertNewContents() {
    const QString &string = value->text();
    currentFileContents.push_back("\n" + string);
    contents->setText(currentFileContents);
    value->setText("");
}