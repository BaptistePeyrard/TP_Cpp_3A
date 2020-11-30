#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>
#include <cassert>


namespace Date {

    class Date {
    public:
        Date(int year, int month, int day);
        Date() = default;
        int getYear() const;    //Nouvelle méthode pour récupérer l'année
        int getMonth() const;
        int getDay() const;
        bool checkDate(int year, int month, int day) const;
        Date nextDay();
        void setYear(int year); //Nouvelle méthode pour modifier l'année
        void setMonth(int month);
        void setDay(int day);
        std::string toString();
        bool checkBissextile(int year) const;
        int DaysInMonth(int year, int month) const;   //Fonction qui donne le nombre de jour dans le mois
        bool operator == (const Date& d) const; //Surchages d'opérateur pour comparer 2 dates
        bool operator <= (const Date& d) const;
        bool operator < (const Date& d) const;
        int operator - (const Date& d); //Surcharge d'opérateur pour soustraire une date à une autre date et récupérer le nombre de nuits les séparants (pour calculer le montant total d'une reservation)
        Date operator + (const int days) const; //Surcharge d'operateur pour ajouter des jours à une date
        Date operator - (const int days) const;
        Date operator ++ (int);    //Renvoie la date + 1 jour
    private:
        int _year;
        int _month;
        int _day;
    };

} //namespace

#endif // DATE_H



