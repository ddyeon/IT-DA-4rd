#include <iostream>
#include <string>
#include <set>

using namespace std;

int R, C;
char table[1010][1010] {};
int cnt;

bool check(int start, int end)
{
    set<string> s;

    for (int j = 0; j < C; j++) {
        string tmp;
        for (int i = start; i <= end; i++) {
            tmp += table[i][j];
        }
        if (s.find(tmp) == s.end()) {
            s.insert(tmp);
        }
        else {
            return false;
        }
    }

    return true;
}

void binarySearch(int left, int right, int end)
{
    if (left > right) {
        return;
    }

    int mid = (left + right) / 2;
    bool flag = check(mid, end);

    if (flag) {
        if (cnt < mid) {
            cnt = mid;
        }
        binarySearch(mid + 1, right, end);
    }
    else {
        binarySearch(left, mid - 1, end);
    }
}

void solve(void)
{
    binarySearch(1, R - 1, C - 1);
    cout << cnt << endl;
}

/*
    배열을 transpose하면서 입력
    R*C => C*R
*/
void input(void)
{
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> table[i][j];
        }
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}