//класс визуального отображения списка дел 
#pragma once
#include <iostream>
using namespace std;

class View
{
public:
	View() //определим первоначальрные настройки в отображении
	{
		setlocale(LC_ALL, "Russian");
	}
	
	void Show_menu(); //рисование общего меню
	void Show_today(); // показать список дел на сегодня 
	void Show_intro(); // показать приветствие
	void Show_manual(); // показать справку

};

