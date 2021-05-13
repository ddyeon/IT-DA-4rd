#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
//13302 ����Ʈ
//Ʋ�Ƚ��ϴ� ��..


using namespace std;
int n, m; //����, �� �� ���� ��
bool arr[101] = {false,};
int dp[101][101]= {int(1e9),};
//�Ϸ� �̿�� ����
//3�� �̿�� 25000�� + ����1��
//5�� �̿�� 37000�� + ����2��

int dfs(int today, int cou, int price)
{
    if(today > n) //��¥ ������ price
        return 0;
    if(dp[today][cou]) //�̹� Ž��
        return dp[today][cou] + price;
    if(arr[today]) //���³�
        return dfs(today + 1, cou, price);

    //3��, �Ϸ�, 5��
    dp[today][cou] = min({dfs(today + 1, cou, price + 10000),dfs(today + 3, cou + 1, price + 25000),dfs(today + 5, cou + 2, price + 37000)});
    if(cou >=3)
        dp[today][cou] = min(dp[today][cou],dfs(today + 1, cou - 3, price)); //����ϱ�

    return dp[today][cou];
}


int main()
{
    cin >> n >> m;

    int work = 0;
    for(int i = 0; i < m; i++)
    {
        cin >> work;
        arr[work] = true;
    }
    int ans = 0;
    ans = dfs(1,0,0);

    cout << ans << endl;


    return 0;
}
