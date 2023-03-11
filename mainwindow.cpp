#include <QVBoxLayout>
#include "mainwindow.h"
#include "widget/SearchInput.h"
#include "widget/ButtonGroup.h"
#include "widget/FileContentWidget.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent) {
    // init Field
    rightWidget = new QWidget(this);
    rightLayout = new QVBoxLayout(this);
    currentFile = new QFile();

    // init Widget
    searchWidget = new SearchInput();
    fileContentWidget = new FileContentWidget();

    // set layout of main
    setInitLayout();

}

// 초기 레이아웃 셋팅
void MainWindow::setInitLayout() {
    ButtonGroup *buttonGroup = new ButtonGroup(this, searchWidget, fileContentWidget);

    QWidget *const main = new QWidget(this);
    QHBoxLayout *const hBoxLayout = new QHBoxLayout;
    rightWidget->setLayout(rightLayout);
    hBoxLayout->addWidget(buttonGroup);
    hBoxLayout->addWidget(rightWidget);
    main->setLayout(hBoxLayout);
    this->setCentralWidget(main);
}

// 위젯 바꾸기
void MainWindow::clearMainWidget() {
    while (QLayoutItem *item = this->rightWidget->layout()->takeAt(0)){
        delete item->widget();
        delete item;
    }
}

//QTextEdit *fileContentTextEdit = new QTextEdit("jfjoasfjasiodjfioasjdfoi");
//fileContentTextEdit->setReadOnly(true);
//connect(fileLoadButton, &FileLoadButton::clicked, fileLoadButton, [=]() {
//QFile *pFile = fileLoadButton->loadFile(searchWidget->searchResult);
//if(pFile->exists()) {
//QTextStream in(pFile);
//QString fileContents = in.readAll();
//fileContentTextEdit->setText(fileContents);
//} else {
//cout << "fail";
//}
//
//});
//
//vboxlayout->addWidget(fileLoadButton);
//vboxlayout->addWidget(fileContentTextEdit);
//hBoxLayout->addLayout(vboxlayout);
//hBoxLayout->addWidget(searchWidget);
//
//main->setLayout(hBoxLayout);
//this->setCentralWidget(main);