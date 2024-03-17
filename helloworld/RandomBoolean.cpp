#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution distr(0.5); // 50% chance of being true

    for(int n=0; n<10; ++n)
        std::cout << distr(gen) << ' ';
    std::cout << '\n';

    return 0;
}
