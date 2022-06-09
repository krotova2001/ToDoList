#include "Model_base.h"

Model Model_base::Add()
{
    Model new_deal; //создадим и заполним новое дело
    cout << "Важность дела (1-5)\n";
    scanf("%1d", &new_deal.pri);
    cout << "Название дела\n";
    cin>>new_deal.name;
    cout << "Описание\n";
    cin.get(); // чтобы функция cin.getline отрабатывала нормально, нужно перед ней выбросить \n из потока, так как cin>> ее там оставляет
    getline(cin, new_deal.information);
    cout << "Дата:\n";
    cout << "  день\n";
    scanf("%2d", &new_deal.date.day);
    cout << " месяц\n";
    scanf("%2d", &new_deal.date.month);
    cout << "  год\n";
    scanf("%4d", &new_deal.date.year);
    cout << "Время исполнения\n";
    cout << "  часы\n";
    scanf("%2d", &new_deal.time.hour);
    cout << "  минуты\n";
    scanf("%2d", &new_deal.time.minutes);
    //формируем индекс времени для удобства поиска и сортировки по времени
   
    new_deal.time_id = new_deal.time.minutes * 525600 + new_deal.time.hour * 8760 + new_deal.date.day * 365 + new_deal.date.month * 12 + new_deal.date.year;
    new_deal.week = new_deal.zellersAlgorithm(new_deal.date.day, new_deal.date.month, new_deal.date.year); // вычисляем день недели
    new_deal.id = base.size();
    base.push_back(new_deal);
    return new_deal;
}

void Model_base::Show_all() // показать все - функция для отладки
{
    for (Model a : base)
    {
        a.Show();
    }
}

void Model_base::Edit(string search)
{
  // здесь не будем испольщовать функции Search, а напишем немного модернизированную
    Model* new_deal = Search_for_edit(search); // нашли указатель на нужное дело
    
    // теперь всё перезаписываеем
    cout << "Важность дела (1-5)\n";
    scanf("%1d", new_deal->pri);
    cout << "Название дела\n";
    cin >> new_deal->name;
    cout << "Описание\n";
    cin.get(); // чтобы функция cin.getline отрабатывала нормально, нужно перед ней выбросить \n из потока, так как cin>> ее там оставляет
    getline(cin, new_deal->information);
    cout << "Дата:\n";
    cout << "  день\n";
    scanf("%2d", new_deal->date.day);
    cout << " месяц\n";
    scanf("%2d", new_deal->date.month);
    cout << "  год\n";
    scanf("%4d", new_deal->date.year);
    cout << "Время исполнения\n";
    cout << "  часы\n";
    scanf("%2d", new_deal->time.hour);
    cout << "  минуты\n";
    scanf("%2d", new_deal->time.minutes);
    //формируем индекс времени для удобства поиска и сортировки по времени

    new_deal->time_id = new_deal->time.minutes * 525600 + new_deal->time.hour * 8760 + new_deal->date.day * 365 + new_deal->date.month * 12 + new_deal->date.year;
    new_deal->week = new_deal->zellersAlgorithm(new_deal->date.day, new_deal->date.month, new_deal->date.year); // вычисляем день недели
}

Model* Model_base::Search_for_edit(string search) 
{
    if (search.find_first_of("1234567890")) //  если вводятся цифры, то ищем по ID дела
    {
        for (Model a : base)
        {
            return &base[stoi(search)];
        }
    }
    else // либо по строке - описанию или имени
    {
        for (Model a : base)
        {
            if (a.name.find(search) || a.information.find(search)) // если в описании или имени дела есть вхождение строки поиска
            {
                a.Show();
                return &a;
            }
        }
    }
    cout << "Ничего не нашлось...\n";
}

Model Model_base::Search() // поиск дел 
{
    cout << "Введите ID дела либо название, либо описание\n";
    string search;
    cin >> search;
    if (search.find_first_of("1234567890")) //  если вводятся цифры, то ищем по ID дела
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
            if (a.name.find(search) || a.information.find(search)) // если в описании или имени дела есть вхождение строки поиска
            {
                a.Show();
            }
        }
    }
    cout << "Ничего не нашлось...\n";
}

void Model_base::Search_date()// поиск по дате
{
}

void Model_base::Write_deals()
{
    FILE* file = nullptr;
    fopen_s(&file, "results.bin", "wb"); // открыть для записи в бинарном режиме

    if (file != nullptr) // проверка открылся ли файл
    {
        fwrite(&base, sizeof(Model), base.size(), file); //записываем целиком все структуры за раз
        cout << "База данных сохранена\n";
        fclose(file); // закрываем файл
    }
    else { cout << "\nНе могу записать базу данных дел\n"; }
}

void Model_base::Load_deal() // функция загрузки файла всех структур (базы данных)
{

    FILE* pfile = nullptr;
    fopen_s(&pfile, "results.bin", "rb"); // открываем файл со структурами
    if (pfile != nullptr)
    {
        Model ni; // создаем новое пустое дело
        while (fread(&ni, sizeof(Model), 1, pfile) > 0)
        {
            base.push_back(ni); // записываем новое дело к общему массиву в памяти
        }
        cout << base.size() << " дел загружено\n";
        fclose(pfile);
    }
    else
    {
        cout << "Не могу загрузить дела\n\n";
    }
}
