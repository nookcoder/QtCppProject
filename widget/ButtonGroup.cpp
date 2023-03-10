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

QString ButtonGroup::printFileContent(FileContentWidget *widget ,QFile *file) {
    QTextStream in(file);
    QString fileContents = in.readAll();
//    widget->fileContentBox->setText(fileContents);
    return fileContents;
}

void ButtonGroup::addMenuWidget(QString menu) {
    this->m_parent->clearMainWidget();

    if (menu == "load"){
        this->m_searchWidget = new SearchInput(this->m_parent);
        // 검색 버튼 이벤트 추가
        connect(this->m_searchWidget->searchButton, &QPushButton::clicked, this->m_parent, [this](){
            currentFile = m_searchWidget->loadFile(m_searchWidget->edit);
            this->is_Load = true;
        });
        this->m_parent->rightLayout->addWidget(this->m_searchWidget);
    }

    else if(menu == "print"){

        // 파일 새로운 거 검색 했을 때 파일 내용 set
        if (this->is_Load && currentFile->isOpen()) { // 파일 찾기 성공
            currentFileContents =  this->printFileContent(this->m_contentWidget, currentFile);
        } else if (this->is_Load && !currentFile->isOpen()) { // 파일 찾기 실패
            currentFileContents = "Fail Loading File";
        }
        this->is_Load = false;

        qDebug() << currentFileContents;
        this->m_contentWidget = new FileContentWidget(this->m_parent, currentFileContents);

        this->m_parent->rightLayout->addWidget(this->m_contentWidget);
    }

    this->m_parent->rightWidget->update();
}
