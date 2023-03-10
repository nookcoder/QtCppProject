cmake_minimum_required(VERSION 3.24)
project(database_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH /Users/wook/Development/qt/6.4.2/macos/lib/cmake)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(database_project
        main.cpp
        mainwindow.cpp
        mainwindow.h
        file-load/components/FileLoadButton.cpp
        file-load/components/FileLoadButton.h
        widget/SearchInput.cpp
        widget/SearchInput.h
        modal/ResultModal.cpp
        modal/ResultModal.h
        widget/ButtonGroup.cpp
        widget/ButtonGroup.h
        widget/FileContentWidget.cpp
        widget/FileContentWidget.h
        components/MenuButton.cpp components/MenuButton.h)
target_link_libraries(database_project
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

