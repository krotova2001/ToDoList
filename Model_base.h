//класс хранилища дел
#pragma once
#include "Model.h"
#include "Controller.h"
#include "View.h"
#include <vector>
#include <string>
#include <fstream>
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
	static void Load_deal(); // функция загрузки файла всех структур (базы данных)

};

