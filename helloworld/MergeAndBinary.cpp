// N integers 
// M integers
// find out if element in M integers is inside N integers
#include <iostream>

using namespace std;

int sortedArray[100001];

void merge(int *arr, int left, int mid, int right) {
    int i = left;
    int j = mid+1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            sortedArray[k] = arr[i];
            ++i;
        }
        else {
            sortedArray[k] = arr[j];
            ++j;
        }
        ++k;
    }
    if (i > mid) {
        for (int t = j; t <= right; ++t) {
            sortedArray[k] = arr[t];
            ++k;
        }
    }
    else {
        for (int t = i; t <= mid; ++t) {
            sortedArray[k] = arr[t];
            ++k;
        }
    }

    for (int t = left; t <= right; ++t) {
        arr[t] = sortedArray[t];
    }
}

void merge_sort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right-left)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

// binarySearch 는 직접 구현할 때, left == right 일 때를 조심하자
bool binarySearch(int* arr, int target, int left, int right) {
    // Repeat until the pointers low and high meet each other
    if (left == right) 
        return true;
    
    while (left <= right) {
        int mid = left + (right - left) /2;

        if (arr[mid] == target) 
            return true;

        if (arr[mid] < target) 
            left = mid + 1;

        else 
            right = mid-1;
    }

    return false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int* arrN = (int*)malloc(sizeof(int) * n);

    for (int t = 0; t < n; ++t) {
        cin >> arrN[t]; 
    } 

    merge_sort(arrN, 0, n-1);

    int m;
    cin >> m;

    for (int t =0; t < m; ++t) {
        cin >> n;
        if (binarySearch(arrN, n, 0, m-1)) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }


    
}