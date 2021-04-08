#include<iostream>
#include <queue>
#include <vector>
using namespace std;
int n, arr[1001], maxi, maxIdx, sum;
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > maxi) {
			maxi = arr[i];
			maxIdx = i;
		}
	}
	for (int i = maxIdx + 1; i < n; i++) {
		sum += maxi + arr[i];
	}
	for (int i = maxIdx - 1; i >= 0; i--) {
		sum += maxi + arr[i];
	}
	cout << sum;
}