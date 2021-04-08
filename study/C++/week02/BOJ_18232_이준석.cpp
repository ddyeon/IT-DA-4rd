#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector <int> vec[3000001];
int col[300001] = { 0 };
int main() {
	int N, M, S, E, cnt = 0;
	cin >> N >> M >> S >> E;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	queue <pair<int, int>>q;
	q.push(make_pair(S, 0));
	while (!q.empty())
	{
		int x = q.front().first;
		cnt = q.front().second;
		q.pop();

		if (x == E)
		{
			cout << cnt;
			break;
		}

		if (x - 1 > 0 && col[x - 1] == 0) {
			q.push(make_pair(x - 1, cnt + 1));
			col[x - 1] = 1;
		}
		if (x + 1 <= N && col[x + 1] == 0) {
			q.push(make_pair(x + 1, cnt + 1));
			col[x + 1] = 1;
		}
		if (vec[x].size() != 0) {
			for (int i = 0; i < vec[x].size(); i++) {
				if (col[vec[x][i]] == 0)
				{
					q.push(make_pair(vec[x][i], cnt + 1));
					col[vec[x][i]] = 1;
				}
			}
			
		}
	}
}