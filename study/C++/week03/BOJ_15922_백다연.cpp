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
//15922
int n;
vector<pair<long long, long long>> v;

int main()
{
    cin >> n;
    long long  x,y;

    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(), v.end());


    int sum = 0;
    long long left = -1e9 -1;
    long long right = -1e9 -1;

    for(int i = 0; i < n; i++)
    {
        int curleft = v[i].first;
        int curright = v[i].second;

        if(left <= curleft && curright <= right) //���ԵǴ� ���
            continue; 
        if(curleft < right) // ��ġ�� ���
            sum -= (right - curleft);

        sum += curright - curleft; // �ȸ����� ���

        left = curleft;
        right = curright;

    }
   
   cout << sum << endl;

}
