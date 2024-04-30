#ifndef CONSUME_H_

#define CONSUME_H_

#include <iostream>
#include "date.h"

int compareDates(const Date&, const Date&);
int consume(std::unique_ptr<Date>);

#endif