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
    QPushButton *fileLoad = new MenuButton( this, "FileLoad");
    QPushButton *filePrint = new MenuButton(this, "FilePrint");
    QPushButton *fileUpdate = new MenuButton(this, "FileUpdate");
    QPushButton *fileDelete = new MenuButton(this,"FileDelete");
    QPushButton *fileFind = new MenuButton(this, "FileFind");
    QPushButton *fileSave = new MenuButton(this, "FileSave");
    QPushButton *exit = new MenuButton(this, "Exit");
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
        if(this->m_parent->currentFile->isOpen()){
            this->printFileContent(this->m_contentWidget,this->m_parent->currentFile);
        }
        this->m_parent->rightLayout->addWidget(this->m_contentWidget);
    }

    this->m_parent->rightWidget->update();
}
