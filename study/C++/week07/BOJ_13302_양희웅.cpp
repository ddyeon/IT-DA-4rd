#include <iostream>
#include <cstring>

#define Min(x,y)    ((x)<(y)?(x):(y))
#define Min3(x,y,z)  ((x)<(y)?(x):((y)<(z)?(y):(z)))

#define ticket1     10000
#define ticket3     25000
#define ticket5     37000

using namespace std;

int N, M; //N: 여름방학 일수, M: 놀 수 없는 날
int arr[110][50] {};
bool imp[110] {};

int dp(int day, int coupon)
{
    if (day > N) {
        return 0;
    }
    if (arr[day][coupon] != -1) {
        return arr[day][coupon];
    }
    if (imp[day]) {
        return arr[day][coupon] = dp(day + 1, coupon);
    }
    arr[day][coupon] = Min3(ticket1 + dp(day + 1, coupon), ticket3 + dp(day + 3, coupon + 1), ticket5 + dp(day + 5, coupon + 2));
    if (coupon >= 3) {
        arr[day][coupon] = Min(arr[day][coupon], dp(day + 1, coupon - 3));
    }
    return arr[day][coupon];
}

void solve(void)
{
    memset(arr, -1, sizeof(arr));
    cout << dp(1, 0) << endl;
}

void input(void)
{
    int tmp;

    cin >> N >> M;
    for (int i = 0 ; i < M; i++) {
        cin >> tmp;
        imp[tmp] = true;
    }
}

int main(void)
{
    input();
    solve();

    return 0;
}