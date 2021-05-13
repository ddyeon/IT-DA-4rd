#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, cnt=0;
int dp[1001][10] = { 0 };

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (i == 1)
				dp[i][j] = 1;
			else {
				for (int k = j; k <= 9; k++)
					dp[i][j] += dp[i - 1][k] % 10007;
			}
		}
	}
	int result = 0;
	for (int i = 0; i <= 9; i++)
		result += dp[N][i];
	cout << result%10007;
}