#include "ktimer/ktimer.hpp"
#include <iostream>
#include <chrono>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int Func1(void* params) {
    printf("Timer Func1\n");
    return 0;
}

int main() {
    nebula::KTimer timer(Func1);
    timer.Run(1000);
    std::this_thread::sleep_for(std::chrono::seconds(500));
}
