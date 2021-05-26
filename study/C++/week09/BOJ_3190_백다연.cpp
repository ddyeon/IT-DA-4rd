#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <deque>

using namespace std;
//3109 뱀
//이동한칸에 사과가 있으면 먹고 꼬리는 움직이지 않음
//사과 없으면 몸길이는 변하지 않지만 꼬리칸 비워줌.
int n, k;
int L, X, C;
int times =0;
deque <pair<int,int>> dq;

int arr[101][101] = {
    0,
};
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
vector <pair<int,char>> v;
//머리2 꼬리0
void search()
{
    int x = 1;
    int y = 1; //시작위치
    int go = 0;
    int cnt = 0;
    dq.push_back({x,y});
    arr[x][y] = 2;

    while(true)
    {
        times++;
        int nx = x + dx[go];
        int ny = y + dy[go];

        //갈수없는곳과 자기 자신
        if(nx<1 || ny <1 || nx > n || ny > n || arr[nx][ny]==2)
            return;
        else if(arr[nx][ny] == 0) //사과가 없으면
        {
            arr[nx][ny] = 2; 
            arr[dq.back().first][dq.back().second] = 0; //꼬리칸 비워줘야함
            dq.pop_back();
            dq.push_front({nx,ny}); //머리부분 삽입

        }
        else if(arr[nx][ny] == 1) //사과존재
        {
            arr[nx][ny] = 2;
            dq.push_front({nx, ny});
        }

        if(cnt < v.size())
        {
            if(times == v[cnt].first)
            {
                if(v[cnt].second == 'L')
                    go = (go+1) % 4;
                else if(v[cnt].second == 'D')
                    go = (go+3) % 4;
                cnt++;

            }
        }
        y = ny;
        x = nx;


    }

}



int main()
{
    cin >> n; //보드의 크기
    cin >> k; // k개의 줄에 사과의 위치

    int a, b;
    for (int i = 1; i <=k; i++)
    {
        cin >> a >> b;
        arr[a][b] = 1; //사과가 있는 곳
    }
    cin >> L; //뱀의 방향 횟수

    int x;
    char dir;
    for (int i = 1; i <=L; i++) //초와 왼쪽 오른쪽
    {
        cin >> x >> dir;
        v.push_back(make_pair(x,dir));

    }

    search();
    cout << times << endl;


}