// 2 -> 2 / 2 -> 1
// 2 -> 2 - 1 -> 1

// 10 -> 10 / 2 -> 5 - 1 -> 4 / 2 -> 2 / 2 -> 1
// 10 -> 10 - 1 -> 9 / 3 -> 3 / 3 -> 1

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36
//     3     6     9       12       15       18       21       24       27       30       33       36
//   2   4   6   8   10    12    14    16    18    20    22    24    26    28    30    32    34    36

// 14 -> 14 / 2 -> 7 - 1 -> 6 / 2 -> 3 / 3 -> 1
// 14 -> 14 - 1 -> 13 - 1 -> 12 / 3 -> 4 - 1 -> 3 / 3 -> 1

// 8 -> 8 / 2 -> 4 / 2 -> 2 / 2 -> 1
// 8 -> 8 - 1 -> 7 - 1 -> 6 / 2 -> 3 / 3 -> 1

// 20 -> 20 / 2 -> 10 / 2 -> 5 - 1 -> 4 / 2 -> 2 / 2 -> 1
// 

// 1 <=      <= 1'000'000

#include <iostream>
#include <queue>

using namespace std;

void calculation(queue<int>& nums, int& count) {
    int temp = nums.front();

    int prevQueueNum{1};
    while (temp != 1) {
        int queueNum{0};

        count++;
        while (prevQueueNum > 0) {
            temp = nums.front();
            nums.pop();
            --prevQueueNum;

            

            if (temp % 3 == 0) {
                nums.push(temp / 3);
                queueNum++;

                if (temp / 3 == 1)
                    return;
            }
            if (temp % 2 == 0) {
                nums.push(temp / 2);
                queueNum++;

                if (temp / 2 == 1)
                    return;
            }
            nums.push(temp - 1);
            queueNum++;            
        }
        prevQueueNum = queueNum;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int count {0};

    queue<int> numbers;

    int start;
    cin >> start;

    numbers.push(start);

    calculation(numbers, count);

    cout << count;
}

/* ANSWER

#include <cstdio>
int min(int a, int b){
    return a> b? b: a;
}
int solve(int n) {
    if (n <= 1) return 0;
    int x, y;
    x = solve(n/3) + 1 + (n%3);
    y = solve(n/2) + 1 + (n%2);
    return min(x,y);
}
int main(void){
    int n;
    scanf("%d", &n);
    printf("%d\n", solve(n));
    return 0;
}

*/