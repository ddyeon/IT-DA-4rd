#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int N, K, L, cnt, tailCnt;
int dummy[101][101]; //���Ӹ�
int visit[101][101]; //�湮ó��
int directY[4] = { 0, -1, 0, 1 }; //����, �Ʒ�, ��, ��
int directX[4] = { 1, 0, -1, 0 };
int mv, times, tailX, tailY;
//���� �� ��Ǯ��,,,,,,,,�ƴ� ������ ���ذ� �ȵ�,,,,,,,,,,,
struct Point {
	int y, x;
};
vector<Point> q;
struct Node {
	int time;
	char dir;
};
vector<Node> v;
void move() {
	mv = 0;
	while (!q.empty()) {
		int ny = q[times].y;
		int nx = q[times].x;

		ny += directY[mv];
		nx += directX[mv];
		if (ny<0 || ny>N - 1 || nx<0 || nx>N - 1 || visit[ny][nx] == 1) { cout << times; break; }
		visit[ny][nx] = 1;
		q.push_back({ ny, nx });
		
		if (dummy[ny][nx] == 0) {
			visit[tailY][tailX] = 0;
			tailCnt++;
			tailY = q[tailCnt].y;
			tailX = q[tailCnt].x;			
		}	

		if (cnt < L) {
			if (times == v[cnt].time){
				if (v[cnt].dir == 'L')
					mv = (mv + 1) % 4;
				else if (v[cnt].dir == 'D')
					mv = (mv + 3) % 4;
				cnt++;
			}
		}
		times++;
	}
}

int main(void) {
	cin >> N >> K;
	int y = 0, x = 0;
	for (int i = 0; i < K; i++) {
		cin >> y >> x;
		dummy[y][x] = 1;
	}
	cin >> L;
	int t = 0; char c = ' ';
	for (int i = 0; i < L; i++) {
		cin >> t >> c; //���� L, ������ D
		v.push_back({ t , c });
	}
	q.push_back({ 0,0 });
	move();
}
