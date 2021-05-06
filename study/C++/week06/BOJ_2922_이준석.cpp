#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
vector<long long>vec;
string str, temp;
bool L = false;
int cnt = 0;
long long result = 0;
void cal() {
	long long k = 0;
	long long tmp = 1;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == 1)
			tmp *= 5;
		else if (vec[i] == 2)
			tmp *= 20;
	}
	result += tmp;
}

bool isvalidrange() {
	int L_cnt = 0;
	int k = 0;
	temp = str;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == '_') {
			temp[i] = vec[k] + '0';
			k++;
		}
		if (temp[i] == '3')
			L_cnt++;
	}
	if (L_cnt == 0)
		return false;
	for (int i = 0; i < temp.size() - 2; i++) {
		if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2])
			return false;
		if (temp[i] != '1' && temp[i + 1] != '1' && temp[i + 2] != '1')
			return false;
	}
	return true;
}

void simulate(int n){
	
	if (n == cnt) {
		if (isvalidrange()) {
			cal();
		}
		return;
	}

	for (int i = 1; i <= 3; i++) {
		
		vec.push_back(i);
		simulate(n + 1);
		vec.pop_back();
		
	}
}

int main() {
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '_')
			cnt++;
		else if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
			str[i] = '1';
		else if (str[i] == 'L')
		{
			str[i] = '3';
		}
		else
			str[i] = '2';
	}
	simulate(0);

	cout << result;
}