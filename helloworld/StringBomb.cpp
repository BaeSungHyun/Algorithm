#include <iostream>
#include <string>

using namespace std;

struct Node {
    Node* above = nullptr;
    Node* below = nullptr;
    char data;

    Node(char x) {
        data = x;       
    }
};

class explodeStack{
    public:
        explodeStack(int size, string explosionString) 
        :size(size), explosionString(explosionString) {
        }

        bool isEmpty() {
            return (top == nullptr);
        }

        void push(char x) {
            Node* temp = new Node(x);
            temp->below = top;
            if (numelt == 0) {
                bot = temp;
                top = temp;
            } else {
                top->above = temp;
                top = temp;
            }
            numelt++;
        }

        void pop() {
            if (isEmpty()) return;

            for (int i = 0; i < (int)explosionString.size(); i++) {
                Node* temp = top;
                if (top->below != nullptr)
                    top->below->above = nullptr;
                top = top->below;
                delete temp;
                numelt--;
            }
        }

        bool check() {
            bool s = true;
            Node* temp = top;
            for (int i = 0; i < (int)explosionString.size(); i++) {
                if (temp == nullptr) 
                    return false;
                if (temp->data == explosionString[(int)explosionString.size() - 1 - i]) {
                    temp = temp->below;
                } else {
                    s = false;
                    break;
                }
            }

            return s;
        }

        void print() {
            string y;
            Node* temp;
            temp = bot;
            while (!isEmpty() && temp != nullptr) {
                y += temp->data;
                temp = temp->above;
            }

            if (y.empty()){
                cout << "FRULA";
                return;
            }
            cout << y;
        }

    private:
        Node* bot = nullptr;
        Node* top = nullptr;
        int numelt = 0;
        int size;
        string explosionString;

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string inputs;
    string explosion;

    cin >> inputs;
    cin >> explosion;


    explodeStack remain(inputs.size(), explosion);
    
    for (int i = 0; i < (int)inputs.size(); i++) {
        remain.push(inputs[i]);

        if (inputs[i] == explosion.back()) {
            if (remain.check()) {
                remain.pop();
            }
        }
    }

    remain.print();
}