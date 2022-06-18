#include "Controller.h"

void Controller::Menu()
{
    {
        //здесь мы создаем систему ввода ответов при работе с многоуровневым меню, и само многоуровневое меню
        int choise, choise1, choise2, choise3, choise4, choise5; // заранее создадим возможные переменные дл€ ввода 
        string s; // строка дл€ поиска
        do {
            View::Show_menu(); //основное меню
            cin >> choise; // берем выбор
            switch (choise)
            {
            case 1:
                View::Show_menu_1(); // вложенное меню - ѕросмотр
                cin >> choise1;
                switch (choise1)
                {
                case 1: // сегодн€
                    break;
                case 2: // недел€
                    break;
                case 3: // мес€ц
                    break;
                case 4: // все дела
                    Model_base::Show_all();
                    break;
                default:
                    break;
                }
                break;
            case 2:
                View::Show_menu_2(); // –едактирование
                cin >> choise5;
                switch (choise5)
                {
                case 1:
                    Model_base::Add(); // добавление нового дела
                    break;
                case 2:
                    View::Show_menu_22(); // редактирование существующего дела
                    cin >> s;
                    if (s == "0")
                        break;
                    Model_base::Edit(s);
                case 3:
                    Model_base::Delete(); // добавление нового дела
                    break;
                default:
                    break;
                }
                break;
            case 3:
                View::Show_menu_3(); // ѕоиск дела
                cin >> choise3;
                switch (choise3)
                {
                case 1:
                    cout << "¬ведите ID дела либо название, либо описание\n";
                    cin >> s;
                    Model_base::Search(s);
                    system("pause");
                    break;
                case 2:
                    Model_base::Search_date();
                    system("pause");
                    break;
                default:
                    break;
                }
                break;
            case 4:
                View::Show_manual(); // ѕоказать справку
                system("pause");
                break;
            case 5:
                View::Show_about(); // –аздел "ќ программе"
                system("pause");
                break;
            default:
                break;
            }
        } while (choise != 0);
    }
}
