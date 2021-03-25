#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int arr[100000] = { 0 };
int main() {
	int N, T, G, cnt = 0;
	bool res = true;
	cin >> N >> T >> G;
	queue<pair<int, int>>q;
	q.push(make_pair(N, 0));
	arr[N] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		cnt = q.front().second;
		q.pop();

		if (cnt == T + 1)
			break;

		if (x == G) {
			cout << cnt;
			res = false;
			break;
		}

		if (x * 2 <= 99999 && x > 0)
		{
			int tmp = 2 * x;
			int k = 0;
			while (tmp > 9)
			{
				tmp = tmp / 10;
				k++;
			}
			tmp = 2 * x - (tmp * pow(10, k)) + (tmp - 1) * pow(10, k);
			if (arr[tmp] == 0) {
				q.push(make_pair(tmp, cnt + 1));
				arr[tmp] = 1;
			}
		}//1¹ø
		
		if (x + 1 <= 99999 && arr[x + 1] == 0) {
			q.push(make_pair(x + 1, cnt + 1));
			arr[x + 1] = 1;
		}//2¹ø

	}

	if (res)
		cout << "ANG";
}