#include <iostream>
using namespace std;

// Heapify - Max Heap
void heapify(int arr[], int N, int i) {
    // initialize largest as root
    int largest = i;
    // left node
    int l = 2 * i + 1;
    // right node
    int r = 2 * i + 2;

    // If left larger than root
    if (l < N && arr[l] > arr[largest]) {
        largest = l;
    }

    // if right larger than root
    if (r < N && arr[r] > arr[largest]) {
        largest = r;
    }
    
    // If largest is not initial root
    if (largest != i) {
        swap(arr[i], arr[largest]);
    
        // recursively heapify the affected sub-tree
        heapify(arr, N, largest);
    }
}


// Heap Sort - Move the root element of Max Heap to actual array
void heapSort(int arr[], int N) {
    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; --i){
        // need i = N / 2 - 1 : ??????????????????
        heapify(arr, N, i);
    }

    // One by one extract element from heap
    for (int i = N - 1; i > 0; --i) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }

}

int main() {
    int arr[] = {4, 10, 3, 5, 1};

    heapSort(arr, 5);

    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
}