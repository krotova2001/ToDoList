#include "Controller.h"

void Controller::Menu()
{
    {
        //здесь мы создаем систему ввода ответов при работе с многоуровневым меню, и само многоуровневое меню
        int choise, choise1, choise2, choise3, choise4, choise5; // заранее создадим возможные переменные для ввода 
        string s; // строка для поиска
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
                case 1: // сегодня
                    break;
                case 2: // неделя
                    break;
                case 3: // месяц
                    break;
                case 4: // все дела
                    Model_base::Show_all();
                    break;
                default:

                    break;
                }
                break;
            case 2:
                View::Show_menu_2(); // Редактирование
                cin >> choise5;
                switch (choise5)
                {
                case 1:
                    Model_base::Add();
                    break;
                case 2:
                    View::Show_menu_22();
                    cin >> s;
                    if (s == "0")
                        break;
                    Model_base::Edit(s);
                default:
                    break;
                }
                break;
            case 3:
                View::Show_menu_3(); // Поиск дела
                cin >> choise3;
                switch (choise3)
                {
                case 1:
                    Model_base::Search();
                    break;
                case 2:
                    Model_base::Search_date();
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
}
