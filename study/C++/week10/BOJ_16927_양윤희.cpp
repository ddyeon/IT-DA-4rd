#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
int N, M, R;
long long arr[301][301];
int tmp;
vector<long long> res[300];

int main(void) {
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int r = 0; r < N / 2; r++) {

		for (int i = r; i < M - r; i++) {
			res[r].push_back(arr[r][i]);
		}
		for (int i = r + 1; i < N - r; i++) {
			res[r].push_back(arr[i][M - r - 1]);
		}
		for (int i = M - r - 2; i >= r; i--) {
			res[r].push_back(arr[N - r - 1][i]);
		}
		for (int i = N - r - 2; i > r; i--) {
			res[r].push_back(arr[i][r]);
		}
	}

	for (int r = 0; r < N / 2; r++) {
		for (int i = 0; i < R; i++) {
			res[r].push_back(res[r][0]);
			res[r].erase(res[r].begin());
		}
	}
	for (int r = 0; r < N / 2; r++) {
		int cnt = 0;
		for (int i = r; i < M - r; i++) {
			arr[r][i] = res[r][cnt++];
		}
		for (int i = r + 1; i < N - r; i++) {
			arr[i][M - r - 1] = res[r][cnt++];
		}
		for (int i = M - r - 2; i >= r; i--) {
			arr[N - r - 1][i] = res[r][cnt++];
		}
		for (int i = N - r - 2; i > r; i--) {
			arr[i][r] = res[r][cnt++];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}