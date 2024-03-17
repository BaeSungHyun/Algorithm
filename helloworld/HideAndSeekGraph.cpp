#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int older, younger;
    cin >> older >> younger;

    if (older >= younger) {
        cout << (older - younger);
        return 0;
    }

    int* traverse = new int[younger + 2]; // if younger == odd number, need to check one more even number and then -1 

    traverse[older] = 0;

    int temp;

    for (int i = older - 1; i >= 0; i--) {
        traverse[i] = traverse[i + 1] + 1;
    }

    int even;
    if ((older + 1) % 2 == 0) {
        even = older + 1;
    } else {
        traverse[older + 1] = 1;
        even = older + 2;
    }

    for (int i = even; i <= younger + 1; i += 2) {
        traverse[i] = traverse[i / 2] + 1 > traverse[i - 1] + 1 ? traverse[i - 1] + 1 : traverse[i / 2] + 1;
        traverse[i - 1] = traverse[i - 1] > traverse[i] + 1 ? traverse[i] + 1 : traverse[i - 1];
        traverse[i + 1] = traverse[i] + 1;
    }

    cout << traverse[younger];

    delete[] traverse;
}