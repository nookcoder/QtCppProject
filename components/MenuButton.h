//
// Created by 김현욱 on 2023/03/11.
//

#ifndef DATABASE_PROJECT_MENUBUTTON_H
#define DATABASE_PROJECT_MENUBUTTON_H

#include <QPushButton>
class MenuButton : public QPushButton {
public:
    MenuButton(QWidget *parent= nullptr, QString buttonText = "");
};


#endif //DATABASE_PROJECT_MENUBUTTON_H
