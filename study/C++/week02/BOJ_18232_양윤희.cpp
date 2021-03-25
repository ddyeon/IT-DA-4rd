#include<iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, S, E;
//N점 개수, M 텔레포트 연결 개수, S 출발 E 도착
int visit[300001], cnt, minIdx, maxIdx;
vector<int> v[300001];
queue<pair<int, int>>q;
void bfs() {
	while (!q.empty()) {
		int now = q.front().first;
		int c = q.front().second;
		q.pop();
		if (now == E) {
			cnt = c;
			return;
		}
		visit[now] = 1;
		for (int i = 0; i < v[now].size(); i++) {
			if (visit[v[now][i]] == 0) q.push(make_pair(v[now][i], c + 1));
		}
		if (now + 1 <= maxIdx && visit[now + 1] == 0)q.push(make_pair(now + 1, c + 1));
		if (now - 1 > minIdx && visit[now - 1] == 0)q.push(make_pair(now - 1, c + 1));

	}
}
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> S >> E;
	minIdx = S, maxIdx = E;
	for (int i = 0; i < M; i++) {
		int x = 0, y = 0;
		cin >> x >> y;
		if (x < minIdx)minIdx = x;
		if (y > maxIdx)maxIdx = y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	q.push(make_pair(S, 0));
	bfs();
	cout << cnt;
}
