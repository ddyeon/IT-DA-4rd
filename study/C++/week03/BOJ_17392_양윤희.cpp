#include<iostream>
#include <queue>
#include <vector>
using namespace std;
/*
��ȣ ���� M
N ���
����� �ູ�� H
����� 0�̸��̸� ���^2��ŭ ������� ������.
����� ������ �������� -1
����� �ּ���
��� ���� N, ���а���M
15������ 8�� �����ϱ� 7�� ���� 7/3 2 1
*/
int H[1001], N, M, appoint, depress, namom, moc, l;

int main(void) {
	cin >> N >> M;
	for (int i = 0;i < N; i++) {
		cin >> H[i];
		appoint += H[i] + 1;
	}
	namom = M - appoint;//���а������� ��� ��� �ٻ���
	moc = namom/ (N+1); //������ ��� / ���� ���� --��
	l = namom % (N+1); //������ ��� % ���� ���� --������

	for (int i = 1; i <= moc; i++) {
		depress += i * i *( N + 1);
	}
	for (int i = 0; i < l; i++) {
		depress += (moc+1) * (moc + 1);
	}
	cout << depress;
}
