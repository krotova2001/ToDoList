//класс визуального отображения списка дел 
#pragma once
#include <iostream>
#include <cstdlib> // Для работы с функцией system()
#include "Model_base.h"
using namespace std;

static class View
{
public:
	View() //определим первоначальрные настройки в отображении
	{
		setlocale(LC_ALL, "Russian");
	}
	
	static void Show_menu(); //рисование общего меню
	static void Show_menu_1(); // первый пункт меню - просмотр
	static void Show_menu_2(); // редактирование дел
	static void Show_menu_22(); //подменю редактирования дела
	static void Show_menu_3(); // поиск дел
	static void Show_today(); // показать список дел на сегодня 
	static void Show_manual(); // показать справку
	static void Show_about(); // показать информацию о разработке
	static void Show_delo(Model A); // показать информацию об одном деле

	
	~View()
	{
		//system("cls");
		cout << "\nПОКА!!!\n";
	}
};

