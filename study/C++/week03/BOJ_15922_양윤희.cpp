#include <iostream>
#include <queue>
using namespace std;
int n, sum, x, y, s, e;
struct Node {
	int x, y;
};
priority_queue<Node> q;
bool operator<(Node n, Node m) {
	if (n.x > m.x)return true;
	if (n.x < m.x)return false;
	return n.y > m.y;
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		q.push({ x,y });
	}
	s = q.top().x; e = q.top().y;
	q.pop();
	for (int i = 0; i < n-1; i++) {
		if (q.top().x > e) {
			sum += abs(s - e);
			s = q.top().x;
			e = q.top().y;
		}
		else if (q.top().y > e && q.top().x <= e) {
			e = q.top().y;
		}
		q.pop();
	}
	sum += abs(s - e);
	cout << sum;
}