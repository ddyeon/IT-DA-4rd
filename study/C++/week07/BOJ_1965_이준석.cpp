#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1001] = { 0 };
vector<int>vec;
int main() {
	int N, result=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (vec[j] < vec[i]) {
				dp[i+1] = max(dp[i+1], dp[j+1] + 1);
				result = max(result, dp[i + 1]);
			}
		}
	}
	cout << result + 1;
}