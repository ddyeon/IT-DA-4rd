#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
char arr[22][22];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector <int> vec;
int main() {
	fill(arr[0], arr[0] + 484, 'X');
	int N, M, cnt = 0;
	bool res = false;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'o') {
				vec.push_back(i);
				vec.push_back(j);
			}
		}
	}
	queue< pair<pair<int, int>, int>>q1;
	queue< pair<pair<int, int>, int>>q2;
	q1.push(make_pair(make_pair(vec[0], vec[1]), 0));
	q2.push(make_pair(make_pair(vec[2], vec[3]), 0));

	while (!q1.empty()) {
		int x1 = q1.front().first.first;
		int y1 = q1.front().first.second;
		int x2 = q2.front().first.first;
		int y2 = q2.front().first.second;
		cnt = q1.front().second;
		q1.pop();
		q2.pop();

		if (cnt > 10)
			break; // cnt가 10을 넘어간 경우
		if (((x1<1 || x1>N || y1<1 || y1>M) && (x2 >= 1 && x2 <= N && y2 >= 1 && y2 <= M)) || ((x2<1 || x2>N || y2<1 || y2>M) && (x1 >= 1 && x1 <= N && y1 >= 1 && y1 <= M)))
		{
			res = true;
			break;
		} // 둘 중 하나만 떨어진 경우
		if ((x1<1 || x1>N || y1<1 || y1>M) && (x2<1 || x2>N || y2<1 || y2>M))
			continue; // 둘 다 떨어진 경우

		for (int i = 0; i < 4; i++)
		{
			if ((arr[x1 + dx[i]][y1 + dy[i]] == '#') && (arr[x2 + dx[i]][y2 + dy[i]] == '#'))// 둘다 벽
				continue; 
			else if ((arr[x1 + dx[i]][y1 + dy[i]] == '#') && (arr[x2 + dx[i]][y2 + dy[i]] != '#'))// 둘중 하나만 벽
			{
				q1.push(make_pair(make_pair(x1, y1), cnt + 1));
				q2.push(make_pair(make_pair(x2 + dx[i], y2 + dy[i]), cnt + 1));
			}
			else if ((arr[x1 + dx[i]][y1 + dy[i]] != '#') && (arr[x2 + dx[i]][y2 + dy[i]] == '#'))// 둘중 하나만 벽
			{
				q1.push(make_pair(make_pair(x1 + dx[i], y1 + dy[i]), cnt + 1));
				q2.push(make_pair(make_pair(x2, y2), cnt + 1));

			}
			else if ((arr[x1 + dx[i]][y1 + dy[i]] != '#') && (arr[x2 + dx[i]][y2 + dy[i]] != '#'))//둘다 벽이 아님
			{
				q1.push(make_pair(make_pair(x1 + dx[i], y1 + dy[i]), cnt + 1));
				q2.push(make_pair(make_pair(x2 + dx[i], y2 + dy[i]), cnt + 1));
			}
		}
	}
	if (res)
		cout << cnt;
	else
		cout << -1;
}