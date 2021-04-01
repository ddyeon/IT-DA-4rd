#include<iostream>
#include <queue>
#include <vector>
using namespace std;
/*
인호 방학 M
N 약속
약속의 행복값 H
기분이 0미만이면 기분^2만큼 우울함을 느낀다.
약속이 없으면 어제보다 -1
우울의 최소합
약속 개수 N, 방학개수M
15였으면 8을 썼으니까 7이 남고 7/3 2 1
*/
int H[1001], N, M, appoint, depress, namom, moc, l;

int main(void) {
	cin >> N >> M;
	for (int i = 0;i < N; i++) {
		cin >> H[i];
		appoint += H[i] + 1;
	}
	namom = M - appoint;//방학개수에서 약속 기분 다빼기
	moc = namom/ (N+1); //나머지 기분 / 방학 개수 --몫
	l = namom % (N+1); //나머지 기분 % 방학 개수 --나머지

	for (int i = 1; i <= moc; i++) {
		depress += i * i *( N + 1);
	}
	for (int i = 0; i < l; i++) {
		depress += (moc+1) * (moc + 1);
	}
	cout << depress;
}
