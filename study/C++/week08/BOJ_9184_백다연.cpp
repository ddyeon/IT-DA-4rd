#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//9184 신나는 함수 실행
int dp[21][21][21]; //어차피 값커도 20으로 조정

int w(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if( a > 20 || b > 20 || c > 20)
        return w(20,20,20);
    else if(a<b && b < c)
    {
        if(dp[a][b][c] != 0)
            return dp[a][b][c];
        else
            return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else
    {
        if(dp[a][b][c] != 0) 
            return dp[a][b][c];
        else
            return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
           
}

int main()
{
    int a,b,c;
    while(true)
    {
        cin >> a >> b >> c;
        if(a== -1 && b == -1 && c == -1)
            break;

        cout << "w(" << a <<"," << b <<"," << c << ") = " << w(a,b,c) << endl; 
    }


    return 0;
}