#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
/*
N행에서의 방의 모습은 3가지 경우 뿐이다. (□열림, ■닫힘)
F = 0 : ■□ (왼쪽만 닫힘)
F = 1 : □■ (오른쪽만 닫힘)
F = 2 : □□ (닫히지 않음)

F가 0인 경우에서 N-1행은 0이나 2의 F형태가 와야한다.
F가 1인 경우에서 N-1행은 1이나 2의 F형태가 와야한다.
F가 2인 경우에서는 3가지 형태 모두 가능하다.

이러한 틀로 점화식을 유도 할 수 있다.

DP[N][K][F] : N행까지 방을 K개 닫고 N행이 F인 모습일때 닫히지 않은 방들의 가치의 최대합

*/
using namespace std;
int N, K;
int map[201][2];
int dp[202][202][3];
int main() {
    int a, b;
    cin >> N >> K;
    for (int n = 1; n <= N; n++)
        cin >> map[n][0] >> map[n][1];
    cin >> a >> b;

    dp[1][1][0] = map[1][1];
    dp[1][1][1] = map[1][0];
    dp[1][0][2] = map[1][1] + map[1][0];

    for (int n = 2; n <= N; n++) {
        for (int k = 0; k <= K; k++) {
            if (k >= 1) {
                dp[n][k][0] = max(dp[n - 1][k - 1][0], dp[n - 1][k - 1][2]) + map[n][1];
                dp[n][k][1] = max(dp[n - 1][k - 1][1], dp[n - 1][k - 1][2]) + map[n][0];
            }
            if (n != k)
                dp[n][k][2] = max(dp[n - 1][k][0], max( dp[n - 1][k][1], dp[n - 1][k][2])) + map[n][0] + map[n][1];
        }
    }
    cout<< max(dp[N][K][0], max( dp[N][K][1], dp[N][K][2]));
    return 0;
}
