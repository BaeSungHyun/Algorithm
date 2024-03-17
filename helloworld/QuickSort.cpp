#include <iostream>
#include <random>

using namespace std;

void swap(int& num1, int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void Quicksort(int* arr, int left, int right, uniform_int_distribution<> &distr, mt19937 &gen) { // left and right should be possible index of array
    if (left >= right) return;

    auto newParamType = uniform_int_distribution<int>::param_type(left, right);
    distr.param(newParamType);

    cout << distr.a() << " " << distr.b() << " ";
    int random = distr(gen);
    swap(arr[left], arr[random]);

    int pivot = arr[left];
    int i, j;
    for (i = left, j = right + 1; i < j;) {
        while (i < right && arr[++i] < pivot);
        while (j > left && arr[--j] > pivot);

        if (i < j) // reaching here : arr[i] >= pivot && arr[j] <= pivot
            swap(arr[i], arr[j]);
    }
    // reaching here, partition done. Now switch with pivot number
    swap(arr[left], arr[j]);

    Quicksort(arr, left, j - 1, distr, gen);
    Quicksort(arr, j + 1, right, distr, gen);
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Quick Sort?
    int num;
    cin >> num;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, num - 1);

    int* answer = new int [num];

    for (int i = 0; i < num; i++) {
        cin >> answer[i];
    }

    Quicksort(answer, 0, num - 1, distr, gen);

    int sum {0};

    for (int i = 0; i < num; i++) {
        sum += answer[i] * (num - i);
    }

    cout << sum;
}