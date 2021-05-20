#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
string s;
long long l;
long long dp[5001];
//dp[n] = dp[n] + dp[n-1] =>한자리 숫자
//dp[n] = dp[n] + dp[n-2] => 두자리 숫자
long long solve() {
	for (int i = 1; i <= s.length(); i++) {
		if (i == 0)continue;
		if (s[i] - '0' >= 1 && s[i] - '0' <= 9) {
			dp[i] = dp[i - 1] + dp[i];
		}
		
		int tmp = (s[i]-'0') + (s[i - 1]-'0') * 10;
		if (tmp >= 10 && tmp <= 26) {
			dp[i] = dp[i - 2] + dp[i];
		}
	}
	return dp[s.length()-1];
}

int main(void){
	cin >> s;
	dp[0] = 1;
	dp[1] = 1;
	cout << solve() % 1000000;
}