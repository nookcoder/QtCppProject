//
// Created by 김현욱 on 2023/03/10.
//

#include "ButtonGroup.h"
ButtonGroup::ButtonGroup(MainWindow *parent,
                         SearchInput *searchWidget,
                         FileContentWidget *contentWidget
                         ) : QWidget() {
    // init
    m_parent = parent;
    m_searchWidget = searchWidget;
    m_contentWidget = contentWidget;


    // create Buttons For Menu
    QPushButton *fileLoad = new QPushButton("FileLoad", this);
    QPushButton *filePrint = new QPushButton("FilePrint", this);
    QPushButton *fileUpdate = new QPushButton("FileUpdate", this);
    QPushButton *fileDelete = new QPushButton("FileDelete", this);
    QPushButton *fileFind = new QPushButton("FileFind", this);
    QPushButton *fileSave = new QPushButton("FileSave", this);
    QPushButton *exit = new QPushButton("Exit", this);
    fileLoad->setFixedSize(100,50);
    filePrint->setFixedSize(100,50);
    fileUpdate->setFixedSize(100,50);
    fileDelete->setFixedSize(100,50);
    fileFind->setFixedSize(100,50);
    fileSave->setFixedSize(100,50);
    exit->setFixedSize(100,50);
    // add click event
    // file load
    connect(fileLoad, &QPushButton::clicked, fileLoad, [this]() {
        ButtonGroup::addMenuWidget("load");
    });
    // file print
    connect(filePrint, &QPushButton::clicked, filePrint, [this]() {
        ButtonGroup::addMenuWidget("print");
    });

    // set Layout
    vBoxLayout = new QVBoxLayout;

    vBoxLayout->addWidget(fileLoad);
    vBoxLayout->addWidget(filePrint);
    vBoxLayout->addWidget(fileUpdate);
    vBoxLayout->addWidget(fileDelete);
    vBoxLayout->addWidget(fileFind);
    vBoxLayout->addWidget(fileSave);
    vBoxLayout->addWidget(exit);

    setLayout(vBoxLayout);
}

void ButtonGroup::printFileContent(FileContentWidget *widget ,QFile *file) {
    QTextStream in(file);
    QString fileContents = in.readAll();
    widget->fileContentBox->setText(fileContents);
}

void ButtonGroup::addMenuWidget(QString menu) {
    this->m_parent->clearMainWidget();

    if (menu == "load"){
        this->m_searchWidget = new SearchInput(this->m_parent);
        if(this->m_searchWidget->edit == nullptr) {
            this->m_searchWidget->edit = new QLineEdit();
        }
        this->m_parent->bindEventOfSearchButton(this->m_searchWidget, this->m_parent);
        this->m_parent->rightLayout->addWidget(this->m_searchWidget);
    }

    else if(menu == "print"){
        this->m_contentWidget = new FileContentWidget();
        this->printFileContent(this->m_contentWidget,this->m_parent->currentFile);
        this->m_parent->rightLayout->addWidget(this->m_contentWidget);
    }

    this->m_parent->rightWidget->update();
}
