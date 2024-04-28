#ifndef DATE_H_

#define DATE_H_
#include <memory>

constexpr int P_TRY = 100;

class Date {
private:
    int year, month, day;

    bool isDateValid() const;
    int generateRandomNumber(const int, const int);

public:
    Date(int, int, int);
    bool isDateCorrect() const;

    std::unique_ptr<Date> factory(const int, const int, const int);
    std::unique_ptr<Date> factory(const Date*, const Date*);

    int getYear() const;
    int getMonth() const;
    int getDay() const;

    explicit operator bool() const;
};

#endif