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
        //здесь мы создаем систему ввода ответов при работе с многоуровневым меню, и само многоуровневое меню
        int choise, choise1, choise2, choise3, choise4; // заранее создадим возможные переменные для ввода 
        string search; // строка для поиска
        do {
            View::Show_menu(); //основное меню
            cin >> choise; // берем выбор
            switch (choise)
            {
            case 1:
                View::Show_menu_1(); // вложенное меню - Просмотр
                cin >> choise1;
                switch (choise1)
                {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                default:

                    break;
                }
                break;
            case 2:
                View::Show_menu_2(); // Редактирование
                cin >> search;
                break;
            case 3:
                View::Show_menu_3(); // Поиск дела
                cin >> choise3;
                switch (choise3)
                    {
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    default:
                        break;
                    }
                break;
            case 4:
                View::Show_manual(); // Показать справка
                system("pause");
                break;
            case 5:
                View::Show_about(); // Раздел "О программе"
                system("pause");
                break;
            default:
                break;
            }
        } while (choise != 0);
    }
};

