#ifndef PROCESSABLE_DATES_H_

#define PROCESSABLE_DATES_H_

#include <iostream>
#include <vector>
#include <queue>
#include "date.h"

// std::priority_queue is chosen for the implementation, because it's important to access and delete
// the element effienetly and for this purpose it's a good choise as retrieving the minimum element is O(1) and 
// removing it is O(logN) as well as inserting a new one
class ProcessableDates {
private:
    std::priority_queue<Date, std::vector<Date>, std::greater<Date>> minHeap;

public:
    ProcessableDates();

    void addDate(const Date&);
    Date getMinimumDate();
    bool isEmmpty() const;
    int size() const;
};

#endif