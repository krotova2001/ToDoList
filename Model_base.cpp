#include "Model_base.h"
vector<Model> Model_base::base; // прописываем еще раз статический массив с делами
Model Model_base::Add()
{
    Model new_deal; //ñîçäàäèì è çàïîëíèì íîâîå äåëî
    cout << "Âàæíîñòü äåëà (1-5)\n";
    scanf("%1d", &new_deal.pri);
    cout << "Íàçâàíèå äåëà\n";
    cin>>new_deal.name;
    cout << "Îïèñàíèå\n";
    cin.get(); // ÷òîáû ôóíêöèÿ cin.getline îòðàáàòûâàëà íîðìàëüíî, íóæíî ïåðåä íåé âûáðîñèòü \n èç ïîòîêà, òàê êàê cin>> åå òàì îñòàâëÿåò
    getline(cin, new_deal.information);
    cout << "Äàòà:\n";
    cout << "  äåíü\n";
    scanf("%2d", &new_deal.date.day);
    cout << " ìåñÿö\n";
    scanf("%2d", &new_deal.date.month);
    cout << "  ãîä\n";
    scanf("%4d", &new_deal.date.year);
    cout << "Âðåìÿ èñïîëíåíèÿ\n";
    cout << "  ÷àñû\n";
    scanf("%2d", &new_deal.time.hour);
    cout << "  ìèíóòû\n";
    scanf("%2d", &new_deal.time.minutes);
    //ôîðìèðóåì èíäåêñ âðåìåíè äëÿ óäîáñòâà ïîèñêà è ñîðòèðîâêè ïî âðåìåíè
   
    new_deal.time_id = new_deal.time.minutes * 525600 + new_deal.time.hour * 8760 + new_deal.date.day * 365 + new_deal.date.month * 12 + new_deal.date.year;
    new_deal.week = new_deal.zellersAlgorithm(new_deal.date.day, new_deal.date.month, new_deal.date.year); // âû÷èñëÿåì äåíü íåäåëè
    new_deal.id = base.size();
    base.push_back(new_deal);
    return new_deal;
}

void Model_base::Show_all() // ïîêàçàòü âñå - ôóíêöèÿ äëÿ îòëàäêè
{
    for (Model a : base)
    {
        a.Show();
    }
}

void Model_base::Edit(string search)
{
  // çäåñü íå áóäåì èñïîëüùîâàòü ôóíêöèè Search, à íàïèøåì íåìíîãî ìîäåðíèçèðîâàííóþ
    Model* new_deal = Search_for_edit(search); // íàøëè óêàçàòåëü íà íóæíîå äåëî
    
    // òåïåðü âñ¸ ïåðåçàïèñûâàååì
    cout << "Âàæíîñòü äåëà (1-5)\n";
    scanf("%1d", new_deal->pri);
    cout << "Íàçâàíèå äåëà\n";
    cin >> new_deal->name;
    cout << "Îïèñàíèå\n";
    cin.get(); // ÷òîáû ôóíêöèÿ cin.getline îòðàáàòûâàëà íîðìàëüíî, íóæíî ïåðåä íåé âûáðîñèòü \n èç ïîòîêà, òàê êàê cin>> åå òàì îñòàâëÿåò
    getline(cin, new_deal->information);
    cout << "Äàòà:\n";
    cout << "  äåíü\n";
    scanf("%2d", new_deal->date.day);
    cout << " ìåñÿö\n";
    scanf("%2d", new_deal->date.month);
    cout << "  ãîä\n";
    scanf("%4d", new_deal->date.year);
    cout << "Âðåìÿ èñïîëíåíèÿ\n";
    cout << "  ÷àñû\n";
    scanf("%2d", new_deal->time.hour);
    cout << "  ìèíóòû\n";
    scanf("%2d", new_deal->time.minutes);
    //ôîðìèðóåì èíäåêñ âðåìåíè äëÿ óäîáñòâà ïîèñêà è ñîðòèðîâêè ïî âðåìåíè

    new_deal->time_id = new_deal->time.minutes * 525600 + new_deal->time.hour * 8760 + new_deal->date.day * 365 + new_deal->date.month * 12 + new_deal->date.year;
    new_deal->week = new_deal->zellersAlgorithm(new_deal->date.day, new_deal->date.month, new_deal->date.year); // âû÷èñëÿåì äåíü íåäåëè
}

Model* Model_base::Search_for_edit(string search) 
{
    if (search.find_first_of("1234567890")) //  åñëè ââîäÿòñÿ öèôðû, òî èùåì ïî ID äåëà
    {
        for (Model a : base)
        {
            return &base[stoi(search)];
        }
    }
    else // ëèáî ïî ñòðîêå - îïèñàíèþ èëè èìåíè
    {
        for (Model a : base)
        {
            if (a.name.find(search) || a.information.find(search)) // åñëè â îïèñàíèè èëè èìåíè äåëà åñòü âõîæäåíèå ñòðîêè ïîèñêà
            {
                a.Show();
                return &a;
            }
        }
    }
    cout << "Íè÷åãî íå íàøëîñü...\n";
}

Model Model_base::Search() // ïîèñê äåë 
{
    cout << "Ââåäèòå ID äåëà ëèáî íàçâàíèå, ëèáî îïèñàíèå\n";
    string search;
    cin >> search;
    if (search.find_first_of("1234567890")) //  åñëè ââîäÿòñÿ öèôðû, òî èùåì ïî ID äåëà
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
            if (a.name.find(search) || a.information.find(search)) // åñëè â îïèñàíèè èëè èìåíè äåëà åñòü âõîæäåíèå ñòðîêè ïîèñêà
            {
                a.Show();
            }
        }
    }
    cout << "Íè÷åãî íå íàøëîñü...\n";
}

void Model_base::Search_date()// ïîèñê ïî äàòå
{
}

void Model_base::Write_deals()
{
    FILE* file = nullptr;
    fopen_s(&file, "results.bin", "wb"); // îòêðûòü äëÿ çàïèñè â áèíàðíîì ðåæèìå

    if (file != nullptr) // ïðîâåðêà îòêðûëñÿ ëè ôàéë
    {
        fwrite(&base, sizeof(Model), base.size(), file); //çàïèñûâàåì öåëèêîì âñå ñòðóêòóðû çà ðàç
        cout << "Áàçà äàííûõ ñîõðàíåíà\n";
        fclose(file); // çàêðûâàåì ôàéë
    }
    else { cout << "\nÍå ìîãó çàïèñàòü áàçó äàííûõ äåë\n"; }
}

void Model_base::Load_deal() // ôóíêöèÿ çàãðóçêè ôàéëà âñåõ ñòðóêòóð (áàçû äàííûõ)
{

    FILE* pfile = nullptr;
    fopen_s(&pfile, "results.bin", "rb"); // îòêðûâàåì ôàéë ñî ñòðóêòóðàìè
    if (pfile != nullptr)
    {
        Model ni; // ñîçäàåì íîâîå ïóñòîå äåëî
        while (fread(&ni, sizeof(Model), 1, pfile) > 0)
        {
            base.push_back(ni); // çàïèñûâàåì íîâîå äåëî ê îáùåìó ìàññèâó â ïàìÿòè
        }
        cout << base.size() << " äåë çàãðóæåíî\n";
        fclose(pfile);
    }
    else
    {
        cout << "Íå ìîãó çàãðóçèòü äåëà\n\n";
    }
}
