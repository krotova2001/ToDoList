//����� ��������� ���
#pragma once
#include "Model.h"
#include "Controller.h"
#include "View.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>



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
	static void Load_base(vector<string> &s); // �������������� ������� �������������� ������� ���
	static std::vector<std::string>& split(const std::string& s, char delim, std::vector<std::string>& elems); // ��������������� ������� ������ �� ���
	static void Load_deal_new(); // �������� ������� ������� ������ ��� � �����
	static void Get_today();// ������� ���� �� �������
	static void Get_week();// ������� ���� �� �������
	static void Get_month();// ������� ���� �� �������
	static void Time_now(); // �������� ������� �����

};

