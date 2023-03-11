//
// Created by 김현욱 on 2023/03/11.
//

#ifndef DATABASE_PROJECT_UPDATEFILE_H
#define DATABASE_PROJECT_UPDATEFILE_H


#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QBoxLayout>
#include "../global.h"

class UpdateFile : public QWidget {
Q_OBJECT
public:
    UpdateFile(QWidget *parent);

private slots:
private:
    QLabel *targetLabel = new QLabel("Want to modify");
    QLabel *renameLabel = new QLabel("how to modify");

    QLineEdit *target = new QLineEdit();
    QLineEdit *rename = new QLineEdit();

    QPushButton *runButton = new QPushButton("Change");

    QTextEdit *fileContent;

    void initLayout();
};


#endif //DATABASE_PROJECT_UPDATEFILE_H
