#include "View.h"
#include <iostream>
#include <iomanip> // это для красивых табличек
#include <ctime> // библиотека работы со временем
using namespace std;

void View::Show_menu() //главное меню
{
	system("cls"); // очистка экрана
	cout <<"\x1B[31m***********************СПИСОК ДЕЛ***********************\033[0m\t\t\n\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "Просмотр " << right << " 1\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "Редактирование " << right << " 2\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "Поиск " << right << " 3\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "Справка " << right << " 4\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "О программе " << right << " 5\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "Выход " << right << " 0\n\n";
}

void View::Show_menu_1()
{
	system("cls");
	cout << "\x1B[31m***********************ПРОСМОТР***********************\033[0m\t\t\n\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "На сегодня " << right << " 1\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "На неделю " << right << " 2\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "На месяц " << right << " 3\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "Все дела " << right << " 4\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "Назад " << right << " 0\n\n";
}

void View::Show_menu_2()
{
	system("cls");
	cout << "\x1B[31m***********************РЕДАКТИРОВАНИЕ***********************\033[0m\t\t\n\n";
	cout << "Введите ID дела либо название, либо описание\n";
	cout << "Либо введите 0 для выхода в меню\n";
}

void View::Show_menu_3()
{
	system("cls");
	cout << "\x1B[31m***********************ПОИСК***********************\033[0m\t\t\n\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "По названию/описанию/ID " << right << " 1\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "По дате " << right << " 2\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "Назад " << right << " 0\n\n";

}

void View::Show_today()
{
	system("cls");

	
}

void View::Show_manual()
{
	system("cls");
	cout << "Добрый день! Вы находитесь в программе \" Список дел \" \n";
	cout << "Программа способна хранить и отображать в различном виде дела и задания в пределах года\n";
	cout << "Программа умеет:\n\t- отображать дела по сортировке день/неделя/месяц\n";
	cout << "\t - искать дела по названию/дате/хэш-тэгу/приоритету\n";
	cout << "\t - сохранять и загружать дела из файла (автоматически)\n";
	cout << "\t - контролировать сроки и исполнение дел\n";
	cout << "Все дела записываются и в файл results.bin, при старте программы - считываются из него.\n";
}

void View::Show_about()
{
	system("cls");
	cout << "***О программе***\n";
	cout << "Программа разработана в рамках учебного процесса в Академии TOP\n";
	cout << "Иполнитель - Кротов Георгий, преподаватель - Давлетшин Роман (г. Красноярск, июнь 2022 г)\n";
}
