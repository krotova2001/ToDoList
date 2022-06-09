//����� ������ - ���������� ����

#include <iostream>
#include <cstdlib>
#include <ctime>
#pragma warning(disable : 4996)
using namespace std;

struct Model // ������� ��������� ���� � ��������� - ��������, ��� ��� �� ����� �������������� � ������� - ������� ������
{
    string zellersAlgorithm(int day, int month, int year) //��� ������� ������ ����������� ��� ������
    {
        static char weekday[7][12] = { "�������","�����������","�����������","�������", "�����","�������","�������" };
        //������ � ���������� ���� ������

        int mon;
        if (month > 2)
            mon = month; //for march to december month code is same as month
        else {
            mon = (12 + month); //for Jan and Feb, month code will be 13 and 14
            year--; //decrease year for month Jan and Feb
        }
        int y = year % 100; //last two digit
        int c = year / 100; //first two digit
        int w = (day + floor((13 * (mon + 1)) / 5) + y + floor(y / 4) + floor(c / 4) + (5 * c));
        w = w % 7;
        return weekday[w];
    }

    struct Date // ���������� ��������� ���� � ��������� ����
    {
        int day;
        int month;
        int year = 2022; // �� ��������� ������� ��� ���
        int week_int;
        //char week[12];
    };

    struct Time // ���������� ��������� ������� � ��������� ����
    {
        int hour = 9;
        int minutes = 00;
    };

    int id; //���������� ���������� �����
    enum priority {extrim=1,imortant, usual,not_important,pofig}pri; // �������� - ���� �������
    string name; // ���
    string information; // �������� 
    struct Date date; // ���� ���������� 
    struct Time time; // ����� ����������
    string week; // ���� ������
    long int time_id;//����� ������� ��� �������� ������ �� �������

    void Show() // ����� � ��������� ������������ ������� - �������� ����
    {
        cout << "\n";
        cout << "���������� ����� - " << id << "\n";
        cout << "�������� - " << name << "\n";
        cout << "��������� - " << pri << "\n";
        cout << "�������� - " << information << "\n";
        cout << "���� - " << date.day << "/" << date.month << "/" << date.year << "\n";
        cout << "���� ������ - " << week << "\n";
        cout << "����� - " << time.hour << ":" << time.hour << "\n";
        cout << "-------------------------------------\n";
    }
};

