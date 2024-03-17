#include <map>
#include <cmath>
#include <iostream>

using namespace std;

int getSecondMaximum(const map<int,int, greater<int>> &map) {
    auto first = map.begin();
    auto temp = map.begin();
    auto last = map.end();
    if (map.begin() == --map.end()) return (*(map.begin())).first;
    auto largest = first;
    while (++first != last) {
        if ((*largest).second < (*first).second)
            largest = first;
        else if ((*largest).second == (*first).second){
            temp = largest;
            largest = first;
        }
    }
    if ((*temp).second == (*largest).second)
        return (*temp).first;
    return (*largest).first;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    map<int, int, greater<int>> numbersCounts; // 오름차순

    int howMany;
    cin >> howMany;

    int number;
    double sum{0};
    for (int  i = 0; i < howMany; ++i) {
        cin >> number;
        if (numbersCounts.find(number) == numbersCounts.end()) {
            numbersCounts.insert(pair<int, int>(number, 1));
        }
        else {
            ++numbersCounts[number];
        }
        sum += static_cast<double>(number);
    }
    if (round(sum / static_cast<double>(howMany)) == -0) {
        cout << 0 << "\n";
    }
    else 
        cout << round(static_cast<double>(sum) / static_cast<double>(howMany)) << "\n";
    int target {(howMany - 1)/2 + 1};
    auto start {numbersCounts.begin()};
    while (target - (*start).second > 0) {
        target -= (*start).second;
        ++start;
    };
    cout << (*start).first << "\n";
    int range{-(*(--numbersCounts.end())).first + (*(numbersCounts.begin())).first };
    cout << getSecondMaximum(numbersCounts) << "\n";
    cout << range;
}