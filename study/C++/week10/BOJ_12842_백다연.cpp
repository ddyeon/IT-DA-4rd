#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
//12842 튀김소보로 
//집어들은건 제외
/* m명이 있었고 마지막 튀김소보로 1개를 먹는데
걸리는 시간 유츄 가능
마지막 튀김소보로 집어든 사람 번호  */
int n, s;
int arr[100005];
int main()
{
    cin >> n >> s; //튀김 개수와 남은 개수
    int m; //사람수
    cin >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    int eat = n-s; //먹은 소보로 개수

    for(int time = 0; time < 1000000; time++)
    {
        for(int i = 0; i < m; i++)
            if(time % arr[i] == 0) {
                sum++;
                if(sum >= eat)
                    {
                        cout << i+1 << endl;
                        return 0;
                    }
            }


    }

}
