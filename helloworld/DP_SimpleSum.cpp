#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int* sum = new int[N + 1]; 
    sum[0] = 0;

    int temp;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        sum[i] = sum[i - 1] + temp;
    } 

    int start, end;
    for (int i = 0; i < M; i++) {
        cin >> start >> end;

        cout << sum[end] - sum[start - 1];
        cout << "\n";
    }
} 