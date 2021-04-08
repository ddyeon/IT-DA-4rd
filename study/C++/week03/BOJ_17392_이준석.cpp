#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int arr[1002] = { 0 };
int main() {
	int N, M, cnt = 0, result = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		cnt = cnt + k + 1;
	}
	if (M - cnt <= 0)
		cout << 0;
	else {
		int x = M - cnt;
		
		int i = 0;
		while (i < x) {
			result = result + (i / (N + 1) + 1) * (i / (N + 1) + 1);
			i++;
		}
		cout << result;
	}
}