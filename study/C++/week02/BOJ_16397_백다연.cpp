#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
int n,t,g;
int visit[100000];

int cal(int num)
{
    if(num == 0)
        return num;

    int temp = num * 2;
    num = temp;
    int digit = 0;
    while(num > 0)
    {
        digit++;
        num = num / 10;
    }
    int val = 1;
    for(int i = 0; i < digit-1; i++)
        val *= 10;

    temp = temp - val;
    return temp;
}


int main()
{
    cin >> n >> t >> g;

    queue<pair<int, int>> q;
    visit[n] = true;
    q.push(make_pair(n, 0)); //현재 숫자랑 시도횟수

    
    while (!q.empty())
    {
        int current = q.front().first;
        int time = q.front().second;
        q.pop();

        if (time > t) //횟수초과한경우
        {
            cout << "ANG" << endl;
            return 0;
        }
        if (current == g) //같은경우
        {
            cout << time << endl;
            return 0;
        }

        //a버튼 눌렀을 때
        if (current + 1 <= 99999 && !visit[current + 1])
        {
            q.push(make_pair(current+1, time + 1));
            visit[current + 1] = true;
        }
        //b버튼 계산
        int bnum = cal(current);
        //cout << bnum << endl;
        if (current * 2 <= 99999 && !visit[bnum])
        {
            q.push(make_pair(bnum, time + 1));
            visit[bnum] = true;
        }
    }



    cout << "ANG"<< endl;
}