#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//11985 오렌지 출하
/* 비용은 k+sx(a-b) a는 가장 큰 오렌지 크기,
b는 상자에 넣은 가장 작은 오렌지크기, s는 개수
k는 상자를 포장하는 비용 */
int n, m, k;
long long arr[20001];
long long dp[20001];
int main()
{
    cin >> n >> m >> k; //오렌지개수, 최대개수,포장비용

    for (long long i = 1; i <=n; i++)
    {
        cin >> arr[i];
        dp[i] = k * i; //1개만 사용하는 경우
    }

    long long min_value = 0;
    long long max_value = 0;
    for (long long i = 0; i < n; i++)
    {
        min_value = arr[i+1];
        max_value = arr[i+1];

        for (long long j = 1; j <=m && i + j <=n; j++)
        {
            min_value = min(min_value, arr[i + j]);
            max_value = max(max_value, arr[i + j]);

            dp[i + j] = min(dp[i + j], dp[i] + k + j * (max_value - min_value));
        }
    }
    cout << dp[n] << endl;
}
