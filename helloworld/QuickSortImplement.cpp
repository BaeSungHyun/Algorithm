#include <iostream>
#include <random>

using namespace std;

struct coordi {
    int x;
    int y;
    coordi(int x_, int y_) {
        x = x_;
        y = y_;
    }
    coordi() = default;

    // X& operator=(X& other); 
    coordi& operator=(const coordi& other) {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }

    bool operator<(const coordi& other) {
        if (this->y < other.y) return true;
        else if (this->y == other.y && this->x <= other.x) return true;
        else return false;
    }

    bool operator>(const coordi& other) {
        if (this->y > other.y) return true;
        else if (this->y == other.y && this->x >= other.x) return true;
        else return false;
    }
};

void swap(coordi& c1, coordi& c2) {
    coordi temp = c1;
    c1 = c2;
    c2 = temp;
}

void quickSort(coordi ans[100'000], int left, int right, uniform_int_distribution<int> &distr, mt19937 &gen) {
    if (left >= right) return;

    // new min and max range
    auto newParam = uniform_int_distribution<int>::param_type(left, right);
    distr.param(newParam);

    int random = distr(gen);
    // place pivot (random) on the most left side of array
    swap(ans[left], ans[random]);

    coordi* pivot = &(ans[left]);
    int i, j;
    // for loop initializes i, j just one bigger or smaller than proper bound
    for (i = left, j = right + 1; i < j;) {
        while (i < right && ans[++i] < *pivot);
        while (j > left && ans[--j] > *pivot);

        if (i < j) swap(ans[i], ans[j]);
    }
    // partition job done. Now switch with the pivot number
    swap(ans[left], ans[j]);

    quickSort(ans, left, j - 1, distr, gen);
    quickSort(ans, j + 1, right, distr, gen);
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

    coordi answer[100'000];
    int tempX, tempY;

    for (int i = 0; i < N; i++) {
        cin >> tempX >> tempY;
        answer[i] = coordi(tempX, tempY);
    }

    quickSort(answer, 0, N - 1, distr, gen);

    for (int i = 0; i < N; i++) {
        cout << answer[i].x << " " << answer[i].y << "\n";
    }
}