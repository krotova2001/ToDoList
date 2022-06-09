//класс хранилища дел
#pragma once
#include "Model.h"
#include "Controller.h"
#include <vector>
#include <string>
using namespace std;

class Model_base
{
	vector<Model> base; // сам массив дел
public:
	void Add(); // добавление дел
	void Edit();
	Model Search(string search);


	void Show_all() // показать все - функция для отладки
	{
		for (Model a:base)
		{
			a.Show();
		}
	}

};

