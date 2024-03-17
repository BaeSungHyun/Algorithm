#include <iostream>

using namespace std;

void calculation(int* answer, int pos) {
    if (answer[pos] == -1) {
        calculation(answer, pos - 1);
    }
    // reaching here, one less than position that contains '-1'
    pos++;
    answer[pos] = answer[pos - 1] + answer[pos - 2] + answer[pos - 3];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // 1 == 1
    // 2, 1 + 1 == 2
    // 3, 1 + 2, 2 + 1, 1 + 1 + 1 == 4
    int answers[11] = {1, 1, 2, 4, -1, -1, -1, -1, -1, -1, -1}; // 1-indexing
    
    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        int temp;
        cin >> temp;
        if (answers[temp] != -1) {
            cout << answers[temp];
        } else {
            calculation(answers, temp);
            cout << answers[temp];
        }
        cout << "\n";
    }    
}