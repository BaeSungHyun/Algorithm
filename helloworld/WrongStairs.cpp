// WRONG!!!! MEMORY 초과


#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int numStairs;
    cin >> numStairs;

    int* stairScores = new int[numStairs];
    for (int i = 1; i <= numStairs; i++) { // 1-indexing
        cin >> stairScores[i];
    }

    stack<int*> stairs;
    // [step gap , total score , current stair position]
    if (numStairs >= 2) {
        stairs.push(new int[3] {1, stairScores[1] + stairScores[2], 2});
        stairs.push(new int[3] {2, stairScores[2], 2});
    }
    stairs.push(new int[3] {1, stairScores[1], 1});

    int max{0};

    while (!stairs.empty()) {
        int* temp = stairs.top();
        stairs.pop();

        if (temp[2] == numStairs) {
            if (max < temp[1]) {
                max = temp[1];
            }
            delete[] temp;
            continue;
        }

        switch (temp[0]) {
            case 1: {
                if (temp[2] + 2 <= numStairs) {
                    stairs.push(new int[3] {2, temp[1] + stairScores[temp[2] + 2], temp[2] + 2});
                    delete[] temp;
                }
                break;
            }
            case 2: {
                if (temp[2] + 1 <= numStairs) {
                    stairs.push(new int[3] {1, temp[1] + stairScores[temp[2] + 1], temp[2] + 1});
                    stairs.push(new int[3] {2, temp[1] + stairScores[temp[2] + 2], temp[2] + 2});
                    delete[] temp;
                }
                break;
            }
            default: {
                break;
            }
        }
    }
    cout << max;
}