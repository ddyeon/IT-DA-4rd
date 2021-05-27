#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
/*
	m*m 격자 형태의 벌집
	매일 정오에 자람
	첫날 아침 크기는 1 --> N일 동안 반복

	+0 +1 +2 중에 자람 

	1. 제일 왼쪽 열과 제일 위쪽 행의 애벌레들은 자신의 속도 결정
	2. 왼, 왼위, 위 중 가장 많이 자란 만큼 자신도 자란다.

	//입력 m 맵 크기 n 날짜 수
	//자라는 형식이 나옴 왼아래 -> 왼위 ->오른 방향 순

*/
int map[701][701], tmp[701];
int m, n, getMax, index;
int dat[3];
int main(void) {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> dat[0] >> dat[1] >> dat[2];
		index = dat[0];
		for (int j = 0; j < dat[1]; j++, index++) {
			tmp[index]++;
		}
		for (int j = 0; j < dat[2]; j++, index++) {
			tmp[index]+=2;
		}
	}
	index = 0;
	for (int i = m - 1;i > 0; i--, index++) {
		map[i][0] = tmp[index];
	}
	for (int i = 0; i < m; i++, index++) {
		map[0][i] = tmp[index];
	}
	for (int y = 1; y < m; y++) {
		for (int x = 1; x < m; x++) {
			getMax = max(map[y-1][x], map[y-1][x - 1]);
			getMax = max(map[y][x - 1], getMax);
			map[y][x] = getMax;
		}
	}
	

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] + 1 << " ";
		}
		cout << endl;
	}
}