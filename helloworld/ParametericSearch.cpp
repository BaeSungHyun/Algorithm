// binary search

// calcul

// sort the array
// initial value : middle value
// if sum > target
// initial value = middle + 1 ~ high
// else if sum < target
// initial value = low ~ middle - 1
// else if sum == target
// initial value = middle

#include <iostream>
#include <algorithm>

using namespace std;


long long calculate(int arr[], int& size, long long& sol) {
    long long calculation{0};
    for (int i = 0 ; i < size; ++i) {
        if (arr[i] <= sol) {
            continue;
        }
        else {
            calculation += (long long)(arr[i] - sol);
        }
    }
    return calculation;
}

long long binarySearch(int arr[], int size, long long lowSol, long long highSol, long long target) {
    if (highSol <= lowSol) {  
        cout << "1: " << "target: " << target << " calculation: " << calculate(arr, size, lowSol) << " lowSol: " <<  lowSol << "\n";
        return (target <= calculate(arr, size, lowSol)) ? (lowSol) : lowSol - 1; 
        // return (target > calculate(arr, size, lowSol)) ? (lowSol - 1) : lowSol;
    }

    long long midSol = (lowSol + highSol) / 2;

    if (target == calculate(arr, size, midSol)) {
        cout << "2: " << "target: " << target << " calculation: " << calculate(arr, size, midSol) << " midSol: " <<  midSol << "\n";
        return midSol;
    }

    if (target < calculate(arr, size, midSol)) {
        cout << "3: " << "target: " << target << " calculation: " << calculate(arr, size, midSol) << " midSol: " <<  midSol << "\n";
        return binarySearch(arr, size, midSol + 1, highSol, target);
    }

    cout << "4: " << "target: " << target << " calculation: " << calculate(arr, size, midSol) << " midSol: " <<  midSol << "\n";
    return binarySearch(arr, size, lowSol, midSol - 1, target);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    long long M;
    long long initial{0};
    cin >> N >> M; 

    int* tree = new int[N];

    for (int i = 0; i < N; ++i) {
        cin >> tree[i];
        if (initial < tree[i]) {
            initial = tree[i];
        }
    }
    
    long long loc = binarySearch(tree, N, 0, initial, M);

    cout << loc;

    delete[] tree;
}