#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//2011 ��ȣ�ڵ�
//���ڸ� or ���ڸ��� ���� �� ����.
string s;
int arr[5001];
int dp[5001];

int main()
{
    cin >> s;


    if(s[0] == '0')
    {
        cout << 0;
        return 0;
    }
    dp[0]= dp[1] = 1;

    for(int i = 2; i <= s.size(); i++)
    {
        char a = s[i-1];
        //cout << a << endl;
        char b = s[i-2];
        //cout << b << endl;

        if(a == '0' && b == '0')
        {
            cout << 0 << endl;
            return 0;
        }
        if( a != '0')
            dp[i] += dp[i-1]; //���ڸ� ���� ����
        if( b != '0')
        {
            int num = (b-'0')*10 + (a - '0');
            if(num <=26)
                dp[i] += dp[i-2];

        }
        dp[i] %= 1000000;
    }

    cout << dp[s.size()];
    return 0;



}