#include <iostream>
#include "date.h"

int consume(const Date* date) {
    static Date* prevDate = nullptr;

    if (prevDate == nullptr) {
        return 42;
    }

    
}