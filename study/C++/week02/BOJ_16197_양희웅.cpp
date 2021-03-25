#include <iostream>
#include <queue>

using namespace std;

int N, M;
char board[30][30] {};
bool check1[30][30] {};
bool check2[30][30] {};
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
pair<int, int> coin1 = {-1, -1};
pair<int, int> coin2 = {-1, -1};
int result;

void bfs(pair<int, int> start1, pair<int, int> start2)
{
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(start1, start2));
    check1[start1.first][start1.second] = true;
    check2[start2.first][start2.second] = true;

    while (!q.empty()) {
        pair<int, int> next1 = q.front().first;
        pair<int, int> next2 = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> tmp1 = make_pair(next1.first + dr[i], next1.second + dc[i]);
            pair<int, int> tmp2 = make_pair(next2.first + dr[i], next2.second + dc[i]);

            if (result > 10) {
                result = -1;
                return;
            }
            if (board[tmp1.first][tmp1.second] == '#' || board[tmp2.first][tmp2.second] == '#' 
                    || check1[tmp1.first][tmp1.second] == true || check2[tmp2.first][tmp2.second] == true) {
                continue;
            }
            if ((tmp1.first >= N || tmp1.first < 0 || tmp1.second >= M || tmp1.second < 0) 
                    && (tmp2.first >= N || tmp2.first < 0 || tmp2.second >= M || tmp2.second < 0)) {
                continue;
            }
            if (board[tmp1.first][tmp1.second] == '.' || board[tmp1.first][tmp1.second] == 'o'
                    || board[tmp2.first][tmp2.second] == '.' || board[tmp2.first][tmp2.second] == 'o') {
                check1[tmp1.first][tmp1.second] = true;
                check2[tmp2.first][tmp2.second] = true;
                q.push(make_pair(tmp1, tmp2));
                result++;
            }
        }
    }
}

void solve(void)
{
    bfs(coin1, coin2);
    cout << result << endl;
}

void input(void)
{
    char tmp;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tmp;
            board[i][j] = tmp;
            if (tmp == 'o') {
                if (coin1.first == -1) {
                    coin1.first = i;
                    coin1.second = j;
                }
                else if (coin2.first == -1) {
                    coin2.first = i;
                    coin2.second = j;
                }
            }
        }
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}