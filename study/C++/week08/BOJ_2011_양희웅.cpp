#include <iostream>
#include <cstring>

using namespace std;

/*
    memo[n] = memo[n-1] + memo[n]
    memo[n] = memo[n-2] + memo[n]
*/

char inputstr[5010] {};
int pw[5010] {};
int memo[5010] {};
int len;

void solve(void)
{
    int tmp;

    if (pw[0] == 0) {
        cout << 0 << endl;
        return;
    }

    memo[0] = 1;

    if (pw[0] >= 1 && pw[0] <= 9) {
        memo[1] = memo[1] + memo[0];
    }
    for (int i = 2; i < len; i++) {
        if (pw[i] >= 1 && pw[i] <= 9) {
            memo[i] = (memo[i - 1] + memo[i]) % 10000000;
        }
        tmp = pw[i - 1] * 10 + pw[i];
        if (tmp >= 10 && tmp <= 26) {
            memo[i] = (memo[i - 2] + memo[i]) % 10000000;
        }
    }

    cout << memo[len - 1] << endl;
}

void input(void)
{
    cin >> inputstr;
    len = strlen(inputstr);
    for (int i = 1; i <= len; i++) {
        pw[i] = inputstr[i - 1] - '0';
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}