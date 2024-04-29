#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "./headers/date.h"
#include "./headers/timed_task.h"

// std::priority_queue is chosen for the implementation, because it's important to access and delete
// the element effienetly and for this purpose it's a good choise as retrieving the minimum element is O(1) and 
// removing it is O(logN) as well as inserting a new one
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

    // Open the file for reading
    char* file_name = argv[1];
    std::ifstream file(file_name);
    if (!file) {
        std::cerr << "File opening failed! \n";
        return -1;
    }

    // Read the values of N and K
    int N, K;
    if (!(file >> N >> K)) {
        std::cerr << "Failed to read N and K from input files!\n";
        return -1;
    }

    ProcessableDates processableDates = ProcessableDates();
    std::vector<Date> movableDates(K);

    // Read and store the first N values in the processableDates data structure:
    for (int i = 0; i < N; ++i) {
        int year, month, day;
        if (!(file >> year >> month >> day)) {
            std::cerr << "Failed to read date from input file!\n";
            return -1;
        }
        processableDates.addDate(Date(year, month, day));
    }

    // Read and store the remaining K values in the vector:
    for (int i = 0; i < K; ++i) {
        int year, month, day;
        if (!(file >> year >> month >> day)) {
            std::cerr << "Failed to read date from input file!\n";
            return -1;
        }
        movableDates[i] = Date(year, month, day);
    }

    file.close();

    return 0;
}