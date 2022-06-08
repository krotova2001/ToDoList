//класс хранилища дел

#pragma once
#include "Model.h"
#include "Controller.h"
#include <vector>
#include <string>
using namespace std;

class Model_base
{
	vector<Model>base; // сам массив дел
public:
	void Add() // добавление дела
	{
        Model new_deal; //создадим и заполним новое дело
        cout << "¬ажность дела (1-5)\n";
        scanf("%1d", &new_deal.pri);
        cout << "Ќазвание дела\n";
        scanf("%49s", &new_deal.name);
        cout << "ќписание\n";
        //cin.get(); // чтобы функци€ cin.getline отрабатывала нормально, нужно перед ней выбросить \n из потока, так как cin>> ее там оставл€ет
        getline(cin, new_deal.information);
        cout << "ƒата:\n";
        cout << "день\n";
        scanf("%2d", &new_deal.date.day);
        cout << "мес€ц\n";
        scanf("%2d", &new_deal.date.month);
        cout << "год\n";
        scanf("%4d", &new_deal.date.year);
        cout << "¬рем€ исполнени€\n";
        cout << "часы\n";
        scanf("%2d", &new_deal.time.hour);
        cout << "минуты\n";
        scanf("%2d", &new_deal.time.minutes);
        //формируем индекс времени дл€ удобства поиска и сортировки по времени
        new_deal.time_id = new_deal.time.minutes * 525600 + new_deal.time.hour * 8760 + new_deal.date.day * 365 + new_deal.date.month * 12 + new_deal.date.year;

        char* week = Model::zellersAlgorithm(new_deal.date.day, new_deal.date.month, new_deal.date.year); // вычисл€ем день недели
        strcpy(new_deal.week, week);
		base.push_back(new_deal);
	}

	void Show_all() // показать все - функци€ дл€ отладки
	{
		for (Model a:base)
		{
			a.Show();
		}
	}

};

