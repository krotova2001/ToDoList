//����� ����������� ����������� ������ ��� 
#pragma once
#include <iostream>
#include <cstdlib> // ��� ������ � �������� system()
using namespace std;

class View
{
public:
	View() //��������� ��������������� ��������� � �����������
	{
		setlocale(LC_ALL, "Russian");
	}
	
	void Show_menu(); //��������� ������ ����
	void Show_menu_1(); // ������ ����� ���� - ��������
	void Show_menu_2(); // �������������� ���
	void Show_menu_3(); // ����� ���
	void Show_today(); // �������� ������ ��� �� ������� 
	void Show_manual(); // �������� �������
	void Show_about(); // �������� ���������� � ����������
	
	~View()
	{
		system("cls");
		cout << "\n����!!!\n";
	}
};

