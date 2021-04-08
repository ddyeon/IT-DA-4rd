#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
typedef long long ll;
ll N, W;
deque <ll> small;
vector <ll> big;
vector <pair<ll, ll>> zaru;
int main()
{
	ll w = 0;
	ll sweet = 0;
	ll SWEET;
	cin >> N >> W;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 3) { small.push_back(b); }
		if (a == 5) { big.push_back(b); }
	}
	sort(small.begin(), small.end(), greater<ll>());
	sort(big.begin(), big.end(), greater<ll>());
	for (int i = 0; i < sizeof(big);i++) {
		if (w+5 > W) { break; }
		w += 5;
		sweet += big[i];
		zaru.push_back(make_pair(5, big[i]));
	}
	SWEET = sweet;
	while (!zaru.empty()) {
		w -= zaru.back().first;
		sweet -= zaru.back().second;
		zaru.pop_back();
		while(!small.empty()) {
			if (w+3 > W) { break; }
			w += 3;
			sweet += small.front();
			small.pop_front();
		}
		SWEET = max(sweet, SWEET);
	}
    cout << SWEET;
}

