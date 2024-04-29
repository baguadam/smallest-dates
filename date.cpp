#include <random>
#include "./headers/date.h"
#include "./headers/bad_date_exception.h"
#include "./headers/terrible_random_exception.h"

/**************************** 
*¸FACTORIES AND RANDOM GENERATOR
*****************************/
int generateRandomNumber(const int min, const int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}

std::unique_ptr<Date> createDate(const int year, const int month, const int day) {
    std::unique_ptr<Date> date(new Date(year, month, day));
    if (date && date->isDateCorrect()) {
        return date;  
    } else {
        throw bad_date("Invalid values for the date. The specific year doesn't exist with the year, month and day values! \n");
    }
}

std::unique_ptr<Date> createRandomDateBetween(Date const* min, Date const* max) {
    int try_count = 0;
    while (try_count < P_TRY) {
        int random_year = generateRandomNumber(min->getYear(), max->getYear());
        int random_month = generateRandomNumber(min->getMonth(), max->getMonth());
        int random_day = generateRandomNumber(min->getDay(), max->getDay());

        try {
            std::unique_ptr<Date> date(new Date(random_year, random_month, random_day));
            return date;
        } catch (const bad_date&) {
            ++try_count;
        }
    }

    throw terrible_random("Couldn't generate proper random date between the provided two dates! \n");
}

/**************************** 
*¸DATE CLASS
*****************************/
bool Date::isDateValid() const {
    // check if the given date is in the correct range
    if (year < 1800 || year > 2200 || month < 1 || month > 12 || day < 1) {
        return false; 
    }

    // calculate if the year is a leap year
    bool leapYear = (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);

    switch (month) {
        case 2: 
            if (leapYear) {
                return day <= 29;
            } else {
                return day <= 28;
            }
        case 4: 
        case 6: 
        case 9:
        case 11:
            return day <= 30;
        default: 
            return day <= 31;
    }
}

Date::Date(const int year, const int month, const int day) : year(year), month(month), day(day) {}

bool Date::isDateCorrect() const { 
    return isDateValid();
}
    
// GETTERS
int Date::getYear() const { return year; }
int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }  

// Operators
Date::operator bool() const {
    return isDateCorrect();
}

bool Date::operator==(const Date& other) const {
    return year == other.year && month == other.month && day == other.day;
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::operator<=(const Date& other) const {
    return (*this < other) || (*this == other);
}

bool Date::operator>(const Date& other) const {
    return !(*this <= other);
}

bool Date::operator>=(const Date& other) const {
    return !(*this < other);
}