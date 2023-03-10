//
// Created by 김현욱 on 2023/03/10.
//

#ifndef DATABASE_PROJECT_FILECONTENTWIDGET_H
#define DATABASE_PROJECT_FILECONTENTWIDGET_H


#include <QTextEdit>
#include <QBoxLayout>
#include <QFile>

class FileContentWidget : public QWidget{
    Q_OBJECT
public:
    FileContentWidget(QWidget *parent= nullptr, QString fileContent="No Content");
    QTextEdit *fileContentBox;

    void printFileContent(QFile *file);

private:

};


#endif //DATABASE_PROJECT_FILECONTENTWIDGET_H
