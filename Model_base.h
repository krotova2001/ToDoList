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
	static void Edit(); // �������������� ����
	static Model* Search_for_edit(string search); // ����� ���� (������ ��� ��������������)
	static Model Search(string search); // ����� ���� ��� ���������� ��� ��� ���������
	void Show_all(); // �������� ��� - ������� ��� �������
	void Write_deals(); // ������� ������ ���� ������ ��� � ����
	void Load_deal(); // ������� �������� ����� ���� �������� (���� ������)
	

};

