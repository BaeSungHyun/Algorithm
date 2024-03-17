#include <iostream>
#include <cmath>
#include <stack>
#include <utility>

using namespace std;

stack<pair<int, int>> startIndex;
int target;

void traverseMatrix(int index, int size, int& count) {
    startIndex.push({index, size});

    while (!startIndex.empty()) {
        int tempIndex {startIndex.top().first};
        int tempSize {startIndex.top().second};

        if (tempSize == 2) {
            int order[4] = {0, 1, size, size + 1};
            for (int i = 0; i < 4; i++) {
                if (tempIndex + order[i] == target)
                    return;
                
                count++;
            }
            startIndex.pop();
            continue;
        }

        startIndex.pop();

        // index, index + size / 2, index + size * size / 2, index + size * size / 2 + size / 2
        startIndex.push({tempIndex + size * tempSize / 2 + tempSize /2, tempSize / 2});
        startIndex.push({tempIndex + size * tempSize / 2, tempSize / 2});
        startIndex.push({tempIndex + tempSize /2, tempSize / 2});
        startIndex.push({tempIndex, tempSize / 2});
    }        
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int initialSize;
    int row, col;

    int count{0};

    cin >> initialSize >> row >> col;

    initialSize = pow(2, initialSize);

    target = initialSize * (row)  + col;

    traverseMatrix(0, initialSize, count);

    // Top left corner element 
    // 0,1,2,3 -> 0
    // 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 -> 0, 2, 8, 10
    // 0 ~ 63 -> 0, 4, 32, 36

    // function parameter : starting index, size (N), count (for counting visiting number)
    //      terminating condition : size == 1


    cout << count;
}
