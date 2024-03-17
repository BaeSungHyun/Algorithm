#include <iostream>

using namespace std;

void heapify(int arr[], int N, int i) {
    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && arr[l] > arr[largest])
        largest = l;
    else if (l < N && arr[l] == arr[largest]) {

    }
    
    if (r < N && arr[r] > arr[largest]) 
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N) {
    for (int i = N / 2 -1; i >= 0; --i) {
        heapify(arr, N, i);
    }

    for (int i = N - 1; i > 0; --i) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    int countNum = 0;

    cin >> count;

    int* ageArr = new int[count];
    char** nameArr = new char*[count];

    int age;
    char* name = new char[101];

    while (count > 0) {
        cin >> age;
        cin >> name;

        for (int i = 0; i < 101; ++i) {
            if (name[i] == '\0') {
                char* newName = new char[i+1];
                for (int j = 0; j <= i; ++j) {
                    newName[j] = name[j];
                }
                delete[] name;
                name = newName;
            }
        }
        ageArr[countNum] = age;
        nameArr[countNum] = name;

        ++countNum;
        --count;
    }
}