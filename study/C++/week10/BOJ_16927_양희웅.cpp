#include <iostream>

using namespace std;

int arr[310][310] {};
int N, M, R;

void solve(void)
{
    int r1 = 0; int c1 = 0;
    int r2 = N - 1; int c2 = 0;
    int r3 = N - 1; int c3 = M - 1;
    int r4 = 0; int c4 = M - 1;

    while ((r1 < r2) && (c1 < c4)) {
        int rotate = R % ((r2 - r1) * 2 + (c4 - c1) * 2);
        while (rotate--) {
            int tmp = arr[r1][c1];

            for (int i = c1; i < c4; i++) {
                arr[r1][i] = arr[r1][i + 1];
            }
            for (int i = r4; i < r3; i++) {
                arr[i][c4] = arr[i + 1][c4];
            }
            for (int i = c3; i > c2; i--) {
                arr[r3][i] = arr[r3][i - 1];
            }
            for (int i = r2; i > r1; i--) {
                arr[i][c2] = arr[i - 1][c2];
            }

            arr[r1 + 1][c1] = tmp;
        }
        r1++; c1++;
        r2--; c2++;
        r3--; c3--;
        r4++; c4--;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void input(void)
{
    cin >> N >> M >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}