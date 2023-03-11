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

    initLayout();
    bindButtonEvent();
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

void ButtonGroup::bindButtonEvent() {
    connect(fileLoad, &QPushButton::clicked, this, [this]() {
        ButtonGroup::changeMenu("load");
    }); // file load
    connect(filePrint, &QPushButton::clicked, this, [this]() {
        ButtonGroup::changeMenu("print");
    }); // file print
    connect(fileUpdate, &QPushButton::clicked, this, [this](){
        ButtonGroup::changeMenu("update");
    }); // file Update
    connect(fileDelete, &QPushButton::clicked, this, [this]() {
        ButtonGroup::changeMenu("delete");
    }); // file Delete
    connect(fileSave, &QPushButton::clicked, this, [this](){
        ButtonGroup::saveNewFile();
    }); // file save
}

void ButtonGroup::saveNewFile() {
    // todo : 파일 이름 변경 기능 추가
    currentFile->resize(0); // 파일 내용 초기화
    QTextStream stream(currentFile); // 파일 작업 시작
    stream << currentFileContents; // 파일 내용 추가
    currentFile->flush(); // 파일 내용 저장
}


void ButtonGroup::changeMenu(QString menu) {
    this->m_parent->clearMainWidget();

    if (menu == "load"){
        this->m_searchWidget = new SearchInput(this->m_parent);
        // 검색 버튼 이벤트 추가
        connect(this->m_searchWidget->searchButton, &QPushButton::clicked, this->m_parent, [this](){
            currentFile = m_searchWidget->loadFile(m_searchWidget->edit);
        });
        this->m_parent->rightLayout->addWidget(this->m_searchWidget);
    }

    else if(menu == "print"){
        // init Widget && add
        this->m_contentWidget = new FileContentWidget(this->m_parent, currentFileContents);
        this->m_parent->rightLayout->addWidget(this->m_contentWidget);
    }


    else if(menu == "update"){
        UpdateFile *updateFileWidget = new UpdateFile(this->m_parent);
        this->m_parent->rightLayout->addWidget(updateFileWidget);
    }

    else if(menu == "delete") {
        DeleteFileWidget *widget = new DeleteFileWidget(this->parentWidget());
        this->m_parent->rightLayout->addWidget(widget);
    }

    this->m_parent->rightWidget->update();
}
