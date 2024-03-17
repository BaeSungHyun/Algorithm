#include<iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    long long int arr[100];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;

    for (int i = 3; i < 100; i++) {
        arr[i] = arr[i - 3] + arr[i - 2];
    }

    int N;
    for (int i = 0; i < T; i++) {
        cin >> N;

        cout << arr[N-1] << "\n";
    }
}