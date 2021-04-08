#include<iostream>
#include <queue>
#include <vector>
using namespace std;
int N, s, t, visit[250001], i5, i3e, NN;
long long int w, maxi;
struct Node {
	int t;
	long long int s;
};
Node arr[250001], arr2[250001];
bool operator<(Node n, Node m) {
	if (n.t < m.t)return true;
	if (n.t == m.t) {
		return n.s < m.s;
	}
	else return false;
}
void run(int sum, int level) {
	if (level > w)return;
	if (level == w - 1 || level == w || level == w - 2) {
		if (sum > maxi)maxi = sum;
		return;
	}
	for (int i = N - 1;i >= 0; i--) {
		if (visit[i] == 1)continue;
		if (arr[i].t + level > w)continue;
		visit[i] = 1;
		run(sum + arr[i].s, level + arr[i].t);
	}
}
int main(void) {
	cin >> N >> w;
	for (int i = 0; i < N; i++) {
		cin >> t >> s;
		arr[i] = { t,s };
	}
	int i3 = 0;
	for (i3 = 0; i3 < N; i3++) {
		if (arr[i3].t != 3)break;
	}
	i3e = w / 3;
	i5 = w / 5;
	int j = 0;
	for (int i = 0; i < i3 - i3e; i++) {
		visit[i] = 1;
	}

	for (int i = i3; i < N - i5; i++) {
		visit[i] = 1;
	}
	int sum = 0, level = 0;
	if (arr[i3 - 1].s < arr[N - 1].s) {
		sum = arr[N - 1].s;
		level = 5;
		visit[N - 1] = 1;
	}
	else {
		sum = arr[i3 - 1].s;
		level = 3;
		visit[i3 - 1] = 1;
	}
	run(sum, level);
	cout << maxi;
}