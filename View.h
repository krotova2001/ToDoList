//класс визуального отображения списка дел 
#pragma once
#include <iostream>
#include <cstdlib> // Для работы с функцией system()
using namespace std;

class View
{
public:
	View() //определим первоначальрные настройки в отображении
	{
		setlocale(LC_ALL, "Russian");
	}
	
	void Show_menu(); //рисование общего меню
	void Show_menu_1(); // первый пункт меню - просмотр
	void Show_menu_2(); // редактирование дел
	void Show_menu_3(); // поиск дел
	void Show_today(); // показать список дел на сегодня 
	void Show_manual(); // показать справку
	void Show_about(); // показать информацию о разработке
	
	~View()
	{
		system("cls");
		cout << "\nПОКА!!!\n";
	}
};

