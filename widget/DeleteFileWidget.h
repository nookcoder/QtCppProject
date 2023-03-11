//
// Created by 김현욱 on 2023/03/11.
//

#ifndef DATABASE_PROJECT_DELETEFILEWIDGET_H
#define DATABASE_PROJECT_DELETEFILEWIDGET_H


#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include "../modal/ResultModal.h"
#include "../global.h"

class DeleteFileWidget : public QWidget{
Q_OBJECT
public:
    DeleteFileWidget(QWidget *parent = nullptr);
    QPushButton *back = new QPushButton("Back");

private slots:
    void deleteFileContents(QString target);

private:
    QLabel *targetLabel = new QLabel("Want to Delete");
    QLineEdit *target = new QLineEdit();
    QPushButton *deleteButton = new QPushButton("Delete");
    QTextEdit *fileContent;
    QString tempContents = currentFileContents;

    void initLayout();
};


#endif //DATABASE_PROJECT_DELETEFILEWIDGET_H
