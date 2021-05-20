#include <iostream>
#include <algorithm>

#define Min(x,y)    ((x)<(y)?(x):(y))
#define Max(x,y)    ((x)>(y)?(x):(y))

using namespace std;

long long N, M, K;
long long orenge[20010] {};
long long price[20010] {};

void solve(void)
{
    long long small, large;

    for (long long i = 1; i <= N; i++) {
        price[i] == 1e15;
        small = orenge[i];
        large = orenge[i];
        for (long long j = i; j >= max(1LL, i - M + 1); j--) {
            small = min(small, orenge[j]);
            large = max(large, orenge[j]);
            price[i] = min(price[i], price[j - 1] + K + (i - j + 1) * (large - small));
        }
        cout << "price[i]: " << price[i] << endl;
    }
    cout << price[N] << endl;
}

void input(void)
{
    cin >> N >> M >> K;
    for (long long i = 1; i <= N; i++) {
        cin >> orenge[i];
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}