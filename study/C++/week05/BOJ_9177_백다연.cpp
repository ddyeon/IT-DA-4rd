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
//9177 단어섞기
bool visit[201][201];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        string a, b, c;
        cin >> a >> b >> c;

        memset(visit, 0, sizeof(visit));

        int alength = a.size();
        int blength = b.size();
        int clength = c.size();

        if(alength + blength != clength)
        {
            cout << "Data set " << i << ": no\n";
            continue;
        }

        bool check = false;
        queue<pair<int,int>> q;
        q.push({0,0});
        visit[0][0] = true;
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            int k = i+j;
            q.pop();

            if(i== alength && j ==blength && k == clength)
            {
                check = true;
                break;
            }
            //해당언어가 사용됐는지 확인
            if (i != alength && a[i] == c[k] && !visit[i + 1][j])
            {
                visit[i+j][j] = true;
                q.push({i+1,j});
            }
            if( j != blength && b[j] == c[k] && !visit[i][j+1])
            {
                visit[i][j+1] = true;
                q.push({i,j+1});
            }
        }

        cout << "Data set " << i << ":" << (check?"yes":"no") << "\n";
        

    }
    return 0;
}
