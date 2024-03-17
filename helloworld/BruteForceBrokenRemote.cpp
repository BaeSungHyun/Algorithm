#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

bool is_posible(bool *btn_broken, int channel) {
	while (true) {
		if (btn_broken[channel % 10]) {
			return false;
		}
		else {
			channel /= 10;
		}

		if (channel == 0) { break; }
	}

	return true;
}

int getDigit(int n) {
	int count = 1;
	while (n / 10 != 0) {
		n /= 10;
		count++;
	}

	return count;
}

int main() {
    

	int targetChannel;
	cin >> targetChannel;

	int numBrokenButton;
	cin >> numBrokenButton;

	bool btn_broken[10]{};
	int temp;
	for (int i = 0; i < numBrokenButton; i++) {
		cin >> temp;
		btn_broken[temp] = true;
	}

    auto start = chrono::high_resolution_clock::now();

	int ideal = 0xfffffff;

	// 100과 목표 채널의 차이 구하기
	int count = abs(targetChannel - 100);
	ideal = count;

    // if (numBrokenButton == 10) {
    //     cout << ideal;
    //     return 0;
    // }

	// 가능한 경우 중, 목표 채널과 가장 가까운 수를 구하고 차이 구하기
	// 낮은 채널 중 가장 가까운 채널 (일단 찾으면 더 낮은 걸 볼 필요가 없음)
	int lower = 0xfffffff;
	for (int i = targetChannel; i >= 0 && abs(targetChannel - i) < count; i--) {
		if (is_posible(btn_broken, i)){
			lower = i;
			break;
		}
	}
	
	// 높은 채널 중 가장 가까운 채널 (일단 찾으면 더 높은 걸 볼 필요가 없음)
	int upper = 0xfffffff;
	for (int i = targetChannel; abs(targetChannel - i) < count; i++) {
		if (is_posible(btn_broken, i)) {
			upper = i;
			break;
		}
	}

	//cout << "upper : " << upper << endl;

	int temp2;
	if (abs(upper - targetChannel) < abs(lower - targetChannel)) {
		temp2 = abs(upper - targetChannel) + getDigit(upper);
	}
	else {
		temp2 = abs(lower - targetChannel) + getDigit(lower);
	}

	if (ideal > temp2) { ideal = temp2; }

	// 출력

	cout << ideal;

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
    // micro : 10^-6
}