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
int n;
int arr[100001];
int visit[100001];
int check[100001];
int cnt = 0;

void dfs(int x)
{
    int next = arr[x];
    visit[x] = true; 

    if(!visit[next])
        dfs(next);
    else
    {
        if(!check[next])
        {
            for(int i = next; i != x; i = arr[i])
                cnt++; //연결된 점들
            cnt++; //나
        }
    }
    check[x] = true;
    

}


int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        cin >> n;
        memset(arr, 0, sizeof(arr));
        memset(visit, false, sizeof(visit));
        memset(check, false, sizeof(check));

        cnt = 0;
        for(int i = 1; i <=n; i++)
        {
            cin >> arr[i];
        }
        for(int i = 1; i <=n; i++)
        {
            if(!visit[i])
                dfs(i);
        }
        cout << n - cnt << endl;
    }
    return 0;
}