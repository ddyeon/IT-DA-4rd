#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
//1965 ���ڳֱ�

using namespace std;
int n;
int dp[1001];
int arr[1001];

int main()
{
    cin >> n;

   //int maxvalue = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dp[0] = 1;
    int result = 0;
    for (int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; i++)
        {
            if(arr[i] > arr[j])
                dp[i] = max(dp[i],dp[j]); //����Ȱ��� �ִ밪���� ���
        }
        dp[i]++;
        result = max(result, dp[i]);
    }

    cout << result << endl;

    return 0;
}