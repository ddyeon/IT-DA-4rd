#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>ans;
int ss(string str, int i, int j, int cnt) {
	while(i<j) {
		if (str[i] == str[j]) {
			i++; 
			j--;
		}
		else
			return -1;
	}
		return cnt;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		string str;
		int cnt = 0;
		cin >> str;
		int i = 0, j = str.size() - 1;
		while(i<j) {
			if (str[i] == str[j]) {
				i++, j--;
			}
			else
			{
				if ((str[i] == str[j - 1]) && (str[i + 1] == str[j])) {
					cnt++;
					cnt = max(ss(str, i + 1,j, cnt), ss(str,i, j - 1, cnt));
					break;
				} // 
				else if (str[i] == str[j - 1] && (str[i + 1] != str[j])) {
					i++; 
					j-=2;
					cnt++;
				}
				else if (str[i + 1] == str[j] && str[i] != str[j - 1]) {
					i += 2; 
					j--;
					cnt++;
				}
					
				else {
					cnt = -1;
					break;
				} // 
			}
		}
		if (cnt == -1 || cnt > 1)
			ans.push_back(2);
		else if (cnt == 1)
			ans.push_back(1);
		else if (cnt == 0)
			ans.push_back(0);
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
}