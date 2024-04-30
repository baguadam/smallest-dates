#include "./headers/processable_dates.h"

void ProcessableDates::addDate(const Date date) {
    minHeap.push(date);
}

std::unique_ptr<Date> ProcessableDates::extractMinimumDate() {
    if (minHeap.empty()) {
        throw std::out_of_range("No date to retrieve!");
    }

    std::unique_ptr<Date> minDate = std::make_unique<Date>(minHeap.top());
    minHeap.pop();
    return minDate;
}

bool ProcessableDates::isEmpty() const {
    return minHeap.empty();
}

int ProcessableDates::size() const {
    return minHeap.size();
}