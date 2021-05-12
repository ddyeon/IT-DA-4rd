#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
//11057 오르막수

using namespace std;
int n;
int dp[1001][10];


int main()
{
    cin >> n;

    int ans = 0;

    for(int i = 0; i < 10; i++) //0-9까지 올 수 있음.
    {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            for(int k = j; k < 10; k++)
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % 10007;
        }
    }

    for(int i = 0; i < 10; i++)
        ans = (ans + dp[n][i]) % 10007;

    
    cout << ans << endl;

    return 0;



}
