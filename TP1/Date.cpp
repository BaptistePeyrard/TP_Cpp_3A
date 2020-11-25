#include "date.h"
#include <iostream>
#include <cassert>

namespace Date {

	bool Date::checkDate(int month, int day) const {
		bool status = true;

		if ((month == 1 || month == 3 || month == 5 || month == 7
			|| month == 8 || month == 10 || month == 12) && (day > 31 || day < 1)) {
			status = false;
		}
		else if ((month == 4 || month == 6 || month == 9 || month == 11)
			&& (day > 30 || day < 1)) {
			status = false;
		}
		else if ((month == 2) && (day > 28 || day < 1)) {
			status = false;
		}
		if ((month < 1) || (month > 12)) {
			status = false;
		}
		return status;
	}

	Date::Date(int year, int month, int day) {
		bool status = checkDate(month, day);
		assert(status == true && "Date is not valid");
		_year = year;
		_month = month;
		_day = day;
	}

	int Date::getYear() const
	{
		return _year;
	}

	int Date::getMonth() const {
		return _month;
	}

	int Date::getDay() const {
		return _day;
	}
	Date Date::nextDay() {
		Date next(_year, _month, _day + 1);
		return next;
	}
	
	std::string Date::toString() {
		std::string month[12] = { "Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec" };
		std::string to_display;
		to_display = month[_month - 1] + "/" + std::to_string(_day);
		return to_display;
	}
	bool Date::checkBissextile(int year)
	{

		if (((year % 4 == 0) && (year % 100 != 100)) || (year % 400 == 0)){
			return true;
		}
		else {
			return false;
		}

	}
	void Date::setYear(int year)
	{
		assert((year >= 2020) && (year <= 3000) && "Year is not valid");	//2020 car  date de debut au moins 2020 et 3000 pour éviter les reservations trop longues
		_year = year;
	}

	void Date::setMonth(int month) {
		assert((month >= 1) && (month <= 12) && "Month is not valid");
		_month = month;
	}

	void Date::setDay(int day) {
		bool status = checkDate(_month, day);
		assert(status == true && "Day is not valid");
		_day = day;
	}

	bool Date::operator == (const Date& d) const { // check for equality
		if ((getDay() == d.getDay()) && (getMonth() == d.getMonth()) && (getYear() == d.getYear())) {
			return true;
		}
		return false;
	}

	bool Date::operator <= (const Date& d) const	//Verification que la premiere date est inférieure ou égale à la deuxiéme
	{
		if (getYear() <= d.getYear()) {
			return true;
		}
		else if ((getYear() == d.getYear()) && (getMonth() <= d.getMonth())) {
			return true;
		}
		else if ((getYear() == d.getYear()) && (getMonth() == d.getMonth()) && (getDay() <= d.getDay())) {
			return true;
		}
		else {
			return false;
		}
		
	}

	int Date::operator - (const Date& d) { // Soustraction de deux dates : renvoie le nombre de nuits entre 2 dates
		

		int compteur = 0;	//On va compter le nombre de nuits entre les deux dates
		
		int year = getYear();
		while (year > d.getYear()) {	//Tant que l'année de la date de fin est > à l'année de la date de début

			if (checkBissextile(year) == true) {	//Si l'année est bissextile, elle aura 366 jours
				compteur += 366;
			}
			else {
				compteur += 365;
			}
			year--;	//On enleve une année à la date de fin après avoir comptabilisé ses jours
		}
		
		int month = getMonth();
		if (month > d.getMonth()) {	//Si la date de fin est toujours ultérieure à la date de début
			
			while (month > d.getMonth()) {
				if(month == 1 || month == 3 || month == 7 || month == 8 || month == 10 || month == 12 ){	//mois avec 31 jours
					compteur += 31;
				}
				else if (month == 4 || month == 6 || month == 9 || month == 11) {	//mois avec 30 jours
					compteur += 30;
				}
				else{	//fevrier
					if (checkBissextile(getYear()) == true) {	//Si année bissextile : 29 jours sinon 28
						compteur += 29;
					}
					else {
						compteur += 28;
					}
					
				}
				
				month--;	//On enleve un mois à la date de fin après avoir comptabilisé ses jours
				
			}
			
		}
		else if (month < d.getMonth()) {	//Si la date de fin est maintenant < à la date de début, il faudra enlever les jours de différence au compteur

			while (month < d.getMonth()) {
				if (month == 1 || month == 3 || month == 7 || month == 8 || month == 10 || month == 12) {	//mois avec 31 jours
					compteur -= 31;
				}
				else if (month == 4 || month == 6 || month == 9 || month == 11) {	//mois avec 30 jours
					compteur -= 30;
				}
				else {	//fevrier
					if (checkBissextile(getYear()) == true) {	//Si année bissextile : 29 jours sinon 28
						compteur -= 29;
					}
					else {
						compteur -= 28;
					}
				}
				month++;	//On ajoute un mois à la date de fin après avoir supprimer du compteur ses jours
			}

		}
		
		int day = getDay();
		if (day > d.getDay()) {	//On ajoute le nombre de jour séparant les 2 dates
			compteur += day - d.getDay();
		}
		else if (day < d.getDay()) {	//Si le jour de la date de fin est avant le jour de la date de depart, on soustrait le nombre de jours les séparants
			compteur += day - d.getDay();
		}

		return compteur;	//On return le nombre de jours entre les 2 dates
	}

}//namespace
