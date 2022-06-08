#pragma once
#include "Model_base.h"
#include "View.h"
#include <iostream>
#include <string>
using namespace std;
class Controller
{
public:
    
    void Menu() // обработка ввода меню
    {
        View::Show_menu();
        int choise;
        do {
            cin >> choise; // берем выбор
            switch (choise)
            {
            case 1:
                View::Show_menu_1();
                break;
            case 2:
                View::Show_menu_2();
                break;
            case 3:
                View::Show_menu_3();
                break;
            case 4:
                View::Show_manual();
                break;
            case 5:
                View::Show_about();
                break;
            default:
                break;
            }
        } while (choise != 0);
    }
};

