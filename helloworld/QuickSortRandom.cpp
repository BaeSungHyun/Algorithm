// number sorting

#include <iostream>
#include <cstdlib>
#include "time.h"

using namespace std;


int partition(char arr[], int low, int high) {    
    int pivot = arr[high];

    int i = (low - 1);

    for (int j = low; j <= high - 1; ++j) {
        if ((int)arr[j] > pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int partition_r(char arr[], int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);

    swap(arr[random], arr[high]);

    return partition(arr, low, high);
}

void quickSort(char arr[], int low, int high) {
    if (low < high) {
        int pi = partition_r(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char* cp = new char[11]; // 1,000,000,000 + '\0'

    cin >> cp;  

    int count;

    for (int i = 0; i < 11; ++i) {
        if (cp[i] == '\0') {
            count = i;
            break;
        }
    }
    quickSort(cp, 0, count-1);

    cout << cp;   

    delete[] cp; 
}