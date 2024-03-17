#include <iostream>

using namespace std;

int min(int a, int b) {
    if (a > b) 
        return b;
    return a;
}

int recursive(int older, int younger) {
    if (older >= younger)
        return older - younger;
    if (older == 0) 
        return recursive(1, younger) + 1; // because recursive(-1, younger) + 1 is not possible
    if (younger % 2 == 1) // odd target number
        return min(recursive(older, younger - 1), recursive(older, younger + 1)) + 1;
    return min(1 + recursive(older, younger / 2), younger - older);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int older, younger;
    cin >> older >> younger;

    cout << recursive(older, younger);
}