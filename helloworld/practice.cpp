#include <iostream>
#include <chrono>

using namespace std;

int main() {
    // Start timer
    auto start = std::chrono::high_resolution_clock::now();

    // Code to measure
    // ... (your algorithm or function calls)

    //9'223'372'036'854'775'807 : too long
    for (long long i = 0; i < ((long long)INT_MAX) * ((long long)2); i++) {
        long long x = i;
    }
    cout << 9'223'372'036'854'775'807 / INT_MAX << "\n";

    // Stop timer
    auto stop = std::chrono::high_resolution_clock::now();

    // Calculate duration
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
