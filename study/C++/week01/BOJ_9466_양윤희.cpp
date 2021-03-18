#include <iostream>
#include <vector>
using namespace std;
int T, n, tmp, buf, sum;
vector<int> arr;
bool flag = false;
void circ(int level, int val, int first) {
	if (level >=n - 1) return;
	if (arr[val] == val) return;
	if (arr[val] == first) {
		arr[val] = 0;
		flag = true;
		return;
	}
	circ(level+1, arr[val], first);
	if (flag == true) arr[val] = 0;
}
int main(void) {
	cin >> T;
	buf = T;
	while (T-- > 0) {
		sum = 0;
		cin >> n;
		arr.push_back(0);
		for (int i = 1; i <= n; i++) {
			cin >> tmp;
			arr.push_back(tmp);
		}
		for (int i = 1; i <= n; i++) {
			flag = false;
			if (arr[i] == i || arr[i]==0) {
				sum++;
			}
			else {
				circ(0, i, i);
				if (flag == true) sum++;
			}
		}
		cout<< n - sum << endl ;
		while (arr.size() != 0) { arr.pop_back(); }
	}
}