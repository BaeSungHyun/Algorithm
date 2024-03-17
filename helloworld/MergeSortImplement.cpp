#include <iostream>

using namespace std;


// defaut initizliaer take time ...... !!!! ex -> int arr[] {}

struct coordi {
    int x;
    int y;
    coordi(int x_, int y_) {
        x = x_;
        y = y_;
    }
    coordi() = default;

    // X& operator=(X& other); 
    coordi& operator=(const coordi& other) {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }

    bool operator<(const coordi& other) {
        if (this->x < other.x) return true;
        else if (this->x == other.x && this->y < other.y) return true;
        else return false;
    }
};

void merge(coordi input[], int left, int mid, int right) {
    // merge two
    // index number follows 'mergeSort' function 
    int leftIndex = left;
    int rightIndex = mid + 1;
    int ansIndex = left;

    coordi temp [100'000];

    while (leftIndex <= mid && rightIndex <= right) {
        if (input[leftIndex] < input[rightIndex]) {
            temp[ansIndex] = input[leftIndex++];
        }
        else {
            temp[ansIndex] = input[rightIndex++];
        }
        ansIndex++;
    }

    if (leftIndex > mid) {
        for (int t = rightIndex; t <= right; ++t) {
            temp[ansIndex++] = input[t];
        }
    }
    else {
        for (int t = leftIndex; t <= mid; ++t) {
            temp[ansIndex++] = input[t];
        }
    }

    for (int t = left; t <= right; ++t) {
        input[t] = temp[t];
    }
}

void mergeSort(coordi input[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // 2, 1 -> 1  /  3, 2 -> 2  /  5, 3 -> 4
        mergeSort(input, left, mid);
        mergeSort(input, mid + 1, right); // mid is slightly toward left side
        merge(input, left, mid, right);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    coordi input[100'000];
    int N;
    cin >> N;

    int tempX, tempY;
    for (int i = 0; i < N; i++) {
        cin >> tempX >> tempY;
        input[i] = coordi(tempX, tempY);
    }

    mergeSort(input, 0, N-1);

    for (int i = 0; i < N; i++) {
        cout << input[i].x << " " << input[i].y << "\n";
    }
} 