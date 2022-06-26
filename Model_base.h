//класс хранилища дел
#pragma once
#include "Model.h"
#include "Controller.h"
#include "View.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>



using namespace std;

class Model_base
{
	static vector<Model> base; // сам массив дел
public:

	static Model Add(); // добавление дел
	static void Edit(string search); // редактирование дела
	static Model* Search(string search); // поиск дела или нескольких дел для просмотра
	static void Search_date(); // поиск дела по дате
	static void Show_all(); // показать все - функция для отладки
	static void Delete(); //удаление дела
	static void Write_deals(); // функция записи базы данных дел в файл
	static void Load_base(vector<string> &s); // вспомогательня функция форматирования массива дел
	static std::vector<std::string>& split(const std::string& s, char delim, std::vector<std::string>& elems); // вспомогательная функция чтения БД дел
	static void Load_deal_new(); // основная внешняя функция четния дел с файла
	static void Get_today();// вернуть дела на сегодня
	static void Get_week();// вернуть дела на сегодня
	static void Get_month();// вернуть дела на сегодня
	static void Time_now(); // показать текущее время

};

