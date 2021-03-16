#include <iostream>
#include <cstring>

#define MAX     100010

using namespace std;

int T, n;
int team;
int students[MAX];
bool check[MAX];
bool visited[MAX];

void dfs(int start)
{
    visited[start] = true;
    int next = students[start];
    if (!visited[next]) {
        dfs(next);
    }
    else {
        if (!check[next]) { //check된 상태면 한바퀴 돌았다는거 => team 발견!!
            for (int i = next; i != start; i = students[i]) {
                team++;
            }
            team++;
        }
    }
    check[start] = true;
}

void solve(void)
{
    int tmp; 

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        team = 0;
        memset(students, 0, sizeof(students));
        memset(check, false, sizeof(check));
        memset(visited, false, sizeof(visited));
        for (int j = 1; j <= n; j++) {
            cin >> students[j];
        }
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                dfs(j);
            }
        }
        cout << n - team << endl;
    }
}

int main(void)
{
    solve();

    return 0;
}