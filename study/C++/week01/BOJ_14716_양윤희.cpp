#include<iostream>
#include<queue>
using namespace std;
int map[251][251], visit[251][251], N, M, cnt;
int direct[8][2] = { -1,-1,-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1 };
queue<pair<int,int>> q;
void bfs(int y, int x) {
	q.push(make_pair(y, x));
	visit[y][x] = 1;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		int yy = p.first;
		int xx = p.second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int ny = yy + direct[i][0];
			int nx = xx + direct[i][1];
			if (ny < 0 || ny> N - 1 || nx<0 || nx>M - 1 || map[ny][nx] == 0 || visit[ny][nx] == 1)continue;
			visit[ny][nx] = 1;
			q.push(make_pair(ny, nx));
		}
	}
}
int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
}