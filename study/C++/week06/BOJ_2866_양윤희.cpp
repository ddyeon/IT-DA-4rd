#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//R*C테이블이 입력으로 들어온다.
//알파벳 소문자로 주어진다. 
int R, C, cnt, mid;
string arr[1001];
string tmp;
vector<string> v[1001];
int search(int s, int e, int index) {
	while (s <= e) {
		
		mid = (s + e) / 2;
		for (int i = 0; i < C; i++) {
			tmp = "";
			for (int j = mid; j < R; j++) {
				tmp += arr[j][i];
			}
			v[index].push_back(tmp);
		}
		sort(v[index].begin(), v[index].end());
		v[index].erase(unique(v[index].begin(), v[index].end()), v[index].end());
		if (v[index].size() != C) {
			e = mid - 1;
			index++;
			cnt = mid - 1;
		}
		else {
			s = mid + 1;
			index++;
			cnt = mid;
		}
	}
	return cnt;
}
int main(void) {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> arr[i];
	}
	cout<< search(0, R-1, 0);
	
}