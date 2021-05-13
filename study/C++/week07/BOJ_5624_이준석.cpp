#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[400001] = { 0 };
vector<int>vec;
int main() {
	int N, result = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < i; j++) {
			if (dp[vec[i] - vec[j] + 200000] == 1) {
				result++;
				break;
			}
		}

		for (int j = 0; j <= i; j++)
			dp[vec[i] + vec[j] + 200000] = 1;
	}
	cout << result;
}