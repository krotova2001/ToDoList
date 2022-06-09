//класс модели - отдельного дела

#include <iostream>
#include <cstdlib>
#include <ctime>
#pragma warning(disable : 4996)
using namespace std;

struct Model // сделаем экземпляр дела в структуре - открытым, так как он будет инкапсулирован с массиве - внешнем классе
{
    string zellersAlgorithm(int day, int month, int year) //это готовая фунция определения дня недели
    {
        static char weekday[7][12] = { "Суббота","Воскресенье","Понедельник","Вторник", "Среда","Четверг","Пятница" };
        //Массив с названиями дней недели

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

    struct Date // встроенная структура даты в структуре дела
    {
        int day;
        int month;
        int year = 2022; // по умолчанию оставим наш год
        int week_int;
        //char week[12];
    };

    struct Time // встроенная структура времени в структуре дела
    {
        int hour = 9;
        int minutes = 00;
    };

    int id; //уникальный порядковый номер
    enum priority {extrim=1,imortant, usual,not_important,pofig}pri; // важность - пять уровней
    string name; // имя
    string information; // описание 
    struct Date date; // дата исполнения 
    struct Time time; // время исполнения
    string week; // день недели
    long int time_id;//метка времени для быстрого поиска по времени

    void Show() // здесь и определим единственную функцию - показать дело
    {
        cout << "\n";
        cout << "Порядковый номер - " << id << "\n";
        cout << "Название - " << name << "\n";
        cout << "Приоритет - " << pri << "\n";
        cout << "Описание - " << information << "\n";
        cout << "Срок - " << date.day << "/" << date.month << "/" << date.year << "\n";
        cout << "День недели - " << week << "\n";
        cout << "Время - " << time.hour << ":" << time.hour << "\n";
        cout << "-------------------------------------\n";
    }
};

