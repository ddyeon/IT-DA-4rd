#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
//13302 리조트
//틀렸습니다 뜸..


using namespace std;
int n, m; //방학, 갈 수 없는 날
bool arr[101] = {false,};
int dp[101][101]= {int(1e9),};
//하루 이용권 만원
//3일 이용권 25000원 + 쿠폰1장
//5일 이용권 37000원 + 쿠폰2장

int dfs(int today, int cou, int price)
{
    if(today > n) //날짜 지나면 price
        return 0;
    if(dp[today][cou]) //이미 탐색
        return dp[today][cou] + price;
    if(arr[today]) //쉬는날
        return dfs(today + 1, cou, price);

    //3일, 하루, 5일
    dp[today][cou] = min({dfs(today + 1, cou, price + 10000),dfs(today + 3, cou + 1, price + 25000),dfs(today + 5, cou + 2, price + 37000)});
    if(cou >=3)
        dp[today][cou] = min(dp[today][cou],dfs(today + 1, cou - 3, price)); //무료니깐

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
