#include <iostream>

using namespace std;

int N, M;
int H;
int result;

void solve(void)
{
    if (M <= 0) {
        cout << 0 << endl;
        return;
    }
    int q = M / (N + 1);
    int r = M % (N + 1);
    result = 0;
    int j = 0;
    for (int i = 0; i < N + 1; i++) {
        int val = (j < r) ? q + 1 : q;
        result += val * (val + 1) * (2 * val + 1) / 6;
        j++;
    }
    cout << result << endl;
}

void input(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> H;
        M -= (H + 1);
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}