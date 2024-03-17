#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int numberCards, target;

    cin >> numberCards >> target;
    int nC = numberCards;

    int number;
    vector<int> numbers;

    while (numberCards > 0) {
        cin >> number;
        numbers.push_back(number); 
        --numberCards;
    }

    int sum{0};
    int bestSum{0};

    for (int i = 0; i < nC; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < j; ++k) {
                sum = numbers[i] + numbers[k] + numbers[j];
                if (sum > target) 
                    continue;
                if (sum > bestSum)
                    bestSum = sum;
            }
        }
    }

    cout << bestSum;
}