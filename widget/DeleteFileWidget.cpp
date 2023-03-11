//
// Created by 김현욱 on 2023/03/11.
//

#include <QVBoxLayout>
#include "DeleteFileWidget.h"

DeleteFileWidget::DeleteFileWidget(QWidget *parent) : QWidget(parent){
    initLayout();

    connect(deleteButton, &QPushButton::clicked, this, [this]() {
        if (target->text().length() == 0) {
            ResultModal *modal = new ResultModal(this, "Please, Enter the Value");
            modal->openModal();
            return;
        }

        this->deleteFileContents(target->text());
    });
}

void DeleteFileWidget::initLayout() {
    QVBoxLayout *parentLayout = new QVBoxLayout;
    QHBoxLayout *targetLayout = new QHBoxLayout;

    QWidget *targetWidget = new QWidget;

    fileContent = new QTextEdit(this->parentWidget());
    fileContent->setText(tempContents);
    fileContent->setReadOnly(true);

    targetLayout->addWidget(targetLabel);
    targetLayout->addWidget(target);
    targetWidget->setLayout(targetLayout);

    parentLayout->addWidget(targetWidget);
    parentLayout->addWidget(deleteButton);
    parentLayout->addWidget(fileContent);


    this->setLayout(parentLayout);
}

void DeleteFileWidget::deleteFileContents(QString target) {
    int index = tempContents.indexOf(target, 0);

    while (index >= 0) {
        tempContents.replace(index, target.length(), "");
        index = tempContents.indexOf(target, index);
    }

    fileContent->setText(tempContents);
    currentFileContents = tempContents;
}