#include <iostream>
#include <chrono>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    auto start = std::chrono::high_resolution_clock::now();

    int min {0x7fffffff};
    int sum;

    for (int a1 = 0; a1 * a1 <= n; a1++) {
        for (int a2 = a1; a1 * a1 + a2 * a2 <= n; a2++) {
            for (int a3 = a2; a1 * a1 + a2 * a2 + a3 * a3 <= n; a3++) {
                for (int a4 = a3; a1 * a1 + a2 * a2 + a3 * a3 + a4 * a4 <= n; a4++) {
                    if (a1 * a1 + a2 * a2 + a3 * a3 + a4 * a4 == n) {
                        sum = (a1 != 0 ? 1 : 0) + (a2 != 0 ? 1 : 0) + (a3 != 0 ? 1 : 0) + (a4 != 0 ? 1 : 0);
                        if (min > sum) 
                            min = sum;
                    }
                }
            }
        }
    }

    cout << min;

    // Stop timer
    auto stop = std::chrono::high_resolution_clock::now();

    // Calculate duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "\nTime taken by function: " << duration.count() << " milliseconds" << std::endl;
}