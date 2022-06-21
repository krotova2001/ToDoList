#include "Model_base.h"
vector<Model> Model_base::base; // создаем единственный экземпляр базы данных модели внутри класса
Model Model_base::Add() // добавление дела
{
    Model new_deal; //создадим и заполним новое дело
    cout << "Priority (1-5)\n";
    scanf("%1d", &new_deal.pri);
    cout << "Name\n";
    cin >> new_deal.name;
    cout << "Informaion\n";
    cin.get(); // чтобы функция cin.getline отрабатывала нормально, нужно перед ней выбросить \n из потока, так как cin>> ее там оставляет
    getline(cin, new_deal.information);
    cout << "Date:\n";
    cout << "  day\n";
    scanf("%2d", &new_deal.date.day);
    cout << " month\n";
    scanf("%2d", &new_deal.date.month);
    cout << "  year\n";
    scanf("%4d", &new_deal.date.year);
    cout << "Time\n";
    cout << "  hour\n";
    scanf("%2d", &new_deal.time.hour);
    cout << "  minutes\n";
    scanf("%2d", &new_deal.time.minutes);
    //формируем индекс времени для удобства поиска и сортировки по времени

    new_deal.time_id = new_deal.time.minutes * 525600 + new_deal.time.hour * 8760 + new_deal.date.day * 365 + new_deal.date.month * 12 + new_deal.date.year;
    new_deal.week = new_deal.zellersAlgorithm(new_deal.date.day, new_deal.date.month, new_deal.date.year); // вычисляем день недели
    new_deal.id = base.size()+1;
    base.push_back(new_deal);
    return new_deal;
}

void Model_base::Show_all() // показать все - функция для отладки
{
    for (Model a : base)
    {
        View::Show_delo(a);
    }
    system("pause");
}


void Model_base::Edit(string search)
{
    // здесь не будем использовать функции Search, а напишем немного модернизированную
    Model* old_deal = Search(search); // нашли указатель на нужное старое дело

    Model new_deal;
    // теперь всё перезаписываеем
    cout << "Priority (1-5)\n";
    scanf("%1d", &new_deal.pri);
    cout << "Name\n";
    cin >> new_deal.name;
    cout << "Information\n";
    cin.get(); // чтобы функция cin.getline отрабатывала нормально, нужно перед ней выбросить \n из потока, так как cin>> ее там оставляет
    getline(cin, new_deal.information);
    cout << "Data:\n";
    cout << "  day\n";
    scanf("%2d", &new_deal.date.day);
    cout << " month\n";
    scanf("%2d", &new_deal.date.month);
    cout << "  год\n";
    scanf("%4d", &new_deal.date.year);
    cout << "Time\n";
    cout << "  hour\n";
    scanf("%2d", &new_deal.time.hour);
    cout << "  minute\n";
    scanf("%2d", &new_deal.time.minutes);
    //формируем индекс времени для удобства поиска и сортировки по времени

    new_deal.time_id = new_deal.time.minutes * 525600 + new_deal.time.hour * 8760 + new_deal.date.day * 365 + new_deal.date.month * 12 + new_deal.date.year;
    new_deal.week = new_deal.zellersAlgorithm(new_deal.date.day, new_deal.date.month, new_deal.date.year); // вычисляем день недели
    new_deal.id = old_deal->id;
    *old_deal = new_deal;
}

Model* Model_base::Search(string search) // поиск дел
{
    if (search.find_first_of("1234567890", 0, 2) != -1) //  если вводятся цифры, то ищем по ID дела
    {
        int s = stoi(search);
        if (s>base.size()||s<=0)
        {
            cout << "ID is Out of range\n";
            return nullptr;
        }
        View::Show_delo(base[s-1]);
        return &base[s - 1];
    }
    else
    {
        for (Model& a : base)
        {
            if (a.name.find(search)!=std::string::npos || a.information.find(search) != std::string::npos) // если в описании или имени дела есть вхождение строки поиска
            {
                View::Show_delo(a);
                return &a;
            }
        }
    }
    cout << "Ничего не нашлось...\n";
    return nullptr;
}

void Model_base::Search_date()// поиск по дате
{
   
}

void Model_base::Write_deals() //запись дел в файл
{
    if (base.size() > 0) // если есть что записывать
    {
        ofstream Result; // объект для вывода результатов
        Result.open("base.txt", ios::out); // откроем файл на запись и запишем
        if (Result.is_open())// проверка открылся ли файл
        {
            for (Model a : base)
            {
                Result << a.id << "|";
                Result << a.pri << "|";
                Result << a.name << "|";
                Result << a.information << "|";
                Result << a.date.day << "|";
                Result << a.date.month << "|";
                Result << a.date.week_int << "|";
                Result << a.date.year << "|";
                Result << a.time.hour << "|";
                Result << a.time.minutes << "|";
                Result << a.week << "|";
                Result << a.time_id << "|";
                Result << "\n";
            }
            Result.close(); // закрываем файл
            cout << "База данных сохранена\n";
        }
        else { cout << "\nНе могу записать базу данных дел\n"; }
    }
}

void Model_base::Load_deal() // функция загрузки файла всех структур (базы данных)
{
    ifstream Source;
    Source.open("base.txt");
    if (Source.is_open())
    {
        while (!Source.eof())// идем до конца файла
        {
            Model a; //создадим и заполним новое дело
            char idc[1024]; // буфер считывания
            Source.getline(idc, sizeof(a.id), '|');
            a.id = atoi(idc);
            Source.getline(idc, sizeof(a.pri), '|');
            switch (atoi(idc))
                {
                case 1:
                    a.pri = Model::extrim;
                    break;
                case 2:
                    a.pri = Model::imortant;
                    break;
                case 3:
                    a.pri = Model::usual;
                    break;
                case 4:
                    a.pri = Model::not_important;
                    break;
                case 5:
                    a.pri = Model::pofig;
                    break;
                default:
                    break;
                }
            Source.getline(idc, sizeof(a.name), '|');
            a.name = idc;
            Source.getline(idc, sizeof(a.information), '|');
            a.information = idc;
            Source.getline(idc, sizeof(a.date.day), '|');
            a.date.day = atoi(idc);
            Source.getline(idc, sizeof(a.date.month), '|');
            a.date.month = atoi(idc);
            Source.getline(idc, sizeof(a.date.week_int), '|');
            a.date.week_int = atoi(idc);
            Source.getline(idc, sizeof(a.date.year), '|');
            a.date.year = atoi(idc);
            Source.getline(idc, sizeof(a.time.hour), '|');
            a.time.hour = atoi(idc);
            Source.getline(idc, sizeof(a.time.minutes), '|');
            a.time.minutes = atoi(idc);
            Source.getline(idc, sizeof(a.week), '|');
            a.week = idc;
            Source.getline(idc, sizeof(a.time_id), '|');
            a.time_id = atoi(idc);
            base.push_back(a);
            //Source.getline(idc, 1);
        }
         Source.close();
         cout << "Base loaded";
    }
    
    else
    {
        cout << "Loading error\n\n";
    }
}

void Model_base::Delete()
{
    string search;
    cout << "Введите ID дела либо название, либо описание\n";
    cin >> search;
    Model* old_deal = Search(search); // нашли указатель на нужное старое дело
    vector <Model>::iterator it = base.begin();
    for (;it<base.end();it++)
    {
        if ((*it).id == old_deal->id)
        {
            break;
        }
        cout << "Iterator error\n";
    }
    if (old_deal) // если дело существует...
    {
        cout << "Deleted\n";
        base.erase(it);
    }
    system("pause");
}
