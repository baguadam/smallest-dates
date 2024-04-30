#include "./headers/processable_dates.h"

void ProcessableDates::addDate(const Date date) {
    minHeap.push(date);
}

Date ProcessableDates::getMinimumDate() {
    if (minHeap.empty()) {
        throw std::out_of_range("No date to retrieve!");
    }

    Date minDate = minHeap.top();
    minHeap.pop();
    return minDate;
}

bool ProcessableDates::isEmpty() const {
    return minHeap.empty();
}

int ProcessableDates::size() const {
    return minHeap.size();
}