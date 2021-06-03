#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int H, W, mx = 0;
vector<int>vec;
int main() {
	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
		mx = max(a, mx);
	}
	int start = W, end = -1, cnt = 0;
	for (int i = 1; i <= mx; i++) {
		for (int j = 0; j < W; j++) {
			if (i > vec[j]) {
				start = min(start, j);
				end = max(end, j);
			}
			else {
				if (start != W && end != -1) {
					if (start != 0 && end != W - 1) {
						cnt += end - start + 1;
					}
				}
				start = W, end = -1;
			}
		}
	}
	cout << cnt;
}