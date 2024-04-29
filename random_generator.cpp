#include <iostream>
#include <cstring>
#include <fstream>
#include "date.h"
#include "terrible_random_exception.h"

void printGeneratedNumbers(const int N, const int K, std::ostream& stream) {
    Date min_date(1970, 1, 1);
    Date max_date(2038, 1, 19);

    stream << N << '\n';
    stream << K << '\n';

    int counter = 0;
    while (counter < N+K) {
        try {
            std::unique_ptr<Date> generated_date = createRandomDateBetween(&min_date, &max_date);
            stream << generated_date->getYear() << ' ' << generated_date->getMonth() << ' ' << generated_date->getDay() << '\n';
            ++counter;
        } catch (const terrible_random&) {
            return;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc == 3) {
        int N = std::atoi(argv[1]);
        int K = std::atoi(argv[2]);
        printGeneratedNumbers(N, K, std::cout);
    } else if (argc == 4) {
        int N = std::atoi(argv[1]);
        int K = std::atoi(argv[2]);
        char* file_name = argv[3];
        if (strcmp("-", file_name) == 0) {
            printGeneratedNumbers(N, K, std::cout);
        } else {
            std::ofstream file(file_name);
            if (!file) {
                std::cerr << "File opening failed! \n";
                return -1;
            }
            printGeneratedNumbers(N, K, file);
            file.close();
        }
    } else {
        std::cerr << "The given number of parameters must be 2 or 3! \n";
        return -1;
    }

    return 0;
}