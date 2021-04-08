#include <iostream>
#include <queue>

using namespace std;

int N, M;
char war[110][110] {};
bool visited[110][110] {};
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int White, Blue;

void bfs(pair<int, int> start, char color)
{
    queue<pair<int, int>> q;
    int people = 1;
    visited[start.first][start.second] = true;

    q.push(start);
    while (!q.empty()) {
        pair<int, int> next = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextR = next.first + dr[i];
            int nextC = next.second + dc[i];
            
            if (nextR < 0 || nextR >= M || nextC < 0 || nextC >= N) {
                continue;
            }
            if (!visited[nextR][nextC] && war[nextR][nextC] == color) {
                visited[nextR][nextC] = true;
                people++;
                q.push(make_pair(nextR, nextC));
            }
        }
    }
    switch (color) {
    case 'W':
        White += (people * people);      
        break;
    case 'B':
        Blue += (people * people);
        break;
    }
}

void solve(void)
{
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                if (war[i][j] == 'W') {
                    bfs(make_pair(i, j), 'W');
                }
                else if (war[i][j] == 'B') {
                    bfs(make_pair(i, j), 'B');
                }
            }
        }
    }
    cout << White << ' ' << Blue << endl;
}

void input(void)
{
    char tmp[110];

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        for (int j = 0; j < N; j++) {
            war[i][j] = tmp[j];
        }
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}