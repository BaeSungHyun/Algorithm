#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distr(0.0, 1.0); // Range from 0.0 to 1.0

    for(int n=0; n<10; ++n)
        std::cout << distr(gen) << ' ';
    std::cout << '\n';

    return 0;
}
