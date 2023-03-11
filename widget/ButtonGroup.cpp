//
// Created by 김현욱 on 2023/03/10.
//

#include "ButtonGroup.h"
ButtonGroup::ButtonGroup(QWidget *parent
                         ) : QWidget(parent) {
    // init
    initLayout();
}

void ButtonGroup::initLayout() {
    // create Buttons For Menu
    fileLoad = new MenuButton( this, "FileLoad");
    filePrint = new MenuButton(this, "FilePrint");
    fileUpdate = new MenuButton(this, "FileUpdate");
    fileDelete = new MenuButton(this,"FileDelete");
    fileFind = new MenuButton(this, "FileFind");
    fileSave = new MenuButton(this, "FileSave");
    exit = new MenuButton(this, "Exit");

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