#include "Model_base.h"

void Model_base::Add()
{
    Model new_deal; //�������� � �������� ����� ����
    cout << "�������� ���� (1-5)\n";
    scanf("%1d", &new_deal.pri);
    cout << "�������� ����\n";
    scanf("%49s", &new_deal.name);
    cout << "��������\n";
    cin.get(); // ����� ������� cin.getline ������������ ���������, ����� ����� ��� ��������� \n �� ������, ��� ��� cin>> �� ��� ���������
    getline(cin, new_deal.information);
    cout << "����:\n";
    cout << "����\n";
    scanf("%2d", &new_deal.date.day);
    cout << "�����\n";
    scanf("%2d", &new_deal.date.month);
    cout << "���\n";
    scanf("%4d", &new_deal.date.year);
    cout << "����� ����������\n";
    cout << "����\n";
    scanf("%2d", &new_deal.time.hour);
    cout << "������\n";
    scanf("%2d", &new_deal.time.minutes);
    //��������� ������ ������� ��� �������� ������ � ���������� �� �������
    new_deal.time_id = new_deal.time.minutes * 525600 + new_deal.time.hour * 8760 + new_deal.date.day * 365 + new_deal.date.month * 12 + new_deal.date.year;

    new_deal.week = new_deal.zellersAlgorithm(new_deal.date.day, new_deal.date.month, new_deal.date.year); // ��������� ���� ������
    new_deal.id = base.size();
    base.push_back(new_deal);

}

void Model_base::Edit()
{
}

Model Model_base::Search(string search)
{
    return Model();
}
