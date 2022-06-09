//класс хранилища дел
#pragma once
#include "Model.h"
#include "Controller.h"
#include <vector>
#include <string>
using namespace std;

class Model_base
{
	static vector<Model> base ; // сам массив дел
public:
	Model Add(); // добавление дел
	static void Edit(string search); // редактирование дела
	static Model* Search_for_edit(string search); // поиск дела (одного для редактирования)
	static Model Search(); // поиск дела или нескольких дел для просмотра
	static void Search_date(); // поиск дела по дате
	void Show_all(); // показать все - функция для отладки
	void Write_deals(); // функция записи базы данных дел в файл
	void Load_deal(); // функция загрузки файла всех структур (базы данных)

};

