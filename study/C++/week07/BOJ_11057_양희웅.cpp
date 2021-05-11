#include <iostream>

using namespace std;

int N;
int memo[1010][10] {};
int ans;

void solve(void)
{
    cin >> N;
    for (int i = 0; i < 10; i++) {
        memo[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                memo[i][j] += memo[i - 1][k];
                memo[i][j] %= 10007;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        ans += memo[N][i];
    }
    cout << ans % 10007 << endl;
}

int main(void)
{
    solve();

    return 0;
}