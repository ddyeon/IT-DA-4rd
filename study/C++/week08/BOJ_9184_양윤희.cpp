#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int a, b, c;
int res;
int visit[51][51][51];
int w(int a, int b, int c) {	
	if (visit[a][b][c] != 0) return visit[a][b][c];

	if (a <= 0 || b <= 0 || c <= 0) return 1;
	else if (a > 20 || b > 20 || c > 20) visit[a][b][c]= w(20, 20, 20);
	

	else if (a < b && b < c) { 
		visit[a][b][c] =  w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c); 
	}
	else {
		visit[a][b][c] = w(a-1, b, c) + w(a-1, b - 1, c) + w(a-1, b, c-1) - w(a-1,b-1,c-1);
	}
	return visit[a][b][c];
}
int main(void) {
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)return 0;
		if (a <= 0 || b <= 0 || c <= 0)res = 1;
		else
			res = w(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << res<<endl;
	}                                                                                                 
}