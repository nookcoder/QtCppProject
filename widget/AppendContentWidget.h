//
// Created by 김현욱 on 2023/03/17.
//

#ifndef DATABASE_PROJECT_APPENDCONTENTWIDGET_H
#define DATABASE_PROJECT_APPENDCONTENTWIDGET_H


#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QTextEdit>
#include "../global.h"
class AppendContentWidget : public QWidget{
    Q_OBJECT
public:
    AppendContentWidget(QWidget *parent);
    QPushButton *back = new QPushButton("Back");

private:
    QLabel *label = new QLabel("Enter the Value");
    QLineEdit *value = new QLineEdit();
    QPushButton *insert = new QPushButton("Add");

    QTextEdit *contents = new QTextEdit();
    void initLayout();
private slots:
    void insertNewContents();
};


#endif //DATABASE_PROJECT_APPENDCONTENTWIDGET_H
