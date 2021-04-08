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
string s;
int dp[2][1000000];
//dp[0]�� a / db[1] b

//����
//������� ���°� ���� a�ų� ����b���� �Ѵ�.

int main()
{
    cin >> n;
    cin >> s;


    //BBABB

    for (int i = 0; i < n; i++)
        dp[0][i] = dp[1][i] = (int)1e9; //�ִ밪 �־��ְ�

    if (s[0] == 'A') 
        dp[0][0] = 0, dp[1][0] = 1; //a�ΰ�� 0, b�� �ٲ۰�� +1

    else
        dp[0][0] = 1, dp[1][0] = 0;




    //��ĭ�� �̵��ϸ鼭 a�� �� ���ִ� ������ ��������.
    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'A')
        {
            //���繮�ڰ� a�̰� a�� ����� ���
            dp[0][i] = min(dp[0][i - 1], dp[1][i - 1] + 1); //�������� a������ �״��, �� ������ b������ ���ε��������
            //���� ���ڰ� a�̰� b�� ����� ���
            dp[1][i] = min(dp[0][i - 1] + 1, dp[1][i - 1] + 1); //�������� a������ ���� �����������, �� ������ b���� ���繮�� b�� �ϴ°�� + 1
        }
        else
        {  //���繮�ڰ� b�̰� a�� ����� ���
            dp[0][i] = min(dp[0][i - 1] + 1, dp[1][i - 1] + 1);  //�������� a������ ���繮�� +1, ������ b������ ���� ���������
            //���繮�ڰ� b�̰� b�� ����� ���
            dp[1][i] = min(dp[0][i - 1] + 1, dp[1][i - 1]); //������ a������ ������ +1, ������ ���� b������ �״��
        }
    }
    cout << dp[0][n - 1];
    return 0;
}
