#include <iostream>
#include <random>

int main() {
    std::mt19937 gen(123); // Fixed seed
    std::uniform_int_distribution<> distr(1, 100);

    for(int n=0; n<10; ++n)
        std::cout << distr(gen) << ' ';
    std::cout << '\n';

    return 0;
}
