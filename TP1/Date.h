#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>


namespace Date {

    class Date {
    public:
        Date(int year, int month, int day);
        Date() = default;
        int getYear() const;    //Nouvelle méthode pour récupérer l'année
        int getMonth() const;
        int getDay() const;
        bool checkDate(int month, int day) const;
        Date nextDay();
        void setYear(int year); //Nouvelle méthode pour modifier l'année
        void setMonth(int month);
        void setDay(int day);
        std::string toString();
        bool checkBissextile(int year);
        bool operator == (const Date& d) const; //Surchages d'opérateur pour comparer 2 dates
        bool operator <= (const Date& d) const;
        int operator - (const Date& d); //Surcharge d'opérateur pour soustraire une date à une autre date et récupérer le nombre de nuits les séparants (pour calculer le montant total d'une reservation)
    private:
        int _year;
        int _month;
        int _day;
    };

} //namespace

#endif // DATE_H



