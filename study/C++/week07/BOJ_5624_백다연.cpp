#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
//5624 좋은 수

using namespace std;

int arr[5001];
bool visit[400000];

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int cnt = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j=0; j < i; i++)
        {
            //두개뺐을때 값이 존재하는 경우 좋은 수가 될 수 있음.
            if(visit[arr[i]-arr[j] + 200000]) //최대합이 2000000
            {
                cnt++;
                break;
            }
        }
        
        for(int k =0; k <=i; k++)
            visit[arr[i]+arr[k] + 200000] = true;
    }

    cout << cnt << endl;

    return 0;
}
