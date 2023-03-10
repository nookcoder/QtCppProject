//
// Created by 김현욱 on 2023/03/10.
//

#ifndef DATABASE_PROJECT_RESULTMODAL_H
#define DATABASE_PROJECT_RESULTMODAL_H

#include <QDialog>
#include <QStandardItemModel>
#include <QLabel>
#include <QBoxLayout>

using namespace std;
class ResultModal : public QDialog {
    Q_OBJECT
public:
    ResultModal(QWidget *parent, QString modalContent);
public slots:
    void openModal();
private:
    QStandardItemModel *modal;
};


#endif //DATABASE_PROJECT_RESULTMODAL_H
