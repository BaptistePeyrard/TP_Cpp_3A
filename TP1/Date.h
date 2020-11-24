#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>


namespace Date {

    class Date {
    public:
        Date(int year, int month, int day);
        Date() = default;
        int getYear() const;
        int getMonth() const;
        int getDay() const;
        bool checkDate(int month, int day) const;
        Date nextDay();
        void setYear(int year);
        void setMonth(int month);
        void setDay(int day);
        std::string toString();
        bool operator == (const Date& d) const;
        bool operator <= (const Date& d) const;
        int operator - (const Date& d) const;
    private:
        int _year;
        int _month;
        int _day;
    };

} //namespace

#endif // DATE_H



