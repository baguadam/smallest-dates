#include <optional>
#include "./headers/consumer.h"

int compareDates(const Date& date1, const Date& date2) {
    return (date1 < date2) ? -1 : ((date1 == date2) ? 0 : 1);
}

int consume(std::unique_ptr<Date> date) {
    static std::optional<Date> prevDate;

    // if the provided date is invalid
    if (!date) {
        return -2;
    }

    if (!prevDate) {
        prevDate = *date;
        return 42;
    }

    int comparison = compareDates(*prevDate, *date);
    prevDate = *date;
    return comparison;
}