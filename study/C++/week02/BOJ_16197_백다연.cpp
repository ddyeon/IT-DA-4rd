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
//두동전은 같은 방향으로 이동

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int n, m;
vector<pair<int, int>> v; //동전의 위치 저장
char s[21][21];

int dfs(int x1, int y1, int x2, int y2, int cnt)
{
    bool coin1 = false;
    bool coin2 = false;
    int ans = -1;

    if (cnt > 10)
        return -1;                              //10번이상인경우
    if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) //coin1 떨어진경우
        coin1 = true;
    if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) //coin2 떨어진경우
        coin2 = true;

    if (coin1 && coin2)
        return -1; //둘다 떨어진경우
    if (coin1 || coin2)
        return cnt;

    for (int i = 0; i < 4; i++)
    {
        int nx1 = x1 + dx[i];
        int ny1 = y1 + dy[i];
        int nx2 = x2 + dx[i];
        int ny2 = y2 + dy[i];

        if (0 <= nx1 && nx1 < n && 0 <= ny1 && ny1 < m && s[nx1][ny1] == '#')
        {
            nx1 = x1;
            ny1 = y1;
        }
        if (0 <= nx2 && nx2 < n && 0 <= ny2 && ny2 < m && s[nx2][ny2] == '#')
        {
            nx2 = x2;
            ny2 = y2;
        }

        int next = dfs(nx1, ny1, nx2, ny2, cnt + 1);

        if (next == -1)
            continue;
        if (ans == -1 || ans > next)
            ans = next;
    }
    return ans;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'o') //동전이라면
            {
                v.push_back(make_pair(i, j));
            }
        }
    }

    int coin1x = v[0].first;
    int coin1y = v[0].second;
    int coin2x = v[1].first;
    int coin2y = v[1].second;

    int result = 0;
    result = dfs(coin1x, coin1y, coin2x, coin2y, 0);

    cout << result << endl;
}