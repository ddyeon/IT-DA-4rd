#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
int H, W;
int arr[501];
int ans = 0;
int main(void) {
	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		cin >> arr[i];
	}
	int left = 0, right = 0, i = 0, j = 0;
	while (1) {
		for (i = j; i < W; i++) {
			if (arr[i] == 0)continue;
			left = arr[i];
			break;
		}
		int getMax = 0, maxIdx = i;
		for (j = i + 1; j < W; j++) {
			if (arr[j] > left) {
				getMax = arr[j];
				break;
			}
			if (getMax < arr[j]) {
				getMax = arr[j];
				maxIdx = j;
			}
		}
		if (getMax == 0)break;
		if (getMax > left) {
			for (int k = i + 1; k < j; k++) {
				ans += left - arr[k];
			}
		}
		else {
			for (int k = i + 1; k < maxIdx; k++) {
				ans += getMax - arr[k];
			}
			j = maxIdx;
		}
		if (j >= W - 1)break;
	}
	cout << ans;
}