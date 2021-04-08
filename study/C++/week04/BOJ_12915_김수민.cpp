#include <iostream>
#include <algorithm>
using namespace std;
int result = 0;
int E, EM, M, MH, H;
int main()
{
	cin >> E >> EM >> M >> MH >> H;
	while ((EM > 0) or (MH > 0)){
		if (EM > 0) {
			if (E < M) {
				EM--;
				E++;
			}
			else if (M < E) {
				EM--;
				M++;
			}
		}
		if (MH > 0) {
			if ((H < M) && (MH > 0)) {
				MH--;
				H++;
			}
			else if (M < H) {
				MH--;
				M++;
			}
		}
		if ((E==M)or(M==H)) {
			if (E == M) {
				if (EM >= 2) {
					E++;
					M++;
					EM -= 2;
				}
				else if (EM == 1) {
					E++;
					EM--;
				}
			}
			if (M == H) {
				if (MH >= 2) {
					M++;
					H++;
					MH -= 2;
				}
				else if (MH == 1) {
					
				}
			}
			
		}

	}
	result = min(E, M);
	result = min(result, H);
    cout << result;
}
