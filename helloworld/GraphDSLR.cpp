#include <iostream>
#include <queue>

using namespace std;

// void numToDigit(int number, int* ans, int& index) {
//     if (index > 0) {
//         ans[index] = number % 10;
//         numToDigit(number / 10, ans, --index);
//     }
// }

// void digitToNum(int* ans) {
//     int mul = 1;
//     ans[0] = 0;
//     for (int i = 4; i > 0; i--) {
//         ans[0] += mul * ans[i];
//         mul *= 10;
//     }
// }

int D(int ans) {
    return (2 * ans) % 10'000;
}

int L(int ans) {
    return (ans % 1000) * 10 + ans / 1000;
}

int S(int ans) {
    int temp = (ans - 1 < 0) ? 9999 : ans - 1;
    return temp;
}

int R(int ans) {
    return (ans % 10) * 1000 + ans / 10;
}

struct history {
    char alphabet;
    int from;
};

void print(history* path, int cur, const int& A) {
    if (cur == A) return;
    print(path, path[cur].from, A);
    cout << path[cur].alphabet;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    int A, B;

    cin >> testCase;
    
    while (testCase-- > 0) {
        cin >> A >> B;

        bool updated[10'000];
        history path[10'000];

        for (int i = 0; i < 10'000; i++) {
            updated[i] = false;
        }

        int answer {A}; // number, digit1, digit2, digit3, digit4
        int index{4};
        // numToDigit(A, answer, index);
        // digitToNum(answer);

        updated[answer] = true;

        queue<int> q;
        q.push(A);
        // int qSize {1};

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            answer = current;
            // index = 4;
            // numToDigit(answer[0], answer, index);

            int temp = D(answer);
            if (!updated[temp]) {
                q.push(temp);
                updated[temp] = true;
                path[temp].from = current;
                path[temp].alphabet = 'D';
            }
            if (temp == B) {
                print(path, B, A);
                cout << "\n";
                break;
            }

            temp = L(answer);
            if (!updated[temp]) {
                q.push(temp);
                updated[temp] = true;
                path[temp].from = current;
                path[temp].alphabet = 'L';
            }
            if (temp == B) {
                print(path, B, A);
                cout << "\n";
                break;
            }

            temp = S(answer);
            if (!updated[temp]) {
                q.push(temp);
                updated[temp] = true;
                path[temp].from = current;
                path[temp].alphabet = 'S';
            }
            if (temp == B) {
                print(path, B, A);
                cout << "\n";
                break;
            }

            temp = R(answer);
            if (!updated[temp]) {
                q.push(temp);
                updated[temp] = true;
                path[temp].from = current;
                path[temp].alphabet = 'R';
            }
            if (temp == B) {
                print(path, B, A);
                cout << "\n";
                break;
            }
        }
    }
}