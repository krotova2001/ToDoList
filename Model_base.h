//����� ��������� ���
#pragma once
#include "Model.h"
#include "Controller.h"
#include "View.h"
#include <vector>
#include <string>
using namespace std;

class Model_base
{
	static vector<Model> base; // ��� ������ ���
public:
	static Model Add(); // ���������� ���
	static void Edit(string search); // �������������� ����
	//static Model* Search_for_edit(string search); // ����� ���� (������ ��� ��������������)
	static Model* Search(string search); // ����� ���� ��� ���������� ��� ��� ���������
	static void Search_date(); // ����� ���� �� ����
	static void Show_all(); // �������� ��� - ������� ��� �������
	static void Delete(); //�������� ����
	void Write_deals(); // ������� ������ ���� ������ ��� � ����
	void Load_deal(); // ������� �������� ����� ���� �������� (���� ������)

};

