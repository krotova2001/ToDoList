//����� ��������� ���
#pragma once
#include "Model.h"
#include "Controller.h"
#include <vector>
#include <string>
using namespace std;

class Model_base
{
	vector<Model> base; // ��� ������ ���
public:
	void Add(); // ���������� ���
	void Edit();
	Model Search(string search);


	void Show_all() // �������� ��� - ������� ��� �������
	{
		for (Model a:base)
		{
			a.Show();
		}
	}

};

