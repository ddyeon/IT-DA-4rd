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

//�Ҽ��κй��ڿ�
//https://www.acmicpc.net/problem/5636
//����ū �Ҽ��� ã�°�
///50���ο��� Ʋ����
bool visit[100005];


int main()
{

    //�Ҽ����� üũ
    for (int i = 2; i * i <= 1e5; i++)
    {
        if (visit[i])
            continue;

        for (int j = i * 2; j <= 1e5; j += i) //�������üũ
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
                if (visit[num]) //�Ҽ����� üũ
                {
                    ans = max(ans, num);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}