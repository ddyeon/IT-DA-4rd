#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int n, answer, getMax, tmp;
vector<int> v;

int main(void) {
	cin >> n;
	int k = 0;

	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
	}
	for (int i = 1; i < n; i++) {
		if (v[i] < v[i - 1]) {
			tmp = 0;
			for (int j = 0; j < i - 1; j++) {
				if (v[j] < v[i - 1])tmp++;
			}
			if (tmp > getMax)getMax = tmp;
		}
	}
	if (v[n - 1] > v[n - 2]) {
		tmp = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] < v[n - 1])tmp++;
		}
		if (tmp > getMax)getMax = tmp;
	}
	cout << getMax;
}