//
// Created by 김현욱 on 2023/03/11.
//

#include "MenuButton.h"
MenuButton::MenuButton(QWidget *parent, QString buttonText) : QPushButton(parent){
    setFixedSize(100,50);
    setText(buttonText);
}