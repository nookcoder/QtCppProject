//
// Created by 김현욱 on 2023/03/11.
//

#include "UpdateFile.h"

UpdateFile::UpdateFile(QWidget *parent) : QWidget(parent){
    initLayout();
}

// 레이아웃 초기화
void UpdateFile::initLayout() {
    QVBoxLayout *parentLayout = new QVBoxLayout; 
    QHBoxLayout *targetLayout = new QHBoxLayout;
    QHBoxLayout *renameLayout = new QHBoxLayout;
    QWidget *targetWidget = new QWidget;
    QWidget *renameWidget = new QWidget;
    fileContent = new QTextEdit(this->parentWidget());
    fileContent->setText(currentFileContents);
    
    targetLayout->addWidget(targetLabel); 
    targetLayout->addWidget(target);
    targetWidget->setLayout(targetLayout);
    
    renameLayout->addWidget(renameLabel); 
    renameLayout->addWidget(rename); 
    renameWidget->setLayout(renameLayout);

    parentLayout->addWidget(targetWidget);
    parentLayout->addWidget(renameWidget);
    parentLayout->addWidget(runButton);
    parentLayout->addWidget(fileContent);

    this->setLayout(parentLayout);
}