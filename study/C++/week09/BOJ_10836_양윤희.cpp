#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
/*
	m*m ���� ������ ����
	���� ������ �ڶ�
	ù�� ��ħ ũ��� 1 --> N�� ���� �ݺ�

	+0 +1 +2 �߿� �ڶ� 

	1. ���� ���� ���� ���� ���� ���� �ֹ������� �ڽ��� �ӵ� ����
	2. ��, ����, �� �� ���� ���� �ڶ� ��ŭ �ڽŵ� �ڶ���.

	//�Է� m �� ũ�� n ��¥ ��
	//�ڶ�� ������ ���� �޾Ʒ� -> ���� ->���� ���� ��

*/
int map[701][701], tmp[701];
int m, n, getMax, index;
int dat[3];
int main(void) {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> dat[0] >> dat[1] >> dat[2];
		index = dat[0];
		for (int j = 0; j < dat[1]; j++, index++) {
			tmp[index]++;
		}
		for (int j = 0; j < dat[2]; j++, index++) {
			tmp[index]+=2;
		}
	}
	index = 0;
	for (int i = m - 1;i > 0; i--, index++) {
		map[i][0] = tmp[index];
	}
	for (int i = 0; i < m; i++, index++) {
		map[0][i] = tmp[index];
	}
	for (int y = 1; y < m; y++) {
		for (int x = 1; x < m; x++) {
			getMax = max(map[y-1][x], map[y-1][x - 1]);
			getMax = max(map[y][x - 1], getMax);
			map[y][x] = getMax;
		}
	}
	

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] + 1 << " ";
		}
		cout << endl;
	}
}