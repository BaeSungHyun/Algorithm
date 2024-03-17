// Divide and Conquer
// Pivot is important = in worst case: n^2 N + N-1 + N-2 + N-3 + ...

#include <stdio.h>

// Swap
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// void pivotFunction();


// Partition the array using the last element as the pivot or make the pivot function
int partition(int arr[], int low, int high) {
    // Choosing pivot
    int pivot = arr[high];

    // index of smaller element and indicates the right position of pivot found so far
    int i = (low - 1);

    for (int j = low; j <= high - 1; ++j) {
        // current < pivot -> swap
        if (arr[j] < pivot) {
            ++i;
            swap(&arr[i], &arr[j]);
        }
        // else -> leave it alone
    }
    swap(&arr[i+1], &arr[high]);  // swap pivot with its right position
    return (i+1); // return right position of the pivot inside array
}

// main function for Quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // separately sort elements before partition and after partition
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(void) {
    int arr[] = {10, 7, 8, 9 , 1, 5};
    int N = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, N-1);

    return 0;
}