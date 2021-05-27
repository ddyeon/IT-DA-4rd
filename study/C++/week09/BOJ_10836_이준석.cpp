#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int tmp[701][701];
int up[1000001][3];
int N, M;

int main() {
	cin >> N >> M;
	vector <int> cnt(2 * N - 1,1);
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> up[i][j];
		}
		for (int j = up[i][0]; j < up[i][0] + up[i][1]; j++)
			cnt[j]++;

		for (int j = up[i][0] + up[i][1]; j < up[i][0] + up[i][1] + up[i][2]; j++)
			cnt[j] += 2;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j == 0)
				cout << cnt[N - 1 - i] << " ";
			else
				cout << cnt[j + N - 1] << " ";
		}
		cout << endl;
	}

}