#include <iostream>
#include <queue>
#include <cmath>

using namespace std;



void flush(queue<char>& conversionHelper, int& converted) {
    converted = 0;
    while (!conversionHelper.empty()) {
        converted += (conversionHelper.front() - 48) * pow(10, conversionHelper.size() - 1);
        conversionHelper.pop();
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    queue<char> conversionHelper;
    int converted;

    char input[51];

    cin >> input;

    int plusNum {0}, minusNum{0};
    bool minus {false};

    for (int i = 0; i < 51; i++) {
        if (input[i] == '\0')
            break;

        if (input[i] != '-' && input[i] != '+') {
            conversionHelper.push(input[i]);
        } else {
            flush(conversionHelper, converted);

            if (minus) {
                minusNum += converted;
            } else {
                plusNum += converted;
            }

            if (input[i] == '-')
                minus = true;
        } 
    }

    flush(conversionHelper, converted);

    if (minus) {
        minusNum += converted;
    } else {
        plusNum += converted;
    }

    cout << plusNum - minusNum;
}