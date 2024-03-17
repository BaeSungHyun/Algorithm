#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long ans[1000 + 1]; 
    long long n;
    cin >> n; // target -> ans[n - 1]

    ans[1] = 1LL; // 2 x 1
    ans[2] = 2; // 2 x 2 

    for (int i = 3; i <= n; i++) {
        ans[i] = (ans[i - 2] + ans[i - 1]) % 10007LL;
    }


    cout << ans[n] % 10007LL;
}