#include <iostream>
#include <algorithm>

using namespace std;

int compare(int a, int b) {
    int result = a ^ b;
    int sum {0};
    for (int i = 0; i < 4; i++) {
        int x = result;
        int y = 1 << i;
        int z = x & y;
        if ( ( result & (1 << i) ) == (1 << i)) {
            sum++;
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    
    int N;

    char mbti[5];
    int mbtiInt {0b0000};

    int group[32];

    while (T > 0) {
        cin >> N;

        if (N > 32) {
            for (int t = 0; t < N; t++)
                cin >> mbti;

            cout << 0 << '\n';
            T--;
            continue;
        }

        // Reaching here, means N <= 32
        int index{0};
        int min {0x7fffffff};
        for (int t = 0; t < N; t++) {
            cin >> mbti;

            mbtiInt = 0b0000;

            mbtiInt |= mbti[0] == 'E' ? 0b0000 : 0b1000;
            mbtiInt |= mbti[1] == 'S' ? 0b0000 : 0b0100;
            mbtiInt |= mbti[2] == 'T' ? 0b0000 : 0b0010;
            mbtiInt |= mbti[3] == 'J' ? 0b0000 : 0b0001;

            group[t] = mbtiInt;
        }

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    int temp { compare(group[i], group[j]) + compare(group[j], group[k]) + compare(group[k], group[i])};
                    if (min > temp) {
                        min = temp;
                    }
                }
            }
        }



        cout << min << "\n";

        T--;
    }
}