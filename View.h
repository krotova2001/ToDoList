//����� ����������� ����������� ������ ��� 
#pragma once
#include <iostream>
using namespace std;

class View
{
public:
	View() //��������� ��������������� ��������� � �����������
	{
		setlocale(LC_ALL, "Russian");
	}
	
	void Show_menu(); //��������� ������ ����
	void Show_today(); // �������� ������ ��� �� ������� 
	void Show_intro(); // �������� �����������
	void Show_manual(); // �������� �������

};

