#include <iostream>
#include "./headers/date.h"

int compareDates(const Date& date1, const Date& date2) {
    if (date1 == date2) {
        return 0;
    } else if (date1 < date2) {
        return -1;
    } else {
        return 1;
    }
}

int consume(std::unique_ptr<Date> date) {
    static std::unique_ptr<Date> prevDate = nullptr;

    // if the provided date is invalid
    if (!date) {
        return -2;
    }

    if (!prevDate) {
        prevDate = std::move(date);
        return 42;
    }

    int comparison = compareDates(*prevDate, *date);
    prevDate = std::move(date);
    return comparison;
}