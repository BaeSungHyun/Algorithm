#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int element{0};
    stack<int> Stack;
    string plusMinus;
    int maxElement{0};


    Stack.push(0);

    // loop : number of elements
    while (n > 0) {
        cin >> element;
        int temp{element};
        
        const int stackTop = Stack.top();

        if (element > stackTop) {
            int i {1};
            while (element > maxElement) {
                Stack.push(maxElement+i);
                plusMinus += "+";
                --element;
                ++i;
            }
            plusMinus += "-";
            Stack.pop();
        }
        else if (element == stackTop) {
            Stack.pop();
            plusMinus += "-";
        }
        else {
            cout << "NO";
            return 0;
        }
        --n;
        maxElement = max(maxElement, temp);
    }

    for (auto i : plusMinus) {
        cout << i << "\n";
    }
}



// if (element > stack.top()) -> stack.push
// else if (element == stack.top()) -> stack.pop
// else (element < stack.top()) -> NO

