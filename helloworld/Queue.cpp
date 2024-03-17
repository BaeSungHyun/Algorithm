#include <queue>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> humans;

    int total, target;
    cin >> total >> target;

    for (int i = 0; i < total; ++i) {
        humans.push(i + 1);
    }   
 
    cout << "<";
    while (!humans.empty()) {
        for (int i = 1; i < target; ++i) {
            humans.push(humans.front());
            humans.pop();
        }
        cout << humans.front();
        humans.pop();
        if (humans.empty())
            break;
        cout << ", ";
    }

    cout << ">";
}

// 1 2 3 4 5 6 7