//
// Created by 김현욱 on 2023/03/10.
//

#ifndef DATABASE_PROJECT_FILECONTENTWIDGET_H
#define DATABASE_PROJECT_FILECONTENTWIDGET_H


#include <QTextEdit>
#include <QBoxLayout>
#include <QFile>
#include <QPushButton>

class FileContentWidget : public QWidget{
    Q_OBJECT
public:
    FileContentWidget(QWidget *parent= nullptr, QString fileContent="No Content");
    QTextEdit *fileContentBox;
    QPushButton *backToMenu;

private:
    void initLayout();
};


#endif //DATABASE_PROJECT_FILECONTENTWIDGET_H
