#ifndef DATE_H_

#define DATE_H_
#include <memory>

constexpr int P_TRY = 100;

class Date {
private:
    int year, month, day;

    bool isDateValid() const;

public:
    Date() = default;
    Date(int, int, int);
    bool isDateCorrect() const;

    int getYear() const;
    int getMonth() const;
    int getDay() const;

    bool operator==(const Date&) const;
    bool operator!=(const Date&) const;
    bool operator<(const Date&) const;
    bool operator<=(const Date&) const;
    bool operator>(const Date&) const;
    bool operator>=(const Date&) const;
    explicit operator bool() const;
};

int generateRandomNumber(const int, const int);
std::unique_ptr<Date> createDate(const int, const int, const int);
std::unique_ptr<Date> createRandomDateBetween(const Date*, const Date*);

#endif