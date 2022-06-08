//����� ��������� ���

#pragma once
#include "Model.h"
#include "Controller.h"
#include <vector>
#include <string>
using namespace std;

class Model_base
{
	vector<Model>base; // ��� ������ ���
public:
	void Add() // ���������� ����
	{
        Model new_deal; //�������� � �������� ����� ����
        cout << "�������� ���� (1-5)\n";
        scanf("%1d", &new_deal.pri);
        cout << "�������� ����\n";
        scanf("%49s", &new_deal.name);
        cout << "��������\n";
        //cin.get(); // ����� ������� cin.getline ������������ ���������, ����� ����� ��� ��������� \n �� ������, ��� ��� cin>> �� ��� ���������
        getline(cin, new_deal.information);
        cout << "����:\n";
        cout << "����\n";
        scanf("%2d", &new_deal.date.day);
        cout << "�����\n";
        scanf("%2d", &new_deal.date.month);
        cout << "���\n";
        scanf("%4d", &new_deal.date.year);
        cout << "����� ����������\n";
        cout << "����\n";
        scanf("%2d", &new_deal.time.hour);
        cout << "������\n";
        scanf("%2d", &new_deal.time.minutes);
        //��������� ������ ������� ��� �������� ������ � ���������� �� �������
        new_deal.time_id = new_deal.time.minutes * 525600 + new_deal.time.hour * 8760 + new_deal.date.day * 365 + new_deal.date.month * 12 + new_deal.date.year;

        char* week = Model::zellersAlgorithm(new_deal.date.day, new_deal.date.month, new_deal.date.year); // ��������� ���� ������
        strcpy(new_deal.week, week);
		base.push_back(new_deal);
	}

	void Show_all() // �������� ��� - ������� ��� �������
	{
		for (Model a:base)
		{
			a.Show();
		}
	}

};

