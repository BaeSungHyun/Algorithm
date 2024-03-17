#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numStairs;

    cin >> numStairs;

    int* stairScores = new int [numStairs + 1];

    for (int i = 1; i <= numStairs; i++) {
        cin >> stairScores[i];
    }

    int** matrix = new int*[numStairs + 1]; // 1-indexing
    for (int i = 0; i <= numStairs; i++) {
        matrix[i] = new int[numStairs + 1];
        for (int j = 0; j <= numStairs; j++) {
            matrix[i][j] = -1; // total score
        }
    }

    // initialize
    matrix[1][1] = stairScores[1];
    int max = matrix[1][1];
    
    if (numStairs >= 2) {
        matrix[2][1] = stairScores[2];
        if (max < matrix[2][1]) 
            max = matrix[2][1];
    }


    // DEBUGGING VARIABLE
    int debugVar;
    // loop
    for (int row = 1; row <= numStairs; row++) {
        for (int col = 1; col <= numStairs; col++) {
            // over number of stairs
            if (row + col - 1 > numStairs) {
                col = numStairs + 1;
                continue;
            }

            // checking (above - 2)
            if (row - 2 >= 1 && matrix[row - 2][col] != -1 && matrix[row][col] < matrix[row - 2][col] + stairScores[row + col - 1]) {
                matrix[row][col] = matrix[row - 2][col] + stairScores[row + col - 1];
                debugVar = matrix[row][col];
            }

            // checking (left - 1)
            if (col - 1 >= 1 && matrix[row][col - 1] != -1) {
                // check (above - 2) of (left - 1)
                if (row - 2 >= 1 && matrix[row-2][col - 1] != -1 && matrix[row][col] < matrix[row - 2][col - 1] + stairScores[row + col - 2] + stairScores[row + col - 1]) {
                    matrix[row][col] = matrix[row - 2][col - 1] + stairScores[row + col - 2] + stairScores[row + col - 1];
                    debugVar = matrix[row][col];
                }

                if (matrix[row][col] == -1) {
                    if (col - 2 >= 1 && matrix[row][col - 2] != -1) {
                        col = numStairs + 1;
                        continue;
                    } else if (col - 1 >= 1 && matrix[row][col] < matrix[row][col - 1] + stairScores[row + col - 1]) { // itself
                        matrix[row][col] = matrix[row][col - 1] + stairScores[row + col - 1];
                        debugVar = matrix[row][col];
                    }   
                }
            }

            // matching the end of stairs
            if (row + col - 1 == numStairs && max < matrix[row][col]) {
                max = matrix[row][col];
            }
        }
    }

    cout << max;

} 