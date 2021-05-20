#include <iostream>
#include <cstring>

#define Max(x,y)    ((x)>(y)?(x):(y))

using namespace std;

int n;
int box[1010] {};
int memo[1010] {};
int result = 1;

void solve(void)
{  
    for (int i = 0; i < n; i++) {
        memo[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            if (box[i] > box[i - j]) {
                memo[i] = memo[i - j] + 1;
                result = Max(result, memo[i]);
                break;
            }
        }
    }
    cout << result << endl;
}

void input(void)
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> box[i];
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}