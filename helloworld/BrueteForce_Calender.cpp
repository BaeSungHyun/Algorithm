#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void limitNum(int &m, int &n) {
    int lcm = (m / gcd(m, n)) * n;

    m = (lcm / m);
    n = (lcm / n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        int mLimit {M}, nLimit{N};
        limitNum(mLimit, nLimit);

        int cX {0}, cY{0};
        bool sign {false};

        while (cX < mLimit && cY < nLimit) {
            if (M * cX + x > N * cY + y) {
                cY++;
            } else if (M * cX + x < N * cY + y) {   
                cX++;
            } else {
                sign = true;
                break;
            }
        }

        if (x == M && y == N) {
            cout << M * cX + M << "\n";
            continue;
        }

        cout << (sign ? x + M * cX : -1) << "\n";
    }
} 