#include <iostream>
#include <sys/resource.h>

void printMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    std::cout << "Memory usage: " << usage.ru_maxrss << " kilobytes\n";
}

int main() {
    // Your algorithm or code here

    printMemoryUsage();
    return 0;
}
