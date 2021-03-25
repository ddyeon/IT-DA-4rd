#include <iostream>
#include <queue>

using namespace std;

int N, T, G;
int cnt;
bool checked[99999] {};

int A(int num)
{
    if (num + 1 > 99999) {
        return -1;
    }

    return num + 1;
}

int B(int num)
{
    int tmp = 1;

    num *= 2;
    if (num > 99999) {
        return -1;
    }
    for (int i = 0; i < 5; i++) {
        if (num < tmp * 10) {
            return num - tmp;
        }
        tmp *= 10;
    }
    return 0;
}

void solve(void)
{
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    checked[N] = true;

    while (!q.empty()) {
       int num = q.front().first;
       int cnt = q.front().second;
       q.pop();

       if (cnt > T) {
           cout << "ANG" << endl;
           return;
       }
       if (num == G) {
           cout << cnt << endl;
           return;
       }
       if (A(num) != -1 && !checked[A(num)]) {
           q.push(make_pair(A(num), cnt + 1));
           checked[A(num)] = true;
       }
       if (B(num) != -1 && !checked[B(num)]) {
           q.push(make_pair(B(num), cnt + 1));
           checked[B(num)] = true;
       }
    }
    cout << "ANG" << endl;
}

void input(void)
{
    cin >> N >> T >> G;
}

int main(void)
{
    input();
    solve();

    return 0;
}