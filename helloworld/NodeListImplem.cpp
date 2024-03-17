#include <iostream>

using namespace std;

// [a1, a2, a3, a4 ... , ] -> cin into data structure
// 'R' - reverse. Linked List with boolean reverse value.
// 'D' - pop

struct Node {
    Node* previous;
    Node* next;
    int key;
    Node (int data) {
        key = data;
        previous = NULL;
        next = NULL;
    }
};

class NodeList {
public:
    bool reverse = false;

    struct Node* first {NULL};
    struct Node* last {NULL};

    void insert(int data) {
        Node* temp = new struct Node(data);

        if (first == NULL) {
            first = last = temp;
            return;
        } 

        switch (reverse) {
        case true: {
            temp->previous = last;
            last->next = temp;
            last = temp;
            break;
        }
        case false: {
            temp->next = first;
            first->previous = temp;
            first = temp;
            break;
        }
        }
    }

    int pop() {
        if (first == NULL)
            return -1; // means error

        switch (reverse) {
            case true: {
                Node* temp = first;
                first = first->next;
                if (first != NULL) {
                    first->previous = NULL;
                } 
                else if (first == NULL) 
                    last = NULL;
                
                int data = temp->key;
                delete temp; // existing first
                return data;
            }
            case false: {
                Node* temp = last;
                last = last->previous;
                if (last != NULL) {
                    last->next = NULL;
                }
                else if (last == NULL) {
                    first = NULL;
                }

                int data = temp->key;
                delete temp;
                return data;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    while (count > 0) {
        char* line = new char[100001];
        cin >> line;

        NodeList nodeNumbers;

        int numberCount;
        std::cin >> numberCount; 
        // arraySize = 2 + numberCount + numberCount - 1 
        //           = 2 * numberCount + 1 + \0
        
        char symbol{'['};// need to check if char array can be converted to int. ASCII? -48
        int number;
        std::cin >> symbol;
        
        while (symbol != ']') {
            if (numberCount == 0) {
                std::cin >> symbol;
                break;
            }
            std::cin >> number;
            std::cin >> symbol;
            nodeNumbers.insert(number);
        }      

        int i = 0;
        while (line[i] != '\0') {
            switch (line[i]) {
                case 'R': {
                    nodeNumbers.reverse = !(nodeNumbers.reverse);
                    break;
                }
                case 'D': {
                    --numberCount;
                    if (nodeNumbers.pop() == -1) {
                        cout << "error" << "\n"; 
                        i = -1;
                    } 
                    break;
                }
            }
            if (i == -1)
                break;
            ++i;
        }

        if (i != -1) {
            if (numberCount <= 0) {
                cout << "[]" << "\n";
                --count;
                continue;
            }
            cout << "[";
            while (numberCount > 0) {
                cout << nodeNumbers.pop();
                if (--numberCount == 0) 
                    break;
                cout << ",";
            }
            cout << "]";
            cout << "\n";
        }

        delete[] line;

        --count;
    }
}