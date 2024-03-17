#include <iostream>
#include <random>

using namespace std;

struct info {
    int order;
    char name[101];
    unsigned short age;

    info() {
        order = 0;
        age = 0;
    }

    bool operator<(const info &other) {
        if (age < other.age) return true;
        else if (age == other.age && order < other.order) return true;
        else return false; 
    }

    bool operator>(const info &other) {
        return !(*this < other);
    }
};

void swap1(info& i1, info& i2) {
    info temp = i1;
    i1 = i2;
    i2 = temp;
}

void quickSort(info answer[100'000], int left, int right, uniform_int_distribution<int> &distr, mt19937 &gen) {
    if (left >= right) return;
   
    auto newParam = uniform_int_distribution<int>::param_type(left, right);
    distr.param(newParam);

    int random = distr(gen);

    swap(answer[left], answer[random]);

    info* pivot = &(answer[left]);

    int i, j;

    for (i = left, j = right + 1; i < j;){
        while (i < right && answer[++i] < *pivot);
        while (j > left && answer[--j] > *pivot);

        if (i < j) swap(answer[i], answer[j]);
    }

    swap1(answer[left], answer[j]);

    quickSort(answer, left, j - 1, distr, gen);
    quickSort(answer, j + 1, right, distr, gen);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution distr(0, N - 1);

    info answer[100'000] {};

    for (int i = 0; i < N; i++) {
        cin >> answer[i].age >> answer[i].name;
        answer[i].order = i;
    }

    quickSort(answer, 0, N - 1, distr, gen);

    for (int i = 0; i < N; i++) {
        cout << answer[i].age << " " << answer[i].name << "\n";
    }
}