#include <iostream>

using namespace std;

bool charEqual(char* a, const char* b){
    int index = 0;

    if (a[index] == '\0' || b[index] == '\0') {
        return false;
    }

    while (a[index] == b[index]) {
        if (a[index] == '\0' && b[index] == '\0')
            return true;

        index++;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int M;

    int S {0b00'000'000'000'000'000'000}; // 20 bits

    cin >> M;

    char operation[7];
    short target;

    for (int i = 0; i < M; i++) {
        cin >> operation;
        
        switch (operation[1]) {
            case 'l': {
                S = 0b11'111'111'111'111'111'111;
                break;
            } case 'm' : {
                S = 0b0;
                break;
            } default : {
                cin >>target;
                break;
            }
        }

        switch (operation[1]) {
            case 'd': {
                S |= (1 << (target - 1));
                break;
            }
            case 'e': {
                S &= ~(1 << (target - 1));
                break;
            }
            case 'h': {
                cout << (S & (1 << (target - 1)) ? 1 : 0) << "\n";
                break;
            }
            case 'o': {
                S = (S & (1 << (target - 1)) ? (S & ~(1 << (target - 1))) : (S | (1 << (target - 1))) );
                break;
            }
        }
    }
}