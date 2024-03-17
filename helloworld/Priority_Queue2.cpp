#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    priority_queue<int, vector<int>, greater<int>> elements;
    int n; 
    int element;

    cin >> n;
    while (n > 0) {
        cin >> element;
        if (element == 0) {
            if (elements.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << elements.top() << "\n";
                elements.pop();
            }
        }
        else {
            elements.push(element);
        }

        --n;
    }
}