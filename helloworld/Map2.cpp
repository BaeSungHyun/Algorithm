#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int count {0};
    int input {0};

    cin >> count;

    int* numbers = new int [count];
    map<int, int> numberMap;

    for (int i = 0; i < count; ++i) {
        cin >> input;
        numbers[i] = input;
        numberMap.insert({input, 0});
    }
    int i = 0;
    for (auto v : numberMap) {
        numberMap[v.first] = i++;
    }

    for (int i = 0; i < count; ++i) {
        cout << numberMap[numbers[i]] << " ";
    }

    delete[] numbers;
}
