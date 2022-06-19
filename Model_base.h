//����� ��������� ���
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
	static vector<Model> base; // ��� ������ ���
public:
	static Model Add(); // ���������� ���
	static void Edit(string search); // �������������� ����
	static Model* Search(string search); // ����� ���� ��� ���������� ��� ��� ���������
	static void Search_date(); // ����� ���� �� ����
	static void Show_all(); // �������� ��� - ������� ��� �������
	static void Delete(); //�������� ����
	static void Write_deals(); // ������� ������ ���� ������ ��� � ����
	static void Load_deal(); // ������� �������� ����� ���� �������� (���� ������)

};

