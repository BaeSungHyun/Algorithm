#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> distr(5.0, 2.0); // Mean = 5.0, Stddev = 2.0

    for(int n=0; n<10; ++n)
        std::cout << distr(gen) << ' ';
    std::cout << '\n';

    return 0;
}
