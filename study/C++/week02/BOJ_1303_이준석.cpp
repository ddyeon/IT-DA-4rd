#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
char arr[102][102];
int col[102][102] = { 0 };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
	int M, N, cnt = 0, result1 = 0, result2 = 0;
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (col[i][j] == 1)
				continue;
			else if (col[i][j] == 0) {
				queue <pair<int, int>>q;
				q.push(make_pair(i, j));
				col[i][j] = 1;
				cnt++;
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						if (arr[x + dx[k]][y + dy[k]] == arr[x][y] && col[x + dx[k]][y + dy[k]] == 0)
						{
							q.push(make_pair(x + dx[k], y + dy[k]));
							col[x + dx[k]][y + dy[k]] = 1;
							cnt++;
						}
					}
				}
				if (arr[i][j] == 'W')
					result1 += cnt * cnt;
				else if (arr[i][j] == 'B')
					result2 += cnt * cnt;
				cnt = 0;
			}
		}
	}
	cout << result1 << ' ' << result2;
}