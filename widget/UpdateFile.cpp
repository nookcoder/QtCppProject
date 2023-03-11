//
// Created by 김현욱 on 2023/03/11.
//

#include "UpdateFile.h"

UpdateFile::UpdateFile(QWidget *parent) : QWidget(parent) {
    initLayout();

    connect(changeButton, &QPushButton::clicked, this, [this]() {
        if (target->text().length() == 0) {
            ResultModal *modal = new ResultModal(this, "Please, Enter the Value");
            modal->openModal();
            return;
        }
        UpdateFile::changeFileContents(target->text(), rename->text());
    });
}

void UpdateFile::changeFileContents(QString target, QString rename) {
    int index = tempContents.indexOf(target, 0);

    while (index >= 0) {
        tempContents.replace(index, target.length(), rename);
        index = tempContents.indexOf(target, index + rename.length());
    }

    fileContent->setText(tempContents);
    currentFileContents = tempContents;
}

// 레이아웃 초기화
void UpdateFile::initLayout() {
    QGridLayout *grid = new QGridLayout;
    QWidget *main = new QWidget(this);

    QVBoxLayout *parentLayout = new QVBoxLayout;
    QHBoxLayout *targetLayout = new QHBoxLayout;
    QHBoxLayout *renameLayout = new QHBoxLayout;
    QWidget *targetWidget = new QWidget;
    QWidget *renameWidget = new QWidget;
    backToMenu->setFixedSize(80,30);

    fileContent = new QTextEdit(this->parentWidget());
    fileContent->setText(tempContents);
    fileContent->setReadOnly(true);

    targetLayout->addWidget(targetLabel);
    targetLayout->addWidget(target);
    targetWidget->setLayout(targetLayout);

    renameLayout->addWidget(renameLabel);
    renameLayout->addWidget(rename);
    renameWidget->setLayout(renameLayout);

    parentLayout->addWidget(targetWidget);
    parentLayout->addWidget(renameWidget);
    parentLayout->addWidget(changeButton);
    parentLayout->addWidget(fileContent);

    main->setLayout(parentLayout);
    grid->addWidget(backToMenu, 0,0);
    grid->addWidget(main, 1, 0);

    this->setLayout(grid);
}