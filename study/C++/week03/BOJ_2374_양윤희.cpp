#include<iostream>
#include <queue>
#include <vector>
using namespace std;
vector<long long int> v;
int n;
long long int k, sum;
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (v.empty())v.push_back(k);
		else {
			if (k > v.back()) {
				sum += abs(v.back() - k);
				v.pop_back();
				while (!v.empty()) {
					if (v.back() > k)break;
					v.pop_back();
				}
				v.push_back(k);
			}
			else if (k < v.back()) {
				v.push_back(k);
			}
			else if (k == v.back())continue;
		}
	}
	if (!v.empty())sum += v.front() - v.back();
	cout << sum;
}