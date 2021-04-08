#include<iostream>
#include <queue>
#include <string.h>
using namespace std;
char map[21][21];
int direct[4][2] = { 1,0,0,1,-1,0,0,-1 };
int visit[21][21][21][21];
int N, M, ans, y11, y22, x11, x22;
bool flag = true;
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
queue<int> cnt;
bool bfs() {
	while (!q1.empty()) {
		int y1 = q1.front().first;
		int x1 = q1.front().second;
		int y2 = q2.front().first;
		int x2 = q2.front().second;
		int cc = cnt.front();
		q1.pop();q2.pop();cnt.pop();
		if (cc >= 10)return false;
		for (int i = 0; i < 4; i++) {
			int ny1 = y1 + direct[i][0];
			int nx1 = x1 + direct[i][1];
			int ny2 = y2 + direct[i][0];
			int nx2 = x2 + direct[i][1];
			if ((ny1 > N - 1 || ny1 < 0 || nx1<0 || nx1>M - 1) && (ny2 > N - 1 || ny2 < 0 || nx2<0 || nx2>M - 1)) continue;
			if((ny1 > N - 1 || ny1 < 0 || nx1<0 || nx1>M - 1)&&(ny2 <= N - 1 || ny2 >= 0 || nx2>=0 || nx2<=M - 1)) { ans = cc + 1; return true; }
			if ((ny1 <= N - 1 || ny1 >= 0 || nx1>=0 || nx1<=M - 1) && (ny2 > N - 1 || ny2 < 0 || nx2 < 0 || nx2 > M - 1)) { ans = cc + 1; return true; }
			if (visit[ny1][nx1][ny2][nx2] == 1)continue;
			if (map[ny2][nx2] == '#' && map[ny1][nx1] == '#')continue;
			if (map[ny1][nx1] == '#' && map[ny2][nx2] != '#') {
				visit[y1][y2][ny2][nx2] = 1;
				q1.push(make_pair(y1, x1));
				q2.push(make_pair(ny2, nx2));
				cnt.push(cc + 1);
			}
			else if (map[ny2][nx2] == '#' && map[ny1][nx1] != '#') {
				visit[ny1][nx1][y2][x2] = 1;
				q1.push(make_pair(ny1, nx1));
				q2.push(make_pair(y2, x2));
				cnt.push(cc + 1);

			}
			else {
				visit[ny1][nx1][ny2][nx2] = 1;
				q1.push(make_pair(ny1, nx1));
				q2.push(make_pair(ny2, nx2));
				cnt.push(cc + 1);
			}
			
		}
	}
	return false;
}
int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (flag && map[i][j] == 'o') { y11 = i; x11 = j; flag = false; }
			if (!flag && map[i][j] == 'o') { y22 = i; x22 = j; }
		}
	}
	q1.push(make_pair(y11, x11));
	q2.push(make_pair(y22, x22));
	cnt.push(0);
	if (bfs()) cout << ans;
	else cout << -1;
}
