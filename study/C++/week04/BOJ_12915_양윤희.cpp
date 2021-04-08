#include<iostream>
#include <queue>
#include <vector>
using namespace std;
//대회 문제 3
//E 쉬운 EM 쉬운중간 MH 중간어려움, H 어려운
int E, EM, M, MH, H, cnt;
int main(void) {
	cin >> E >> EM >> M >> MH >> H;
	while (true) {
		if (E <= 0)EM--;
		else E--;
		if (M <= 0) {
			if (EM > MH)EM--;
			else if (EM == MH) {
				if (E >= H)EM--;
				if (H > E)MH--;
			}
			else MH--;
		}
		else M--;
		if (H <= 0)MH--;
		else H--;

		if (E ==-1 || EM == -1)break;
		if (H == -1 || MH == -1)break;
		if ((M == -1 || EM == -1) || (M == -1 || MH == -1))break;
		cnt++;
		cout << E << " " << EM << " " << M << " " << MH << " " << H << endl;
	}
	cout << cnt;
}