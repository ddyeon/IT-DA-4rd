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
char arr[101][101];
int visit[101][101];
int n,m = 0;
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};

/*
int dfs(int x, int y, int num)
{
    int cnt = num;
    visit[x][y] = true;
    char team = arr[x][y]; //ÇöÀç Å½»öÇÏ°í ÀÖ´Â ÆÀ

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        if(!visit[nx][ny] && arr[nx][ny] == team)
        {
            visit[nx][ny] = true;
            cnt++;
            dfs(nx, ny, cnt);
        }
     
    }

    return cnt * cnt;
}*/

int bfs(int x, int y)
{
    int cnt = 1;
    char team = arr[x][y];
    visit[x][y] = true;
    queue <pair<int,int>> q;

    q.push(make_pair(x,y));

    while(!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if (!visit[nx][ny] && arr[nx][ny] == team)
            {
                visit[nx][ny] = true;
                cnt++;
                q.push(make_pair(nx,ny));
            }
        }
    }

    return cnt * cnt;
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }

    int white_score = 0;
    int blue_score = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if(!visit[i][j] && arr[i][j] == 'W')
                white_score += bfs(i, j); //dfs(i,j,1);
            else if (!visit[i][j] && arr[i][j] == 'B')
                blue_score += bfs(i,j); //dfs(i,j,1);
        }

    cout << white_score << " " << blue_score << endl;

    return 0;
}
