#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int numbers[10001]{0};
    int number;

    while (N > 0) {
        cin >> number;

        ++numbers[number];

        --N;
    }

    for (int i = 1; i < 10001; ++i) {
        while (numbers[i] != 0) {
            cout << i << "\n";
            --numbers[i];
        }
    }
}