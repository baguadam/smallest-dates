#include <iostream>
#include <chrono>
#include "./headers/timed_task.h"

template <typename F>
void run_timed_task(const char* task, F&& lambda) {
    std::cerr << "Started execution of task: " << task << '\n';
    
    auto start = std::chrono::high_resolution_clock::now();
    std::forward<F>(lambda)();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cerr << "Stopped exeuction of task: " << task << " - elapsed time: " << duration.count() << '\n';
}