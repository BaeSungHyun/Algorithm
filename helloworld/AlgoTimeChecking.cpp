#include <iostream>
#include <chrono>

int main() {
    // Start timer
    auto start = std::chrono::high_resolution_clock::now();

    // Code to measure
    // ... (your algorithm or function calls)
    for (int i = 0; i < 500000; i++) {
        int x = i;
    }

    // Stop timer
    auto stop = std::chrono::high_resolution_clock::now();

    // Calculate duration
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
