#include <iostream>

using namespace std;

const int MOD = 1 << 17;
const int BIT = MOD - 1;
const int R = 127;

int bhash(char* arr) {
    long long int mul = 1, res = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        res = (res + mul * arr[i] ) & BIT;
        mul = (mul * R) & BIT;
    }
    // BIT - sets limit to maximum digits (limit : MOD)
    return res;
}

bool strCmp(char* a, char* b) {
    for (int i = 0; a[i] != '\0' || b[i] != '\0'; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

struct Node {
    char name[21];
    char password[21];
    Node* next;
    Node() {
        next = nullptr;
    }
};

class HM {
    public:
        Node* map;

        HM() {
            map = new Node[MOD + 1];
        }

        void insert(char* arr, char* pwd) {
            int h = bhash(arr);

            Node* current = &map[h];
            Node* temp = new Node();

            int i {0};
            for (; arr[i] != '\0'; i++) {
                temp->name[i] = arr[i];
                arr[i] = '\0';
            }
            temp->name[i]= '\0';

            i = 0;
            for (; pwd[i] != '\0'; i++) {
                temp->password[i] = pwd[i];
                pwd[i] = '\0';
            }
            temp->password[i] = '\0';

            temp->next = current->next;
            current->next = temp;
        }

    Node* get(char* arr) {
        int h = bhash(arr);

        Node* current = &map[h];
        current = current->next;

        while (current != nullptr) {
            if (strCmp(current->name, arr)) return current;
            current = current->next;
        }

        return current;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    char s[21];
    char p[21];

    HM h;

    for (int i = 0; i < N; i++) {
        cin >> s >> p;
        h.insert(s, p);
    }


    for (int i = 0; i < M; i++) {
        cin >> s;
        Node* target = h.get(s);
        cout << target->password << "\n";
    }
}