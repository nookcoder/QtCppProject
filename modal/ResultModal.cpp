//
// Created by 김현욱 on 2023/03/10.
//

#include "ResultModal.h"
//ResultModal::ResultModal(string modalContent):QTableView {
//    this->modal = new QStandardItemModel();
//
//}

ResultModal::ResultModal(QWidget *parent,QString modalContent): QDialog(parent) {
    QLabel *const content = new QLabel(modalContent);
    QVBoxLayout *boxLayout =new QVBoxLayout;
    boxLayout->addWidget(content);
    this->setWindowModality(Qt::ApplicationModal);
    this->setLayout(boxLayout);
}

void ResultModal::openModal() {
    this->exec();
}
