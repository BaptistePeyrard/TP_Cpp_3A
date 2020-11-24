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

	bool Date::operator <= (const Date& d) const
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

	int Date::operator - (const Date& d) const { // Soustraction de deux dates : renvoie le nombre de jour
		
		int day;
		int month;
		int year;

		if (getYear() == d.getYear()) {	//On a deja vérifié que la date de fin etait ultérieur à la date de début : l'année de fin est forcement superieur ou egale à l'année de debut
			year = 0;
		}
		else {
			year = getYear() - d.getYear();
		}

		month = getMonth() - d.getMonth();	//Le nombre de mois peut etre différent
		day = getDay() - d.getDay();

		return (day + month * 30 + year * 365);	

	}

}//namespace
