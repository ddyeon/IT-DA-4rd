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

//소수부분문자열
//https://www.acmicpc.net/problem/5636
//가장큰 소수를 찾는것
///50프로에서 틀림ㅠ
bool visit[100005];


int main()
{

    //소수먼저 체크
    for (int i = 2; i * i <= 1e5; i++)
    {
        if (visit[i])
            continue;

        for (int j = i * 2; j <= 1e5; j += i) //각배수들체크
            visit[j] = true;
    }

    string s;
    while (cin >> s)
    {
        if(s[0] == '0' && s.size() == 1)
            break;

        int n = s.length();

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                int num = stoi(s.substr(i, j));
                //cout << num << endl;
                if (visit[num]) //소수인지 체크
                {
                    ans = max(ans, num);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}