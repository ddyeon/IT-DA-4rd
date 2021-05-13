#include <iostream>

using namespace std;

int N;
int arr[5010] {};
bool memo[400010] {};
int result;

void solve(void)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (memo[arr[i] - arr[j] + 200000]) {
                result++;
                break;
            }
        }
        for (int j = 0; j <= i; j++) {
            if (arr[i] + arr[j] > 100000 || arr[i] + arr[j] < -100000) {
                continue;
            }
            if (memo[arr[i] + arr[j] + 200000]) {
                continue;
            }
            memo[arr[i] + arr[j] + 200000] = true;
        }
    }
    cout << result << endl;
}

void input(void)
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}