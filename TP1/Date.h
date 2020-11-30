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
        int getYear() const;    //Nouvelle m�thode pour r�cup�rer l'ann�e
        int getMonth() const;
        int getDay() const;
        bool checkDate(int year, int month, int day) const;
        Date nextDay();
        void setYear(int year); //Nouvelle m�thode pour modifier l'ann�e
        void setMonth(int month);
        void setDay(int day);
        std::string toString();
        bool checkBissextile(int year) const;
        int DaysInMonth(int year, int month) const;   //Fonction qui donne le nombre de jour dans le mois
        bool operator == (const Date& d) const; //Surchages d'op�rateur pour comparer 2 dates
        bool operator <= (const Date& d) const;
        bool operator < (const Date& d) const;
        int operator - (const Date& d); //Surcharge d'op�rateur pour soustraire une date � une autre date et r�cup�rer le nombre de nuits les s�parants (pour calculer le montant total d'une reservation)
        Date operator + (const int days) const; //Surcharge d'operateur pour ajouter des jours � une date
        Date operator - (const int days) const;
        Date operator ++ (int);    //Renvoie la date + 1 jour
    private:
        int _year;
        int _month;
        int _day;
    };

} //namespace

#endif // DATE_H



