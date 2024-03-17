#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    // 1. save each lantern's length in container
    // 2. divide and get integer value of lantern's length
    // 3. until count of lantern exceed N

    unsigned int K, N;
    cin >> K >> N;

    unsigned int length;
    // 1. save each lantern's length in container
    vector<unsigned int> lengthsOrigin;
    unsigned int divideLength{0};
    for (int i = 0; i < K; ++i) {
        cin >> length;
        lengthsOrigin.push_back(length);

        if (length > divideLength) {
            divideLength = length;
        }
    }

    // 2. divide and get integer value of lantern's length
    // 3. until count of lantern exceed N

    // use binary search 
    
    unsigned int sum;

    

    unsigned int left{1};

    while (left <= divideLength) {
        unsigned int mid = (left + divideLength)/2;
        sum = 0;

        auto check = [&mid, &sum](unsigned int x) -> void {
            sum += (x / mid);
        };

        for_each(lengthsOrigin.cbegin(), lengthsOrigin.cend(), check);
        if (sum >= N) {
            left = mid + 1;
        }
        else {
            divideLength = mid - 1;
        }
    }

    cout << divideLength;
}