#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
/*
 I V X  L   C   D  M
 1 5 10 50 100 500 1000
 V L D는 한번만 사용가능 
 I X C M은 연속해서 3번까지 사용 가능
 같은 숫자가 반복되면 그 값은 모든 숫자의 값을 더한 값이 된다. 
 IV = 4, IX = 9, XL = 40, XC = 90, CD = 400, CM = 900 - 각각 한번씩 그리고 같이 못씀
 얘네한테 큰숫자는 왼쪽에 있을 수 있으나 작은 숫자는 X

 DLIII = 553
 MCMXL = 1940
 2493 = MMCDXCIII
*/
string one, two, dap;
bool IV, IX, XL, XC, CD, CM;
int res;
int calc(string one, int ans){
	for (int i = 0; i < one.size(); i++) {
		string tmp = one.substr(i, 2);
		if (tmp == "IV" || tmp == "IX" || tmp == "XL"  || tmp == "XC" || tmp == "CD" || tmp == "CM") {
			if (tmp == "IV")ans += 4;
			else if (tmp == "IX")ans += 9;
			else if (tmp == "XL")ans += 40;
			else if (tmp == "XC")ans += 90;
			else if (tmp == "CD")ans += 400;
			else if (tmp == "CM")ans += 900;
			i++;
		}
		else {
			if (one[i] == 'M') {
				ans += 1000;
			}
			else if (one[i] == 'D') {
				ans += 500;
			}
			else if (one[i] == 'C') {
				ans += 100;
			}
			else if (one[i] == 'L') {
				ans += 50;
			}
			else if (one[i] == 'X') {
				ans += 10;
			}
			else if (one[i] == 'V') {
				ans += 5;
			}
			else {
				ans++;
			}
		}
	}
	return ans;
	
}
int main(void) {
	cin >> one >> two;
	res = calc(one,0) + calc(two,0);
	cout << res<<endl;
	if (res >= 1000) {
		for (int i = 0; i < res / 1000; i++) {
			dap += "M";
		}
		res -= (res / 1000) * 1000;
	}
	if (res >= 900) {
		dap += "CM";
		res -= 900;
	}
	if (res >= 500) {
		dap += "D";
		res -= 500;
	}
	if (res >= 400) {
		dap += "CD";
		res -= 400;
	}
	if (res < 400 && res>=100) {
		for (int i = 0; i < res / 100; i++) {
			dap += "C";
		}
		res -= (res / 100) * 100;
	}
	if (res >= 90) {
		dap += "XC";
		res -= 90;
	}
	if (res >= 50) {
		dap += "L";
		res -= 50;
	}
	if (res >= 40) {
		dap += "XL";
		res -= 40;
	}
	if (res < 40 && res>=10) {
		for (int i = 0; i < res / 10; i++) {
			dap += "X";
		}	
		res -= (res / 10) * 10;

	}
	if (res >= 9) {
		dap += IX;
		res -= 9;
	}
	if (res >= 5) {
		dap += "V";
		res -= 5;
	}
	if (res >= 4) {
		dap += "IV";
		res -= 4;
	}
	if (res < 4 && res >= 1) {
		for (int i = 0; i < res; i++) {
			dap += "I";
		}
	}
	cout << dap;
}
