#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
char arr[101][101];
char tmp[101][101];
int visited[101][101];
int dx[10] = { 0,1,1,1,0,0,0,-1,-1,-1 };
int dy[10] = { 0,-1,0,1,-1,0,1,-1,0,1 };
int main() {
	int N, M;
	cin >> N >> M;
	int xi=0, yi=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			tmp[i][j] = arr[i][j];
			if (arr[i][j] == 'I') {
				xi = i;
				yi = j;
			}
		}
	}
	string dir;
	cin >> dir;

	for (int k = 0; k < dir.size(); k++) {
		// 주인공 말 움직이기
		tmp[xi][yi] = '.';
		xi = xi + dx[dir[k] - '0'];
		yi = yi + dy[dir[k] - '0'];
		if (tmp[xi][yi] == 'R') {
			cout << "kraj " << k + 1;
			return 0;
		}
		else
			tmp[xi][yi] = 'I'; 
		// 미친말 움직이기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 'R') {
					if (visited[i][j] == 0)
						tmp[i][j] = '.';
					else if (visited[i][j] == 1)
						tmp[i][j] = 'R';
					else if (visited[i][j] > 1)
						tmp[i][j] = '.';
					int x = i, y = j;

					if (xi == i) {
						if (yi < j) {
							x = x + dx[4];
							y = y + dy[4];
						}
						else {
							x = x + dx[6];
							y = y + dy[6];
						}
					}

					else if (yi == j) {
						if (xi < i) {
							x = x + dx[8];
							y = y + dy[8];
						}
						else {
							x = x + dx[2];
							y = y + dy[2];
						}
					}

					else {
						if (xi < i && yi < j) {
							x = x + dx[7];
							y = y + dy[7];
						}
						else if (xi > i && yi > j) {
							x = x + dx[3];
							y = y + dy[3];
						}
						else if (xi > i && yi < j) {
							x = x + dx[1];
							y = y + dy[1];
						}
						else if (xi<i && yi>j) {
							x = x + dx[9];
							y = y + dy[9];
						}
					}
				
					if (tmp[x][y] == 'I') {
						cout << "kraj " << k + 1;
						return 0;
					}
					else {
						if (tmp[x][y] == '.' && visited[x][y] == 0) {
							tmp[x][y] = 'R';
							visited[x][y]++;
						}
						else if (tmp[x][y] == 'R' && visited[x][y] == 0)
							visited[x][y]++;
						else if (visited[x][y] > 0) {
							tmp[x][y] = '.';
							visited[x][y]++;
						}
					}
				}
			}
		}
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				arr[i][j] = tmp[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << arr[i][j];
		cout << endl;
	}
	
}