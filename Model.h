//класс модели - дела

#include <iostream>
#include <cstdlib>
#include <ctime>
#pragma warning(disable : 4996)
using namespace std;
#pragma warning(disable : 4996)
class Model
{
    // здесь мы создаем встроенную структуру — котора€ содержит текущее врем€
    time_t now = time(0);
    tm* time_now = localtime(&now);

    char weekday[7][12] = { "—уббота","¬оскресенье","ѕонедельник","¬торник", "—реда","„етверг","ѕ€тница" };
    // в глобальной области видимости нам понадоб€тьс€ длни недели. ћассив с названи€ми

    char* zellersAlgorithm(int day, int month, int year) //это готова€ фунци€ определени€ дн€ недели
    {
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

    struct Date // встроенна€ структура даты в структуре дела
    {
        int day;
        int month;
        int year = 2022; // по умолчанию оставим наш год
        int week_int;
        char week[12];
    };

    struct Time // встроенна€ структура времени в структуре дела
    {
        int hour = 9;
        int minutes = 00;
    };

    struct deal // ќсновна€ - структура одного экземпл€ра дела 
    {
        int id; //уникальный пор€дковый номер
        int priority; // важность
        char name[50]; // им€
        char information[250]; // описание 
        struct Date date; // дата исполнени€ 
        struct Time time; // врем€ исполнени€
        char week[12]; // день недели
        long int time_id;//метка времени дл€ быстрого поиска по времени
    };
};

