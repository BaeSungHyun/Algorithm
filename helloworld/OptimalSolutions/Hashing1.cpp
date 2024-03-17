#include <iostream>

using namespace std;

const int MOD = 1 << 16; // 1'000'000'000'000'000
const int BIT = MOD - 1; //   111'111'111'111'111
const int R = 127;

int baeHash(char* arr) {
    long long int mul = 1, res = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        res = (res + mul * arr[i] ) & BIT;
        mul = (mul * R) & BIT;
    }
    // BIT - sets limit to maximum digits (limit : MOD)
    return res;
}

bool baeStrcmp(char* a, char* b) {

    for (int i = 0; a[i] != '\0' || b[i] != '\0'; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

struct Node {
        char* name;
        int index;
        Node* next;
        Node() {
            next = nullptr;
        }
};

class HashMap {
    public:
        Node* map;
        // Node* orders;
        // int order_index;

        HashMap() {
            map = new Node[MOD + 1];
            // orders = new Node[100000 + 1];
            // order_index = 0;
        }

        void insert(char* arr, int index) {
            int h = baeHash(arr);
            Node* current = &map[h];
            // Node* temp = &orders[order_index++];
            Node* temp = new Node();

            // concatenate temp Node to current Node if Hash 'h' overlaps
            temp->name = arr;
            temp->index = index;
            
            temp->next = current->next; // put temp at the front of the 'map'
            current->next = temp;
        }

        Node* get(char* arr) {
            int h = baeHash(arr);

            Node* current = &map[h];
            current = current -> next;

            while (current != nullptr) {
                if (baeStrcmp(current->name, arr)) return current;
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
    char temp[21];
    char (*input)[21] = new char [100001][21];
    int tempInt;

    HashMap hashMap;

    // input
    for (int i = 1; i <= N; i++) {
        cin >> input[i];
        hashMap.insert(input[i], i);
    }

    // output
    for (int i = 1; i <= M; i++) {
        cin >> temp;
        if ('0' <= temp[0] && temp[0] <= '9') { // if index
            sscanf(temp, "%d", &tempInt);

            cout << input[tempInt] << "\n";
        } else {
            cout << hashMap.get(temp)->index << "\n";
        }

        for (int j = 0; j < 21; j++) {
            temp[j] = '\0';
        }
    }
}