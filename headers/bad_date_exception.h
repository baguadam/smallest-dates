#ifndef BAD_DATE_EXCEPTION_H_

#define BAD_DATE_EXCEPTION_H_

#include <iostream>

class bad_date : public std::runtime_error {
public:
    explicit bad_date(const char* message) : std::runtime_error(message) {}
};

#endif