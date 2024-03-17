#include <iostream>
#include <cmath>

using namespace std;

// 명심하자. Traversing 과 Searching은 다른 문제다!

// 0-indexing matrix

//   0 1 2 3 4 5 6 7
// 0 
// 1
// 2
// 3
// 4
// 5
// 6 
// 7

// 4 corners - (0, 0, 7, 7) for whole matrix : question 6, 6 ?
// check 4 times
// (0, 0, 3, 3) (0, 4, 3, 7) (4, 0, 7, 3) (4, 4, 7, 7)
// (4, 4, 7, 7) picked - (size * size) * ( order of (4,4, 7,7) )  = 4 * 4 * 3 = 48
// (4, 4, 5, 5) (4, 6, 5, 7) (6, 4, 7, 5) (6, 6, 7, 7)
// (6, 6, 7, 7) picked - (size * size) * (order) = 2 * 2 * 3 = 12
// where is 6,6  in (6, 6, 7, 7) = first (0 in 0-indexing)
// answer : 48 + 12 + 0 = 60

int count{0};

int matrixSize;

int targetRow;
int targetCol;

bool order[2];

void searchMatrix(int& topLeftRow, int& topLeftCol, int& botRightRow, int& botRightCol) {
    int newTLR, newTLC, newBRR, newBRC;
    if (targetRow <= topLeftRow + (botRightRow - topLeftRow) / 2) {
        newTLR = topLeftRow;
        newBRR = topLeftRow + (botRightRow - topLeftRow) / 2;
        order[0] = false;
    } else {
        newTLR = topLeftRow + (botRightRow - topLeftRow) / 2 + 1;
        newBRR = topLeftRow + (botRightRow - topLeftRow);
        order[0] = true;
    }

    if (targetCol <= topLeftCol + (botRightCol - topLeftCol) / 2) {
        newTLC = topLeftCol;
        newBRC = topLeftCol + (botRightCol - topLeftCol) / 2;
        order[1] = false;
    } else {
        newTLC = topLeftCol + (botRightCol - topLeftCol) / 2 + 1;
        newBRC = topLeftCol + (botRightCol - topLeftCol);
        order[1] = true;
    }

    topLeftRow = newTLR;
    topLeftCol = newTLC;
    botRightRow = newBRR;
    botRightCol = newBRC;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    cin >> matrixSize >> targetRow >> targetCol;

    int tLR{0}, tLC{0}, bRR{pow(2, matrixSize) - 1}, bRC{pow(2, matrixSize) - 1};

    while (bRR - tLR != 1) {
        searchMatrix(tLR, tLC, bRR, bRC);

        if (order[0] && order[1]) {
            count += (bRR - tLR + 1) * (bRR - tLR + 1) * 3; 
        } else if (!order[0] && order[1]) {
            count += (bRR - tLR + 1) * (bRR - tLR + 1) * 1; 
        } else if (order[0] && !order[1]) {
            count += (bRR - tLR + 1) * (bRR - tLR + 1) * 2; 
        } else if (!order[0] && !order[1]) {
            count += (bRR - tLR + 1) * (bRR - tLR + 1) * 0; 
        }
    } 

    count += (targetRow - tLR) * 2 + (targetCol - tLC);

    cout << count;
}