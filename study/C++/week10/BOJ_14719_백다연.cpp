#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
//14719 빗물
int H,W;
//왼쪽 오른쪽중 나보다 큰값들 중 작은거에 맞춤.

int main()
{
    cin >> H >> W;
    int arr[W];
    for(int i = 0; i < W; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    for(int i = 1; i < W-1; i++)
    {
        int left = 0;
        int right = 0;

        for(int j = 0; j < i; j++)
            left = max(left, arr[j]);
        for(int k = W-1; k > i; k--)
            right = max(right, arr[k]);

        //빗물 더하기
        int height = min(left,right);
        ans += max(0, height - arr[i]); //최고높이에서 내 자신 빼기
        
    }

    cout << ans << endl;



    return 0;
}

