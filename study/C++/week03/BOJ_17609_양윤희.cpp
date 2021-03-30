#include<iostream>
#include <queue>
#include <vector>
using namespace std;
int T, ans;
string i, o;

int check(int x, int y) {

	string tmp = i.substr(0, x);
	tmp += i.substr(x + 1, i.length());
	int yy = tmp.length() - 1;
	for (x = 0; x < tmp.length() / 2; x++, yy--) {
		if (tmp[x] != tmp[yy]) {
			break;
		}
		if (x == (tmp.length() / 2) - 1)return 1;
	}
	tmp = i.substr(0, y);
	tmp += i.substr(y + 1, i.length());
	yy = tmp.length() - 1;
	for (x = 0; x < tmp.length() / 2; x++, yy--) {
		if (tmp[x] != tmp[yy]) {
			return 2;
		}
	}
	return 1;
}
int main(void) {
	cin >> T;
	while (T-- > 0) {
		cin >> i;

		int y = i.length() - 1;
		for (int x = 0; x < i.length()/2; x++, y--) {
			if (i[x] != i[y]) {
				ans = check(x, y);
				break;
				
			}
			ans = 0 ;
		}
		cout << ans << endl;
	}
}
