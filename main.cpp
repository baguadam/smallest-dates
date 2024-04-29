#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "./headers/date.h"
#include "./headers/timed_task.h"

class ProcessableDates {
private:
    std::priority_queue<Date, std::vector<Date>, std::greater<Date>> minHeap;

public:
    ProcessableDates() {}

    void addDate(const Date& date) {
        minHeap.push(date);
    }

    Date getMinimumDate() {
        if (minHeap.empty()) {
            throw std::out_of_range("No date to retrieve!");
        }

        Date minDate = minHeap.top();
        minHeap.pop();
        return minDate;
    }

    bool isEmmpty() const {
        return minHeap.empty();
    } 

    int size() const {
        return minHeap.size();
    }
}; 

int main(int argc, char* argv[]) {
    // if less or more than 1 argument
    if (argc != 2) {
        std::cerr << "The provided number of arguments is incorrect! \n";
        return -1;
    }

    char* file_name = argv[1];
    std::ifstream file(file_name);
    if (!file) {
        std::cerr << "File opening failed! \n";
        return -1;
    }


    return 0;
}