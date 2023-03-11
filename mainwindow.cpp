#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent) {
    initLayout();
    bindButtonGroupEvent();

}

void MainWindow::initLayout() {
    buttonGroup = new ButtonGroup(this);
    main = new QWidget(this);
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(buttonGroup);
    main->setLayout(mainLayout);
    setCentralWidget(main);
};

// 메뉴로 다시 돌아을 때 view, event 초기화
void MainWindow::backToMenu() {
    clearMainWidget();
    buttonGroup = new ButtonGroup(this);
    bindButtonGroupEvent();
    mainLayout->addWidget(buttonGroup);
    mainLayout->update();
}

// 메뉴 버튼 이벤트 맵핑
void MainWindow::bindButtonGroupEvent() {
    bindMenuButtonEvent(buttonGroup->fileLoad, "load");
    bindMenuButtonEvent(buttonGroup->filePrint, "print");
    bindMenuButtonEvent(buttonGroup->fileUpdate, "update");
    bindMenuButtonEvent(buttonGroup->fileDelete, "delete");
    bindMenuButtonEvent(buttonGroup->fileFind, "find");
    bindMenuButtonEvent(buttonGroup->fileSave, "save");
    connect(buttonGroup->exit, &QPushButton::clicked, this, &QMainWindow::close);
}

// 메뉴 버튼 이벤트 맵핑
void MainWindow::bindMenuButtonEvent(QPushButton *button, QString menu) {
    connect(button, &QPushButton::clicked, this, [this, menu]() {
        changeMenu(menu);
    });
}

// 뒤로 가기 기능 맵핑
void MainWindow::bindBackToMenuEvent(QPushButton *button) {
    connect(button, &QPushButton::clicked, this, [this]() {
        backToMenu();
    });
}

// 화면 지우기
void MainWindow::clearMainWidget() {
    while (QLayoutItem *item = mainLayout->takeAt(0)) {
        delete item->widget();
        delete item;
    }
}

// 메뉴 이동
void MainWindow::changeMenu(QString menu) {
    this->clearMainWidget();

    if (menu == "load") {
        searchWidget = new SearchInput(this);
        bindBackToMenuEvent(searchWidget->backToMenu);
        bindBackToMenuEvent(searchWidget->searchButton);
        mainLayout->addWidget(this->searchWidget);
    } else if (menu == "print") {
        // init Widget && add
        fileContentWidget = new FileContentWidget(this, currentFileContents);
        bindBackToMenuEvent(fileContentWidget->backToMenu);
        mainLayout->addWidget(this->fileContentWidget);
    } else if (menu == "update") {
        updateFileWidget = new UpdateFile(this);
        bindBackToMenuEvent(updateFileWidget->backToMenu);
        mainLayout->addWidget(updateFileWidget);
    } else if (menu == "delete") {
        deleteFileWidget = new DeleteFileWidget(this);
        bindBackToMenuEvent(deleteFileWidget->back);
        this->mainLayout->addWidget(deleteFileWidget);
    } else if (menu == "find") {
        findFileWidget = new FindFileWidget(this);
        bindBackToMenuEvent(findFileWidget->backToMenu);
        this->mainLayout->addWidget(findFileWidget);
    } else if (menu == "save") {
        saveFileWidget = new SaveFileWidget(this);
        bindBackToMenuEvent(saveFileWidget->backToMenu);
        bindBackToMenuEvent(saveFileWidget->save);
        this->mainLayout->addWidget(saveFileWidget);
    }

    this->mainLayout->update();
}

