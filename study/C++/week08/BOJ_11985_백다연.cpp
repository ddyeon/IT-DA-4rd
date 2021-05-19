#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//11985 ������ ����
/* ����� k+sx(a-b) a�� ���� ū ������ ũ��,
b�� ���ڿ� ���� ���� ���� ������ũ��, s�� ����
k�� ���ڸ� �����ϴ� ��� */
int n, m, k;
long long arr[20001];
long long dp[20001];
int main()
{
    cin >> n >> m >> k; //����������, �ִ밳��,������

    for (long long i = 1; i <=n; i++)
    {
        cin >> arr[i];
        dp[i] = k * i; //1���� ����ϴ� ���
    }

    long long min_value = 0;
    long long max_value = 0;
    for (long long i = 0; i < n; i++)
    {
        min_value = arr[i+1];
        max_value = arr[i+1];

        for (long long j = 1; j <=m && i + j <=n; j++)
        {
            min_value = min(min_value, arr[i + j]);
            max_value = max(max_value, arr[i + j]);

            dp[i + j] = min(dp[i + j], dp[i] + k + j * (max_value - min_value));
        }
    }
    cout << dp[n] << endl;
}
