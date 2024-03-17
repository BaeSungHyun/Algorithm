#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int row, col, height;

void updateCoordi(int*** volume, tuple<int, int, int> coordi, queue<tuple<int, int, int>>& reaped, int& zeroTomato, int& nextQueueSize) {
    // up : height + 1
    if (get<0>(coordi) + 1 < height && volume[get<0>(coordi) + 1][get<1>(coordi)][get<2>(coordi)] == 0) {
        volume[get<0>(coordi) + 1][get<1>(coordi)][get<2>(coordi)] = 1;
        zeroTomato--;
        reaped.push(make_tuple(get<0>(coordi) + 1, get<1>(coordi), get<2>(coordi)));
        nextQueueSize++;
    }

    // down : height - 1
    if (get<0>(coordi) - 1 >= 0 && volume[get<0>(coordi) - 1][get<1>(coordi)][get<2>(coordi)] == 0) {
        volume[get<0>(coordi) - 1][get<1>(coordi)][get<2>(coordi)] = 1;
        zeroTomato--;
        reaped.push(make_tuple(get<0>(coordi) - 1, get<1>(coordi), get<2>(coordi)));
        nextQueueSize++;
    }

    // left : row - 1
    if (get<1>(coordi) - 1 >= 0 && volume[get<0>(coordi)][get<1>(coordi) - 1][get<2>(coordi)] == 0) {
        volume[get<0>(coordi)][get<1>(coordi) - 1][get<2>(coordi)] = 1;
        zeroTomato--;
        reaped.push(make_tuple(get<0>(coordi), get<1>(coordi) - 1, get<2>(coordi)));
        nextQueueSize++;
    }
    
    // right : row + 1
    if (get<1>(coordi) + 1 < row && volume[get<0>(coordi)][get<1>(coordi) + 1][get<2>(coordi)] == 0) {
        volume[get<0>(coordi)][get<1>(coordi) + 1][get<2>(coordi)] = 1;
        zeroTomato--;
        reaped.push(make_tuple(get<0>(coordi), get<1>(coordi) + 1, get<2>(coordi)));
        nextQueueSize++;
    }

    // front : col - 1
    if (get<2>(coordi) - 1 >= 0 && volume[get<0>(coordi)][get<1>(coordi)][get<2>(coordi) - 1] == 0) {
        volume[get<0>(coordi)][get<1>(coordi)][get<2>(coordi) - 1] = 1;
        zeroTomato--;
        reaped.push(make_tuple(get<0>(coordi), get<1>(coordi), get<2>(coordi) - 1));
        nextQueueSize++;
    }
    
    // rear : col + 1
    if (get<2>(coordi) + 1 < col && volume[get<0>(coordi)][get<1>(coordi)][get<2>(coordi) + 1] == 0) {
        volume[get<0>(coordi)][get<1>(coordi)][get<2>(coordi) + 1] = 1;
        zeroTomato--;
        reaped.push(make_tuple(get<0>(coordi), get<1>(coordi), get<2>(coordi) + 1));
        nextQueueSize++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> col >> row >> height;

    int*** volume = new int**[height];

    int tomato;
    int queueSize;
    int zeroTomato {0};

    queue<tuple<int, int, int>> reaped;

    for (int h = 0; h < height; h++) {
        volume[h] = new int*[row];
        for (int r = 0; r < row; r++) {
            volume[h][r] = new int[col];
            for (int c = 0; c < col; c++) {
                cin >> tomato;
                volume[h][r][c] = tomato;

                if (tomato == 1) {
                    reaped.push(make_tuple(h,r,c));
                }

                if (tomato == 0) {
                    zeroTomato++;
                }
            }
        }
    }

    queueSize = (int)( reaped.size() );
    int nextQueueSize{0};

    if ((int)reaped.size() == col * row * height - 1) {
        cout << 0;

        for (int h = 0; h < height; h++) {
            for (int r = 0; r < row; r++) {
                delete[] volume[h][r];
            }
        }

        for (int h = 0; h < height; h++) {
            delete[] volume[h];
        }

        delete[] volume;

        return 0;
    }
    int days{0};

    while (!reaped.empty() && zeroTomato != 0) {
        if (queueSize == 0) {
            days++;
            queueSize = nextQueueSize;
            nextQueueSize = 0;
        }

        tuple<int, int, int> temp = reaped.front();
        reaped.pop();
        queueSize--;

        updateCoordi(volume, temp, reaped, zeroTomato, nextQueueSize);

        if (zeroTomato == 0)
            days++;
    }   

    if (zeroTomato == 0) {
        cout << days;
    } else {
        cout << -1;
    }

    for (int h = 0; h < height; h++) {
        for (int r = 0; r < row; r++) {
            delete[] volume[h][r];
        }
    }

    for (int h = 0; h < height; h++) {
        delete[] volume[h];
    }

    delete[] volume;
}