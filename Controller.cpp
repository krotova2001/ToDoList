#include "Controller.h"

void Controller::Menu()
{
    {
        //����� �� ������� ������� ����� ������� ��� ������ � �������������� ����, � ���� �������������� ����
        int choise, choise1, choise2, choise3, choise4, choise5; // ������� �������� ��������� ���������� ��� ����� 
        string s; // ������ ��� ������
        do {
            View::Show_menu(); //�������� ����
            cin >> choise; // ����� �����
            switch (choise)
            {
            case 1:
                View::Show_menu_1(); // ��������� ���� - ��������
                cin >> choise1;
                switch (choise1)
                {
                case 1: // �������
                    break;
                case 2: // ������
                    break;
                case 3: // �����
                    break;
                case 4: // ��� ����
                    Model_base::Show_all();
                    break;
                default:

                    break;
                }
                break;
            case 2:
                View::Show_menu_2(); // ��������������
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
                View::Show_menu_3(); // ����� ����
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
                View::Show_manual(); // �������� �������
                system("pause");
                break;
            case 5:
                View::Show_about(); // ������ "� ���������"
                system("pause");
                break;
            default:
                break;
            }
        } while (choise != 0);
    }
}
