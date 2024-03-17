// Since Number of blocks == 256. It is not too many to store in an array.
// O(256) -> constant
// Divie and Conquer -> O(256 * log n) -> OK.

#include <iostream>
#include <stack>

using namespace std;

int groundMatrix[257]; // 0 ~ 256
int noneZeroMatrix[257];

int N, M, B;

int count = 0;

int calculator(int targetHeight) {
    int result = 0;

    for (int index = 0; index < count; index++) {
        if (noneZeroMatrix[index] - targetHeight > 0) { // discard
            result += 2 * (noneZeroMatrix[index] - targetHeight) * groundMatrix[noneZeroMatrix[index]];
        } else if (noneZeroMatrix[index] - targetHeight < 0) { // add block
            result += -1 * (noneZeroMatrix[index] - targetHeight) * groundMatrix[noneZeroMatrix[index]];
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> B;

    float sum{0};
    int temp;

    int left = 0x7fffffff;
    int right = (-0x7fffffff - 1);

    for (int cell = 0; cell < M*N; cell++){
        cin >> temp; // 0 ~ 256
        groundMatrix[temp]++;
        sum += temp;

        if (left > temp)
            left = temp;

        if (right < temp) 
            right = temp;
    }

    for (int index = 0; index < 257; index++) {
        if (groundMatrix[index] != 0)
            noneZeroMatrix[count++] = index; 
    }
    
    int minIndex;
    int result = 0x7fffffff;

    int upperBound = (int)((sum + B)/(M*N));

    for (int index = 0; index <= upperBound; index++) { // index: 0 ~ 256
        if (calculator(index) <= result){
            result = calculator(index);
            minIndex = index;
        }
    }
    

    cout << result << " " << minIndex;
}