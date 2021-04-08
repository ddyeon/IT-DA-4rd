#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int E, EM, M, MH, H;
	cin >> E >> EM >> M >> MH >> H;
	while (EM != 0 || MH != 0) {
		if (E > M) {
			for (int i = 0; i < E - M; i++) {
				if (EM == 0)
					break;
				else {
					EM--;
					M++;
				}
			}
		}
		else if (E < M) {
			for (int i = 0; i < M - E; i++) {
				if (EM == 0)
					break;
				else {
					EM--;
					E++;
				}
			}
		}
		else if (E == M) {
			for (int i = 0; i < EM; i++) {
				if (EM == 0)
					break;
				else {
					EM--;
					E++;
				}
				if (EM == 0)
					break;
				else {
					EM--;
					M++;
				}
			}
		}
		if (H > M) {
			for (int i = 0; i < H - M; i++) {
				if (MH == 0)
					break;
				else {
					MH--;
					M++;
				}
			}
		}
		else if (H < M) {
			for (int i = 0; i < M - H; i++) {
				if (MH == 0)
					break;
				else {
					MH--;
					H++;
				}
			}
		}
		else if (H == M) {
			for (int i = 0; i < MH; i++) {
				if (MH == 0)
					break;
				else {
					MH--;
					M++;
				}
				if (MH == 0)
					break;
				else {
					MH--;
					H++;
				}
			}
		}
	}
	cout << min(min(E, M),H);
}