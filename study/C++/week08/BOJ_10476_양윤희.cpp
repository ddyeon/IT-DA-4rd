#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
/*
N�࿡���� ���� ����� 3���� ��� ���̴�. (�࿭��, �����)
F = 0 : ��� (���ʸ� ����)
F = 1 : ��� (�����ʸ� ����)
F = 2 : ��� (������ ����)

F�� 0�� ��쿡�� N-1���� 0�̳� 2�� F���°� �;��Ѵ�.
F�� 1�� ��쿡�� N-1���� 1�̳� 2�� F���°� �;��Ѵ�.
F�� 2�� ��쿡���� 3���� ���� ��� �����ϴ�.

�̷��� Ʋ�� ��ȭ���� ���� �� �� �ִ�.

DP[N][K][F] : N����� ���� K�� �ݰ� N���� F�� ����϶� ������ ���� ����� ��ġ�� �ִ���

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
