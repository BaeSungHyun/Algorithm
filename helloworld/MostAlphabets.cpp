#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char input[1'000'001]; 
    int alphabets[26];

    for (int i = 0; i < 26; i++) {
        alphabets[i] = 0;
    }

    cin >> input;

    int index = 0;

    while (input[index] != '\0') {
        alphabets[input[index] < 91 ? input[index] - 65 : input[index] - 97]++;
        index++;
    }

    bool multi {false};
    int maxIndex{0};
    int max{0};

    for (int i = 0; i < 26; i++) {
        if (alphabets[i] == 0)
            continue;
        if (max < alphabets[i]) {
            max = alphabets[i];
            multi = false;
            maxIndex = i;
        } else if (max == alphabets[i]) {
            multi = true;
        }
    }

    if (multi)
        cout << "?";
    else 
        cout << (char)(65 + maxIndex);
}