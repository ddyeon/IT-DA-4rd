#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector <int> l;
int main()
{
	int gold=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		l.push_back(a);
	}
	sort(l.begin(), l.end(), greater<int>());
	for (int i = 0; i < n-1; i++) {
		gold += l[i] + l[i + 1];
		l[i + 1] = l[i];
	}
    cout <<gold;
}

