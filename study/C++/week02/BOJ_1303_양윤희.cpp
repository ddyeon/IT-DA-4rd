#include<iostream>
#include <queue>
#include <string.h>
using namespace std;
int N, M;
char map[101][101];
int visit[101][101], white, blue;
int direct[4][2] = { 1,0,0,1,-1,0,0,-1 };
queue<pair<int, int>> q;
queue<int> cnt;
int bfs(int y, int x) {
	int maxi = 1;
	q.push(make_pair(y, x));

	visit[y][x] = 1;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0;i < 4; i++) {
			int ny = yy + direct[i][0];
			int nx = xx + direct[i][1];
			if (ny<0 || ny>N - 1 || nx<0 || nx>M - 1 || map[ny][nx] != map[y][x] || visit[ny][nx] == 1)continue;
			visit[ny][nx] = 1;
			q.push(make_pair(ny, nx));
			maxi++;
		}
	}
	return maxi * maxi;
}
int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0;j < M; j++) {
			if (map[i][j] == 'W' && visit[i][j] == 0) white += bfs(i,j);
			if (map[i][j] == 'B' && visit[i][j] == 0) blue += bfs(i, j);
		}
	}
	cout << white << " " << blue;
}
