#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//10476 ���� �̼����ð�
//����2, ���� N, k���� ���� �ݾƾ���.
//�������� �ι��� ��� �ݰų� �밢������ ������ �ȵ�.
//��ġ�� ���� �ִ��
int n, k;
int arr[201][2];
int dp[201][201][3]; //���ʸ� ������ ���, �����ʸ� ������ ���, �ȴ����� ���
//�ʹ���ƴ�...
int main()
{
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
        cin >> arr[i][0] >> arr[i][1];
    int a,b;
    cin >> a >> b;

    dp[1][1][0] = arr[1][1]; //������ ������� �����ʰ��� ��ġ ���
    dp[1][1][1] = arr[1][0]; //�������� ���� ��� ���ʰ���
    dp[1][0][2] = arr[1][1] + arr[1][0]; //�Ѵ� ��������.

    for(int i=2; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            if(j>=1)
            {
                dp[i][j][0] = max(dp[i-1][j-1][0],dp[i-1][j-1][2]) + arr[i][1];
                dp[i][j][1] = max(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + arr[i][0];
            }
            if( i != j)
                dp[i][j][2] = max(dp[i-1][j][0], max(dp[i-1][j][1], dp[i-1][j][2])) + arr[i][0] + arr[i][1];
        }
    }

    cout << max(dp[n][k][0], max(dp[n][k][1], dp[n][k][2])) << endl;

    return 0;
   
}
