//
// Created by 김현욱 on 2023/03/11.
//

#ifndef DATABASE_PROJECT_SAVEFILEWIDGET_H
#define DATABASE_PROJECT_SAVEFILEWIDGET_H


#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QBoxLayout>
#include "../global.h"
#include "../modal/ResultModal.h"

class SaveFileWidget : public QWidget{
public:
    SaveFileWidget(QWidget *parent);
    QPushButton *save = new QPushButton("save");
    QPushButton *backToMenu = new QPushButton("Back");

private:
    QLabel *label = new QLabel("new file name : ");
    QLineEdit *newFilename;

    void initLayout();
    void bindEvent();
private slots:
    void saveFile();
};


#endif //DATABASE_PROJECT_SAVEFILEWIDGET_H
