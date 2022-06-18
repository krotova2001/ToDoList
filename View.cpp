#include "View.h"
#include <iostream>
#include <iomanip> // ��� ��� �������� ��������
#include <ctime> // ���������� ������ �� ��������
using namespace std;

void View::Show_menu() //������� ����
{
	system("cls"); // ������� ������
	cout <<"\x1B[31m***********************������ ���***********************\033[0m\t\t\n\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "�������� " << right << " 1\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "�������������� " << right << " 2\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "����� " << right << " 3\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "������� " << right << " 4\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "� ��������� " << right << " 5\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "����� " << right << " 0\n\n";
}

void View::Show_menu_1()
{
	system("cls");
	cout << "\x1B[31m***********************��������***********************\033[0m\t\t\n\n";
	
	cout << "\t\t" << setw(25) << setfill('-') << left << "�� ������� " << right << " 1\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "�� ������ " << right << " 2\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "�� ����� " << right << " 3\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "��� ���� " << right << " 4\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "����� " << right << " 0\n\n";
}

void View::Show_menu_2()
{
	system("cls");
	cout << "\x1B[31m***********************��������������***********************\033[0m\t\t\n\n";
	cout << "\t\t" << setw(30) << setfill('-') << left << "����� ���� " << right << " 1\n";
	cout << "\t\t" << setw(30) << setfill('-') << left << "�������������� ������������� ���� " << right << " 2\n";
	cout << "\t\t" << setw(30) << setfill('-') << left << "�������� ���� " << right << " 3\n";
	cout << "\t\t" << setw(30) << setfill('-') << left << "����� " << right << " 0\n\n";
}

void View::Show_menu_22()
{
	system("cls");
	cout << "\x1B[31m***********************��������������***********************\033[0m\t\t\n\n";
	cout << "������� ID ���� ���� ��������, ���� ��������\n";
	cout << "���� ������� 0 ��� ������ � ����\n";
}


void View::Show_menu_3()
{
	system("cls");
	cout << "\x1B[31m***********************�����***********************\033[0m\t\t\n\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "�� ��������/��������/ID " << right << " 1\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "�� ���� " << right << " 2\n";
	cout << "\t\t" << setw(25) << setfill('-') << left << "����� " << right << " 0\n\n";

}

void View::Show_today()
{
	system("cls");

	
}

void View::Show_manual()
{
	system("cls");
	cout << "������ ����! �� ���������� � ��������� \" ������ ��� \" \n";
	cout << "��������� �������� ������� � ���������� � ��������� ���� ���� � ������� � �������� ����\n";
	cout << "��������� �����:\n\t- ���������� ���� �� ���������� ����/������/�����\n";
	cout << "\t - ������ ���� �� ��������/����/���-����/����������\n";
	cout << "\t - ��������� � ��������� ���� �� ����� (�������������)\n";
	cout << "\t - �������������� ����� � ���������� ���\n";
	cout << "��� ���� ������������ � � ���� results.bin, ��� ������ ��������� - ����������� �� ����.\n";
}

void View::Show_about()
{
	system("cls");
	cout << "***� ���������***\n";
	cout << "��������� ����������� � ������ �������� �������� � �������� TOP\n";
	cout << "���������� - ������ �������, ������������� - ��������� ����� (�. ����������, ���� 2022 �)\n";
}

void View::Show_delo(Model A)
{
	cout << "\n";
	cout << "���������� ����� - " << A.id << "\n";
	cout << "�������� - " << A.name << "\n";
	cout << "��������� - " << A.pri << "\n";
	cout << "�������� - " << A.information << "\n";
	cout << "���� - " << A.date.day << "/" << A.date.month << "/" << A.date.year << "\n";
	cout << "���� ������ - " << A.week << "\n";
	cout << "����� - " << A.time.hour << ":" << A.time.hour << "\n";
	cout << "-------------------------------------\n";
}


