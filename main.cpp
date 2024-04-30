#include <iostream>
#include <fstream>
#include "./headers/date.h"
#include "./headers/timed_task.h"
#include "./headers/processable_dates.h"
#include "./headers/consumer.h"

int (*consumer_ptr)(std::unique_ptr<Date>) = consume;

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
    int N, K;

    auto read_from_file_task = [&file, &processable_dates, &movable_dates, &N, &K]() {
       // Read the values of N and K
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

    auto main_algorithm_task = [&processable_dates, &movable_dates, &N, &K]() {
        for (int i = 0; i < N + K; ++i) {
            // creates a copy of the returned date on the heap. Maybe it would be better to modify the implementation 
            // of the ProcessableDates class so that it doesn't return a Date by value?
            std::unique_ptr<Date> date = std::make_unique<Date>(processable_dates.getMinimumDate()); 
            int result = consumer_ptr(std::move(date)); 

            Date nextDate = movable_dates[i % (N + K)];
            processable_dates.addDate(nextDate);
        }
    };

    run_timed_task("Date processing", main_algorithm_task);
    
    return 0;
}