//
// Created by 김현욱 on 2023/03/11.
//

#ifndef DATABASE_PROJECT_FINDFILEWIDGET_H
#define DATABASE_PROJECT_FINDFILEWIDGET_H


#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QBoxLayout>
#include "../global.h"
#include "../modal/ResultModal.h"

class FindFileWidget : public QWidget{
public:
    FindFileWidget(QWidget *parent);
    QPushButton *backToMenu;

private:
    QLabel *label;
    QPushButton *findButton;
    QLineEdit *target;
    QTextEdit *contents;

    void initLayout();
    void bindEvent();
    void findContents();
};


#endif //DATABASE_PROJECT_FINDFILEWIDGET_H
