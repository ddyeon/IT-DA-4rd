#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <deque>

using namespace std;
//3109 ��
//�̵���ĭ�� ����� ������ �԰� ������ �������� ����
//��� ������ �����̴� ������ ������ ����ĭ �����.
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
//�Ӹ�2 ����0
void search()
{
    int x = 1;
    int y = 1; //������ġ
    int go = 0;
    int cnt = 0;
    dq.push_back({x,y});
    arr[x][y] = 2;

    while(true)
    {
        times++;
        int nx = x + dx[go];
        int ny = y + dy[go];

        //�������°��� �ڱ� �ڽ�
        if(nx<1 || ny <1 || nx > n || ny > n || arr[nx][ny]==2)
            return;
        else if(arr[nx][ny] == 0) //����� ������
        {
            arr[nx][ny] = 2; 
            arr[dq.back().first][dq.back().second] = 0; //����ĭ ��������
            dq.pop_back();
            dq.push_front({nx,ny}); //�Ӹ��κ� ����

        }
        else if(arr[nx][ny] == 1) //�������
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
    cin >> n; //������ ũ��
    cin >> k; // k���� �ٿ� ����� ��ġ

    int a, b;
    for (int i = 1; i <=k; i++)
    {
        cin >> a >> b;
        arr[a][b] = 1; //����� �ִ� ��
    }
    cin >> L; //���� ���� Ƚ��

    int x;
    char dir;
    for (int i = 1; i <=L; i++) //�ʿ� ���� ������
    {
        cin >> x >> dir;
        v.push_back(make_pair(x,dir));

    }

    search();
    cout << times << endl;


}