#include <iostream>

using namespace std;

typedef pair<int, int> point;
point sortedArray[100000];

void merge(point* arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i].second < arr[j].second) {
            sortedArray[k] = arr[i]; // put small element first
            ++i;
        }
        else if (arr[i].second > arr[j].second) {
            sortedArray[k] = arr[j];
            ++j;
        }
        else if (arr[i].second == arr[j].second) {
            if (arr[i].first <= arr[j].first) {
                sortedArray[k] = arr[i];
                ++i;
            }
            else if (arr[i].first > arr[j].first) {
                sortedArray[k] = arr[j];
                ++j;
            }
        }
        ++k;    
    }
    if (i > mid) {
        for (int t = j; t <= right; ++t) {
            sortedArray[k] = arr[t];
            ++k;
        }
    }
    else if (j > right) {
        for (int t = i; t <= mid; ++t) {
            sortedArray[k] = arr[t];
            ++k;
        }
    }

    for (int t = left; t <= right; ++t) {
        arr[t] = sortedArray[t];
    }
}

void merge_sort(point* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, count{0};

    cin >> N;
    point pointArray[N];

    while (N > 0) {
        cin >> pointArray[count].first >> pointArray[count].second;
        --N;
        ++count;
    }

    merge_sort(pointArray, 0, count - 1);

    for (int i = 0; i < count; ++i) {
        cout << pointArray[i].first << " " << pointArray[i].second << "\n";
    }

}