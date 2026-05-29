// src/main.cpp
#include <iostream>
#include "Timer.h"

int main() {
    std::cout << "[Benchmark] Standard OS memory allocation (100,000 integers)...\n";
    
    {
        // The Timer starts the moment this object is created
        Timer timer; 
        
        // Simulating standard, unoptimized OS allocations
        int* rawArray = new int[100000];
        for (int i = 0; i < 100000; i++) {
            rawArray[i] = i;
        }
        delete[] rawArray;
        
        // The Timer automatically stops and prints the time when it leaves this scope
    }

    return 0;
}