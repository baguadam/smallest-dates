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

    ProcessableDates processable_dates = ProcessableDates();
    std::vector<Date> movable_dates;

    auto read_from_file_task = [&file, &processable_dates, &movable_dates]() {
       // Read the values of N and K
        int N, K;
        if (!(file >> N >> K)) {
            throw std::runtime_error("Failed to read N and K from input file!");
        }

        if (N <= 0 || K <= 0) {
            throw std::runtime_error("Invalid values for N and/or K");
        }

        // Read and store the first N values in the processableDates data structure:
        for (int i = 0; i < N; ++i) {
            int year, month, day;
            if (!(file >> year >> month >> day)) {
                throw std::runtime_error("Failed to read the first N dates from input file!");
            }
            processable_dates.addDate(Date(year, month, day));
        }

        // Read and store the remaining K values in the vector:
        for (int i = 0; i < K; ++i) {
            int year, month, day;
            if (!(file >> year >> month >> day)) {
                throw std::runtime_error("Failed to read the remaining K dates from input file!");
            }
            movable_dates.push_back(Date(year, month, day));
        }
    };

    try {
        run_timed_task("File reading: ", read_from_file_task);
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return -1;
    }
    
    return 0;
}