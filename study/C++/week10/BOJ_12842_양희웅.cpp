#include <iostream>

using namespace std;

int n, s, m;
int eat_time[100010] {};

void solve(void)
{
    int eat = n - s;
    int tmp = 0;
    
    for (int i = 0; ; i++) {
        for (int j = 0; j < m; j++) {
            if (i % eat_time[j] == 0) {
                tmp++;
                if (tmp == eat) {
                    cout << j + 1 << endl;
                    return;
                }
            }
        }
    }
}

void input(void)
{
    cin >> n >> s;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> eat_time[i];
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}