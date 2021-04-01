#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	int N, result = 0, s = 0, e = 0;
	cin >> N;
	vector<pair<int, int>> vec;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		vec.push_back(make_pair(a, b));
	}
	s = vec[0].first;
	e = vec[0].second;
	if (N == 1)
		cout << e - s;
	else {
		for (int i = 0; i < vec.size() - 1; i++) {
			if (e >= vec[i + 1].first) {
				if (i == vec.size() - 2) {
					e = max(vec[i + 1].second, e);
					result = result + e - s;
				}
				else {
					e = max(vec[i + 1].second, e);
				}
			}
			else {
				if (i == vec.size() - 2) {
					result = result + e - s;
					result = result + vec[vec.size() - 1].second - vec[vec.size() - 1].first;
				}
				else {
					result = result + e - s;
					s = vec[i + 1].first;
					e = vec[i + 1].second;
				}
			}
		}
		cout << result;
	}
}