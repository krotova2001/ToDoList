//����� ��������� ���
#pragma once
#include "Model.h"
#include "Controller.h"
#include <vector>
#include <string>
using namespace std;

class Model_base
{
	static vector<Model> base ; // ��� ������ ���
public:
	Model Add(); // ���������� ���
	static void Edit(string search); // �������������� ����
	static Model* Search_for_edit(string search); // ����� ���� (������ ��� ��������������)
	static Model Search(); // ����� ���� ��� ���������� ��� ��� ���������
	static void Search_date(); // ����� ���� �� ����
	void Show_all(); // �������� ��� - ������� ��� �������
	void Write_deals(); // ������� ������ ���� ������ ��� � ����
	void Load_deal(); // ������� �������� ����� ���� �������� (���� ������)

};

