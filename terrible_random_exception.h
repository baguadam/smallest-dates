#ifndef TERRIBLE_RANDOM_EXCEPTION_H_

#define TERRIBLE_RANDOM_EXCEPTION_H_

#include <iostream>

class terrible_random : public std::runtime_error {
public:
    explicit terrible_random(const char* message) : std::runtime_error(message) {}
};

#endif