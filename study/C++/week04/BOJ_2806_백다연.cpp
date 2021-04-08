#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
int n;
string s;
int dp[2][1000000];
//dp[0]은 a / db[1] b

//참고
//현재까지 상태가 전부 a거나 전부b여야 한다.

int main()
{
    cin >> n;
    cin >> s;


    //BBABB

    for (int i = 0; i < n; i++)
        dp[0][i] = dp[1][i] = (int)1e9; //최대값 넣어주고

    if (s[0] == 'A') 
        dp[0][0] = 0, dp[1][0] = 1; //a인경우 0, b로 바꾼경우 +1

    else
        dp[0][0] = 1, dp[1][0] = 0;




    //한칸식 이동하면서 a가 될 수있는 조건을 만들어야함.
    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'A')
        {
            //현재문자가 a이고 a로 만드는 경우
            dp[0][i] = min(dp[0][i - 1], dp[1][i - 1] + 1); //그전까지 a였으면 그대로, 그 전까지 b였으면 전부뒤집어야함
            //현재 문자가 a이고 b로 만드는 경우
            dp[1][i] = min(dp[0][i - 1] + 1, dp[1][i - 1] + 1); //그전까지 a였으면 전부 뒤집어줘야함, 그 전까지 b였고 현재문자 b로 하는경우 + 1
        }
        else
        {  //현재문자가 b이고 a로 만드는 경우
            dp[0][i] = min(dp[0][i - 1] + 1, dp[1][i - 1] + 1);  //그전까지 a였으면 현재문자 +1, 그전이 b였으면 전부 뒤집어야함
            //현재문자가 b이고 b로 만드는 경우
            dp[1][i] = min(dp[0][i - 1] + 1, dp[1][i - 1]); //그전이 a였으면 무조건 +1, 그전이 전부 b였으면 그대로
        }
    }
    cout << dp[0][n - 1];
    return 0;
}
