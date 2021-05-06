#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str1, str2, result;

int main() {
	cin >> str1 >> str2;
	int len = str1.size();
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end(), greater<char>());
	int idx1 = 0, idx2 = 0;
	for (int i = 0; i < len; i++) {
		if (i % 2 == 0) {
			result += str1[idx1];
			idx1++;
		}
		else {
			result += str2[idx2];
			idx2++;
		}
	}
	cout << result;
}