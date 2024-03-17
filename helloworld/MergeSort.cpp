// Let's go with mergeSort. Binary fail.
#include <iostream>

using namespace std;

struct Point{
    int x;
    int y;
} point;

void merge(struct Point* sortedArr, struct Point* arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i].x < arr[j].x) {
            sortedArr[k] = arr[i];
            ++i;
        }
        else if (arr[i].x > arr[j].x) {
            sortedArr[k] = arr[j];
            ++j;
        }
        else {
            if (arr[i].y < arr[j].y) {
                sortedArr[k] = arr[i];
                ++i;
            }
            else {
                sortedArr[k] = arr[j];
                ++j;
            }
        }
        ++k;
    }
    if (i > mid) {
        for (int t = j; t <= right; ++t) {
            sortedArr[k] = arr[t];
            ++k;
        }
    }
    else {
        for (int t = i; t <= mid; ++t) {
            sortedArr[k] = arr[t];
            ++k;
        }
    }

    for (int t = left; t <= right; ++t) {
        arr[t] = sortedArr[t];
    }
}

void mergeSort(struct Point* sortedArr, struct Point* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(sortedArr, arr, left, mid);
        mergeSort(sortedArr, arr, mid+1, right);
        merge(sortedArr, arr, left, mid, right);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    struct Point* sortedArr = new struct Point[count];
    struct Point* ptr = new struct Point[count];
    int x, y;
    for (int i = 0; i < count; ++i) {
        cin >> ptr[i].x >> ptr[i].y;
    }

    mergeSort(sortedArr, ptr, 0, count - 1);

    for (int i = 0; i < count; ++i) {
        cout << sortedArr[i].x << " " << sortedArr[i].y << "\n";
    }

    delete[] ptr;
    delete[] sortedArr;
}
