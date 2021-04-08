#include <iostream>
#include <algorithm>
using namespace std;
int hyun[251][251];
int movex[8] = { 1,-1,0,0,1,1,-1,-1 };
int movey[8] = { 0,0,1,-1,1,-1,1,-1 };
bool visited[251][251];
int M, N;
int anw = 0;
void dfs(int a, int b) {
	int newa, newb;
	for (int i = 0; i < 8; i++) {
		newa = a + movex[i];
		newb = b + movey[i];
		if ((newa >= 0) && (newa < M) && (newb >= 0) && (newb < N) && (visited[newa][newb] == false) && (hyun[newa][newb] == 1)) {
			visited[newa][newb] = true;
			dfs(newa, newb);
		}
	}
}
int main()
{
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> hyun[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if ((hyun[i][j] == 1) && (visited[i][j] == false)) {
				visited[i][j] = true;
				dfs(i, j);
				anw++;
			}
			
		}
	}
    cout << anw;
}
