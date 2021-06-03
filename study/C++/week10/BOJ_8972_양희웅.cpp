#include <iostream>
#include <cstring>

#define abs(x)  ((x)>=0?(x):-(x))

using namespace std;

int R, C;
char board[110][110] {};
char move_dir[110] {};
int dr[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int dc[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};

pair<int, int> jongsu_robot;
pair<int, int> crazy_robot[10010] {};
int num_of_crazy_robot;

pair<int, int> move_robot(pair<int, int> jongsu_robot, pair<int, int> crazy_robot) //종수의 로봇이 이동한 방향을 받아서 미친 아두이노들의 위치를 변경
{
    pair<int, int> tmp_crazy_robot;
    pair<int, int> new_crazy_robot;
    pair<int, int> final_pos = make_pair(0, __INT32_MAX__); //어느 방향으로 움직였는지, 그 때 종수와의 거리
    int tmp_distance;    

    for (int i = 0; i < 9; i++) {
        tmp_crazy_robot = make_pair(crazy_robot.first + dr[i], crazy_robot.second + dc[i]);
        tmp_distance = abs(jongsu_robot.first - tmp_crazy_robot.first) + abs(jongsu_robot.second - tmp_crazy_robot.second);

        if (tmp_distance < final_pos.second) {
            final_pos.first = i;
            final_pos.second = tmp_distance;
        }
    }
    new_crazy_robot.first = crazy_robot.first + dr[final_pos.first];
    new_crazy_robot.second = crazy_robot.second + dc[final_pos.first];

    return new_crazy_robot;
}

void solve(void)
{  
    for (int i = 0; i < strlen(move_dir); i++) {
        board[jongsu_robot.first][jongsu_robot.second] = '.';
        jongsu_robot.first += jongsu_robot.first + dr[move_dir[i]];
        jongsu_robot.second += jongsu_robot.second + dc[move_dir[i]];
        board[jongsu_robot.first][jongsu_robot.second] = 'I';

        for (int j = 0; j < num_of_crazy_robot; j++) {
            board[crazy_robot[j].first][crazy_robot[j].second] = '.';
            crazy_robot[j] = move_robot(jongsu_robot, crazy_robot[i]);
            board[crazy_robot[j].first][crazy_robot[j].second] = 'R';
            if (crazy_robot[j].first == jongsu_robot.first && crazy_robot[j].second == jongsu_robot.second) {
                cout << "kraj X" << endl;
                return;
            }
        }
    }
}

void input(void)
{
    char tmp[110];

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> tmp;
        for (int j = 0; j < C; j++) {
            board[i][j] = tmp[j];
            if (tmp[j] == 'I') { //종수의 로봇인 경우
                jongsu_robot.first = i;
                jongsu_robot.second = j;
            }
            else if (tmp[j] == 'R') { //미친 로봇인 경우
                crazy_robot[num_of_crazy_robot].first = i;
                crazy_robot[num_of_crazy_robot++].second = j;
            }
        }
    }
    cin >> move_dir; 
}

int main(void)
{
    input();
    solve();

    return 0;
}