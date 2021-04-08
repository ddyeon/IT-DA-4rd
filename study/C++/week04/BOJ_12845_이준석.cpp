#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, L, result = 0, mx = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L;
		mx = max(mx, L);
		result += L;
	}
	result += mx * (N - 2);
	cout << result;
}