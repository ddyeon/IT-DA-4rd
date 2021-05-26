#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
string zxcv[5];
int n;
string answer;
int main(void) {
	cin >> n;
	string s;
	cin >> s;
	int index = 0;
	for (int i = 0; i < s.size(); i++) {
		zxcv[index] += s[i];
		if ((i + 1) % (n / 5) == 0)index++;
	}
	int startIndex = 0;
	for (int i = 0; i < n / 5; i++) {
		if ((zxcv[0][i] == '.' && zxcv[2][i] == '.' && zxcv[0][i-1] == '#' ) || (i==(n/5)-1 && zxcv[0][i]=='#')) {
			if (i == (n / 5) - 1) i++;
			if (i==1 || zxcv[0][i-2]=='.' && zxcv[2][i-2]=='.')answer += "1";
			else {
				startIndex = i - 3;
				if (zxcv[4][startIndex + 1] == '#' && zxcv[2][startIndex + 1] == '.')answer += "0";
				else if (zxcv[1][startIndex] == '.' && zxcv[3][startIndex + 2] == '.')answer += "2";
				else if (zxcv[1][startIndex] == '.' && zxcv[2][startIndex] == '#' && zxcv[3][startIndex] == '.')answer += "3";
				else if (zxcv[0][startIndex + 1] == '.')answer += "4";
				else if (zxcv[3][startIndex] == '.' && zxcv[1][startIndex + 2] == '.')answer += "5";
				else if (zxcv[1][startIndex + 2] == '.' && zxcv[3][startIndex] == '#')answer += "6";
				else if (zxcv[2][startIndex + 1] == '.')answer += "7";
				else if (zxcv[0][startIndex] == zxcv[0][startIndex + 2] && zxcv[3][startIndex] == zxcv[3][startIndex + 2])answer += "8";
				else answer += "9";
			}
		}
	}
	cout << answer;
}
