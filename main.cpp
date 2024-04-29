#include <iostream>
#include <fstream>
#include "./headers/date.h"
#include "./headers/timed_task.h"

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