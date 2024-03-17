#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int MOD = 1 << 14; // 
const int BIT = MOD - 1;
const int R = 31;

int baeHash(char* arr) {
    long long int mul = 1, res = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        res = (res + mul * arr[i]) & BIT;
        mul = (mul * R) & BIT;
    }

    return res;
}

bool baeStrCmp(char* a, char* b) {
    for (int i = 0; a[i] != '\0' || b[i] != '\0'; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

struct Node {
        char* name;
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

        void insert(char* arr) {
            int h = baeHash(arr);
            Node* current = &map[h];
            // Node* temp = &orders[order_index++];
            Node* temp = new Node();

            // concatenate temp Node to current Node if Hash 'h' overlaps
            temp->name = arr;
            
            temp->next = current->next; // put temp at the front of the 'map'
            current->next = temp;
        }

        void contains(char* arr, vector<char*>& names) {
            int h = baeHash(arr);

            Node* current = &map[h];
            current = current->next;

            while (current != nullptr) {
                if (baeStrCmp((current->name), arr)) {    
                    names.push_back(current->name);   
                    break;                 
                }
                current = current -> next;
            }
        }

        Node* get(char* arr) {
            int h = baeHash(arr);

            Node* current = &map[h];
            current = current -> next;

            while (current != nullptr) {
                if (baeStrCmp(current->name, arr)) return current;
                current = current->next;
            }
            return current;
        }
};

bool compareChrPtr(const char* a, const char* b) {
    return strcmp(a, b) < 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    char name[21];

    HashMap hashMap;
    vector<char*> names;

    cin >> N >> M;

    for (int i = 0, j = 0; i < N; i++, j = 0) {
        cin >> name;
        char* temp = new char[21];
        strcpy(temp, name);
        hashMap.insert(temp);

        while (name[j] != '\0')
            name[j++] = '\0';
    }

    for (int i = 0; i < M; i++) {
        cin >> name;
        hashMap.contains(name, names);
    }

    sort(names.begin(), names.end(), compareChrPtr);
    cout << (int)names.size() << "\n";
    for (const auto& n : names) {
        cout << n << "\n";
    }
} 