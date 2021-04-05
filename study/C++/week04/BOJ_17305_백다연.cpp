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
//작은 사탕 3g, 큰 사탕 5g
//최대 wg의 사탕만 담을 수 있음., 당도의 합은?
//예제 50 40 100(3,3,5)

int n, w; //사탕의 개수와 무게 제한

vector<int> small;
vector<int> big;
long long sum = 0;
long long cnt = 0;
long long three[250001] = {
    0,
};
long long five[250001] = {
    0,
};

int main()
{
    cin >> n >> w;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == 3)
            small.push_back(y);
        else
            big.push_back(y);
    }

    //큰수부터 꺼낼수있도록
    sort(small.begin(), small.end());
    reverse(small.begin(), small.end());
    sort(big.begin(), big.end());
    reverse(big.begin(), big.end());

    int fivesize = big.size();
    int threesize = small.size();

    if (!small.empty())
    {
        for (int i = 1; i <= threesize; i++)
        {
            three[i] = (three[i - 1] + small[i - 1]);
        }
    }
    if (!big.empty())
    {
        for (int i = 1; i <= fivesize; i++)
        {
            five[i] = (five[i - 1] + big[i - 1]);
        }
    }

    long long temp = 0;
    long long ans = 0;

    int fivetotal = w / 5; //5가 들어갈 수 있는 최대값

    for (int i = 0; i <= min(fivetotal, fivesize); i++)
    {
        temp = five[i];

        int threetotal = (w - (i * 5)) / 3; //5개에 따른 3개
        threetotal = min(threetotal, threesize);

        temp += three[threetotal];

        ans = max(ans, temp);
    }

    cout << ans << endl;

    return 0;
}