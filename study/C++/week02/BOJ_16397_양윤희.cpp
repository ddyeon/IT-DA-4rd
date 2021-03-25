#include<iostream>
#include <queue>
#include <string>
using namespace std;
//A-->N+1 B-->N*2-->가장 높은 자리수 숫자 1 줄어들기
string N, G;
int T, ans, visit[100000];
bool flag = true;
queue<string>q;
queue<int> lev;
string B(string c) {
	int x = stoi(c);
	x *= 2;
	c = to_string(x);
	int t = (c[0]-'0') - 1;
	c[0] = '0' + t;
	if (c[0] == '0'&& c.length() != 1) c = c.substr(1);
	if (c[0] == '0' && c.length() != 1) c = c.substr(1);
	if (c[0] == '0' && c.length() != 1) c = c.substr(1);
	if (c[0] == '0' && c.length() != 1) c = c.substr(1);
	return c;
}
string A(string c) {
	int x = stoi(c);
	x++;
	c = to_string(x);
	return c;
}
void run(int level, string tmp) {
	q.push(tmp);
	lev.push(level);

	while(!q.empty()){

		string tmp = q.front();
		int check = stoi(tmp);
		int level = lev.front();
		q.pop(); lev.pop();
		if (tmp == G) { flag = true; ans = level; return; }


		if (level > T) {
			flag = false;
			return;
		}
		if (visit[check] == 1) continue;
		visit[check] = 1;

		if (check < 99999) {
			string b = A(tmp);
			q.push(b);
			lev.push(level + 1);
		}

		
		if (check > 0 && check < 50000) {
			string a = B(tmp);	
			q.push(a);
			lev.push(level + 1);
		}
	}
	flag = false;
	return;
}
int main(void) {
	cin >> N >> T >> G;
	run(0, N);
	
	if (flag)cout << ans;
	else cout << "ANG";
}
