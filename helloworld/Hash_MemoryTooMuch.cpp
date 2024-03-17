#include <iostream>

using namespace std;

const int MOD = 1 << 6; // 64
const int BIT = MOD - 1;
const int R = 7;

int hash(char arr[21]) {
    int mul = 1, res = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        res = (res + mul * arr[i] ) & BIT;
        mul = (mul * R) & BIT;
    }
    // BIT - sets limit to maximum digits (limit : MOD)
    return res;
}

bool strCmp(char *a, char *b) {
    int i {0};
    for (i; a[i] != '\0' || b[i] != '\0'; i++) {
        if (a[i] != b[i]) return false;
    }

    if (a[i] != b[i])
        return false;

    return true;
}


void strCpy(char *a, char *b)  {
    for (int i = 0; i < 21; i++) 
        a[i] = '\0';

    int i {0};
    for (i; b[i] != '\0'; i++) 
        a[i] = b[i];
}

struct Node {
    char category[21];
    Node *next {nullptr};
    short count {0};
};   

class HashMap {
    public:
        Node* map;

        int candidates[30];
        int candiIndex{0};

        HashMap() {
            map = new Node[MOD + 1];
        }

        ~HashMap() {
            delete[] map;
        }

        void insert(char category[21]) {
            int h = ::hash(category);

            Node* current = &map[h];
            
            Node *temp2 = current->next;
            while (temp2 != nullptr) {
                if (strCmp(temp2->category, category)) {
                    temp2->count++;
                    return;
                }
                temp2 = temp2->next;
            }

            Node* temp = new Node();

            strCpy(temp->category, category);
            temp->count = (short)1;

            candidates[candiIndex++] = h;
            
            // put temp right after current node
            temp->next = current->next;
            current->next = temp; // current will always be nullptr
        }

        unsigned int calculate() {
            unsigned int answer{1};
            for (int i = 0; i < MOD; i++) {
                Node* current = &map[i];
                current = current->next; // real current Node is always nullptr

                while (current != nullptr) {
                    answer *= (static_cast<unsigned int>(current->count) + 1);
                    current = current->next;
                }
            }
            return answer;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        HashMap m;

        for (int j = 0; j < N; j++) {
            char name[21];
            char category[21];
            cin >> name >> category;

            m.insert(category);        
        }

        cout << m.calculate() - 1 << "\n";
    }
}