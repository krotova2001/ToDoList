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
	static void Edit(); // редактирование дела
	static Model* Search_for_edit(string search); // поиск дела (одного для редактирования)
	static Model Search(string search); // поиск дела или нескольких дел для просмотра
	void Show_all(); // показать все - функция для отладки
	void Write_deals(); // функция записи базы данных дел в файл
	void Load_deal(); // функция загрузки файла всех структур (базы данных)
	

};

