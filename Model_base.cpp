#include "Model_base.h"

Model Model_base::Add()
{
    Model new_deal; //�������� � �������� ����� ����
    cout << "�������� ���� (1-5)\n";
    scanf("%1d", &new_deal.pri);
    cout << "�������� ����\n";
    cin>>new_deal.name;
    cout << "��������\n";
    cin.get(); // ����� ������� cin.getline ������������ ���������, ����� ����� ��� ��������� \n �� ������, ��� ��� cin>> �� ��� ���������
    getline(cin, new_deal.information);
    cout << "����:\n";
    cout << "  ����\n";
    scanf("%2d", &new_deal.date.day);
    cout << " �����\n";
    scanf("%2d", &new_deal.date.month);
    cout << "  ���\n";
    scanf("%4d", &new_deal.date.year);
    cout << "����� ����������\n";
    cout << "  ����\n";
    scanf("%2d", &new_deal.time.hour);
    cout << "  ������\n";
    scanf("%2d", &new_deal.time.minutes);
    //��������� ������ ������� ��� �������� ������ � ���������� �� �������
   
    new_deal.time_id = new_deal.time.minutes * 525600 + new_deal.time.hour * 8760 + new_deal.date.day * 365 + new_deal.date.month * 12 + new_deal.date.year;
    new_deal.week = new_deal.zellersAlgorithm(new_deal.date.day, new_deal.date.month, new_deal.date.year); // ��������� ���� ������
    new_deal.id = base.size();
    base.push_back(new_deal);
    return new_deal;
}

void Model_base::Show_all() // �������� ��� - ������� ��� �������
{
    for (Model a : base)
    {
        a.Show();
    }
}

void Model_base::Edit(string search)
{
  // ����� �� ����� ������������ ������� Search, � ������� ������� �����������������
    Model* new_deal = Search_for_edit(search); // ����� ��������� �� ������ ����
    
    // ������ �� ���������������
    cout << "�������� ���� (1-5)\n";
    scanf("%1d", new_deal->pri);
    cout << "�������� ����\n";
    cin >> new_deal->name;
    cout << "��������\n";
    cin.get(); // ����� ������� cin.getline ������������ ���������, ����� ����� ��� ��������� \n �� ������, ��� ��� cin>> �� ��� ���������
    getline(cin, new_deal->information);
    cout << "����:\n";
    cout << "  ����\n";
    scanf("%2d", new_deal->date.day);
    cout << " �����\n";
    scanf("%2d", new_deal->date.month);
    cout << "  ���\n";
    scanf("%4d", new_deal->date.year);
    cout << "����� ����������\n";
    cout << "  ����\n";
    scanf("%2d", new_deal->time.hour);
    cout << "  ������\n";
    scanf("%2d", new_deal->time.minutes);
    //��������� ������ ������� ��� �������� ������ � ���������� �� �������

    new_deal->time_id = new_deal->time.minutes * 525600 + new_deal->time.hour * 8760 + new_deal->date.day * 365 + new_deal->date.month * 12 + new_deal->date.year;
    new_deal->week = new_deal->zellersAlgorithm(new_deal->date.day, new_deal->date.month, new_deal->date.year); // ��������� ���� ������
}

Model* Model_base::Search_for_edit(string search) 
{
    if (search.find_first_of("1234567890")) //  ���� �������� �����, �� ���� �� ID ����
    {
        for (Model a : base)
        {
            return &base[stoi(search)];
        }
    }
    else // ���� �� ������ - �������� ��� �����
    {
        for (Model a : base)
        {
            if (a.name.find(search) || a.information.find(search)) // ���� � �������� ��� ����� ���� ���� ��������� ������ ������
            {
                a.Show();
                return &a;
            }
        }
    }
    cout << "������ �� �������...\n";
}

Model Model_base::Search() // ����� ��� 
{
    cout << "������� ID ���� ���� ��������, ���� ��������\n";
    string search;
    cin >> search;
    if (search.find_first_of("1234567890")) //  ���� �������� �����, �� ���� �� ID ����
    {
         for (Model a:base)
            {
            return base[stoi(search)];
            }
    }
    else
    {
        for (Model a : base)
        {
            if (a.name.find(search) || a.information.find(search)) // ���� � �������� ��� ����� ���� ���� ��������� ������ ������
            {
                a.Show();
            }
        }
    }
    cout << "������ �� �������...\n";
}

void Model_base::Search_date()// ����� �� ����
{
}

void Model_base::Write_deals()
{
    FILE* file = nullptr;
    fopen_s(&file, "results.bin", "wb"); // ������� ��� ������ � �������� ������

    if (file != nullptr) // �������� �������� �� ����
    {
        fwrite(&base, sizeof(Model), base.size(), file); //���������� ������� ��� ��������� �� ���
        cout << "���� ������ ���������\n";
        fclose(file); // ��������� ����
    }
    else { cout << "\n�� ���� �������� ���� ������ ���\n"; }
}

void Model_base::Load_deal() // ������� �������� ����� ���� �������� (���� ������)
{

    FILE* pfile = nullptr;
    fopen_s(&pfile, "results.bin", "rb"); // ��������� ���� �� �����������
    if (pfile != nullptr)
    {
        Model ni; // ������� ����� ������ ����
        while (fread(&ni, sizeof(Model), 1, pfile) > 0)
        {
            base.push_back(ni); // ���������� ����� ���� � ������ ������� � ������
        }
        cout << base.size() << " ��� ���������\n";
        fclose(pfile);
    }
    else
    {
        cout << "�� ���� ��������� ����\n\n";
    }
}
