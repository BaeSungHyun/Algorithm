#include <iostream>

using namespace std;

class Node {
public: 
    char data;
    Node* link;

    Node(char n) {
        this->data = n;
        this->link = NULL;
    }
};

class Stack {
    Node* top;
public: 
    Stack() {top = NULL;}

    void push(char data) {
        Node* temp = new Node(data);

        temp->data = data;
        temp->link = top;
        top = temp; 
        // delete temp;
    }

    bool isEmpty() {
        return top == NULL;
    }

    // check isEmpty first
    char topData() {
        return top->data;
    }
    
    // check isEmpty first
    void pop() {
        Node* temp;
        
        temp = top;

        top = top->link;

        delete temp;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    cout.tie(NULL);

    bool finish{true};

    while (true) {
        char line[101];

        std::cin.getline(line, 101);

        if (line[0] == '.') 
            return 0;

        Stack lines;

        int count{0};
        while (count < 101) {
            switch (line[count]) {
                case '(': {
                    lines.push('(');
                    break;
                }
                case ')': {
                    if (lines.isEmpty() || lines.topData() != '(') {
                        count = 200;
                        finish = false;
                    } else if (lines.topData() == '(') {
                        lines.pop();
                    }
                    break;
                }
                case '[': {
                    lines.push('[');
                    break;
                }
                case ']': {
                    if (lines.isEmpty() || lines.topData() != '[') {
                        count = 200;
                        finish = false;
                    } else if (lines.topData() == '[') {
                        lines.pop();
                    }
                    break;
                }
                case '.': {
                    count = 200;
                    break;
                }
                default: {
                    break;
                }
            }
            ++count;
        }
        if (lines.isEmpty() && finish)
            cout << "yes\n";
        else 
            cout << "no\n";
        finish = true;
    }
}