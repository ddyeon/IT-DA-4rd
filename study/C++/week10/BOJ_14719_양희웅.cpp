#include <iostream>
#include <map>

using namespace std;

int H, W;
int arr[510] {};
int result;

void solve(void)
{
    int tmp = 0;
    bool left; // 왼쪽 기둥이 존재?

    for (int i = 1; i <= H; i++) {
        left = false;
        for (int j = 0; j < W; j++) {
            if (arr[j] >= i) {
                if (!left) { //왼쪽 기둥 설정
                    left = true;
                }
                else if (left) {
                    result += tmp;
                    tmp = 0;
                }
            }
            else if (arr[j] < i) {
                if (left) {
                    tmp++;
                }
            }
        }
    }

    cout << result << endl;
}

void input(void)
{
    cin >> H >> W;
    for (int i = 0; i < W; i++) {
        cin >> arr[i];
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}