//����� ����������� ����������� ������ ��� 
#pragma once
#include <iostream>
#include <cstdlib> // ��� ������ � �������� system()
using namespace std;

static class View
{
public:
	View() //��������� ��������������� ��������� � �����������
	{
		setlocale(LC_ALL, "Russian");
	}
	
	static void Show_menu(); //��������� ������ ����
	static void Show_menu_1(); // ������ ����� ���� - ��������
	static void Show_menu_2(); // �������������� ���
	static void Show_menu_3(); // ����� ���
	static void Show_today(); // �������� ������ ��� �� ������� 
	static void Show_manual(); // �������� �������
	static void Show_about(); // �������� ���������� � ����������
	
	~View()
	{
		//system("cls");
		cout << "\n����!!!\n";
	}
};

