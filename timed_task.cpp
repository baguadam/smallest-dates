#include <iostream>
#include <chrono>
#include "timed_task.h"

template <typename F>
void run_timed_task(const char* task, const F&& func) {
    std::cerr << "Started execution of task: " << task << '\n';
    
    auto start = std::chrono::high_resolution_clock::now();
    std::forward<F>(func)();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cerr << "Stopped exeuction of task: " << task << " - elapsed time: " << duration.count() << '\n';
}