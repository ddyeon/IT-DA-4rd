#include <iostream>
#include <queue>

using namespace std;

int M, N;
int poster[260][260] {};
bool visited[260][260] {};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int result;

void bfs(pair<int, int> start)
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        pair<int, int> next = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int tmpX = next.first + dx[i];
            int tmpY = next.second + dy[i];

            if (tmpX < 0 || tmpX >= M || tmpY < 0 || tmpY >= N) {
                continue;
            }
            if (poster[tmpX][tmpY] == 1 && visited[tmpX][tmpY] == false) {
                visited[tmpX][tmpY] = true;
                q.push(make_pair(tmpX, tmpY));
            }
        }
    }
}

void solve(void)
{
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (poster[i][j] == 1 && visited[i][j] == false) {
                bfs(make_pair(i, j));
                result++;
            }
        }
    }
    cout << result << endl;
}

void input(void)
{
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> poster[i][j];
        }
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}