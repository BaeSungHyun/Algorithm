// 자신의 아래 층 1호부터 b호 까지 계산 한 거만큼 더한다

#include <iostream>

using namespace std;


int recursive(int k, int n, const int N) {
    if (k == 0) {
            return n;
        }
    else {
        if (n == 1) {
            return 1;
        }
        return recursive(k, n-1, N) + recursive(k-1, n, N);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int test;
    cin >> test;

    int k, n;
    
    while (test > 0) {
        
        cin >> k >> n;
        cout << recursive(k, n, n) << "\n";
        --test;
    }
}