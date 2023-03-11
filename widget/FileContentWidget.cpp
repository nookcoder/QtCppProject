//
// Created by 김현욱 on 2023/03/10.
//

#include "FileContentWidget.h"
FileContentWidget::FileContentWidget(QWidget *parent, QString fileContent) : QWidget(parent){
    initLayout();

    fileContentBox->setText(fileContent);
}

void FileContentWidget::initLayout() {
    QGridLayout *grid = new QGridLayout;
    QWidget *main = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(this);

    fileContentBox = new QTextEdit(this);
    backToMenu = new QPushButton("Back");
    backToMenu->setFixedSize(80, 30);

    fileContentBox->setReadOnly(true);
    layout->addWidget(fileContentBox);

    main->setLayout(layout);
    grid->addWidget(backToMenu, 0,0);
    grid->addWidget(main, 1,0);

    setLayout(grid);
}