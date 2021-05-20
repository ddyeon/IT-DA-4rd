#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//10476 좁은 미술전시관
//가로2, 세로 N, k개의 방을 닫아야함.
//같은줄의 두방을 모두 닫거나 대각선으로 닫으면 안됨.
//가치의 값을 최대로
int n, k;
int arr[201][2];
int dp[201][201][3]; //왼쪽만 닫히는 경우, 오른쪽만 닫히는 경우, 안닫히는 경우
//너무어렵다...
int main()
{
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
        cin >> arr[i][0] >> arr[i][1];
    int a,b;
    cin >> a >> b;

    dp[1][1][0] = arr[1][1]; //왼쪽이 닫힌경우 오른쪽값만 가치 계산
    dp[1][1][1] = arr[1][0]; //오른쪽이 닫힌 경우 왼쪽값만
    dp[1][0][2] = arr[1][1] + arr[1][0]; //둘다 열려있음.

    for(int i=2; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            if(j>=1)
            {
                dp[i][j][0] = max(dp[i-1][j-1][0],dp[i-1][j-1][2]) + arr[i][1];
                dp[i][j][1] = max(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + arr[i][0];
            }
            if( i != j)
                dp[i][j][2] = max(dp[i-1][j][0], max(dp[i-1][j][1], dp[i-1][j][2])) + arr[i][0] + arr[i][1];
        }
    }

    cout << max(dp[n][k][0], max(dp[n][k][1], dp[n][k][2])) << endl;

    return 0;
   
}
