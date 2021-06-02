#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
//16927 배열돌리기2
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int arr[301][301];
int N, M, r;

void rotate(int x, int box_size)
{
    int rot = r % box_size; //몇번마다 반복되는지

    for (int i = 0; i < rot; i++)
    {
        int start = arr[x][x];
        int r = x;
        int c = x;

        int k = 0;
        while (k < 4) //방향 총 4개
        {
            int nr = r + dx[k];
            int nc = c + dy[k];

            if (nr == x && nc == x)
                break;
            if (x <= nr && nr < N - x && x <= nc && nc < M - x)
            {
                arr[r][c] = arr[nr][nc];
                r = nr;
                c = nc;
            }
            else
                k++;
        }
        arr[x + 1][x] = start;
    }
}

int main()
{
    cin >> N >> M >> r;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    int min_rot = min(N, M) / 2;

    int n = N;
    int m = M;
    for (int i = 0; i < min_rot; i++)
    {
        rotate(i, (n - 1) * 2 + (m - 1) * 2);
        n -= 2;
        m -= 2;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << arr[i][j] << "";
        }
        cout << endl;
    }

    return 0;
}
