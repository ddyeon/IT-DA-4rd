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

int dx[2] = { -1, 1};
int n,m,s,e;
vector <int> v[3000000];
int visit[300000];
int arr[300000];
int cnt = 0;

int bfs(int start)
{
    visit[start] = true;
    queue <pair<int,int>> q;
    q.push(make_pair(start, cnt)); //현재위치랑cnt

    while (!q.empty())
    {
    
        int current = q.front().first;
        int time = q.front().second;

        if(current == e) {
            int result = time;
            return result;
        }

        if(current + 1 <= n && !visit[current+1])
        {
            visit[current+1] = true;
            q.push(make_pair(current+1, time+1));
        }
        if(current -1 > 0 && !visit[current-1])
        {
            visit[current-1] = true;
            q.push(make_pair(current-1, time+1));
        }
        if(v[current].size() > 0)
        {
            for(int i = 0; i < v[current].size(); i++)
            {
                if(!visit[v[current][i]])
                {
                    visit[v[current][i]] = true;
                    q.push(make_pair(v[current][i], time+1));
                }
            }
        }


    }
    
   
}


int main()
{
    cin >> n >>m; 
    cin >> s >> e; //주예랑 방주 위치

    for(int i = 0; i < m; i++) //텔레포트
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }


    int ans = 0;

    ans = bfs(s); // 주예의 위치

    cout << ans << endl;

    return 0;


    

}