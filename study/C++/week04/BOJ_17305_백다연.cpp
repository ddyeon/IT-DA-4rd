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
//���� ���� 3g, ū ���� 5g
//�ִ� wg�� ������ ���� �� ����., �絵�� ����?
//���� 50 40 100(3,3,5)

int n, w; //������ ������ ���� ����

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

    //ū������ �������ֵ���
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

    int fivetotal = w / 5; //5�� �� �� �ִ� �ִ밪

    for (int i = 0; i <= min(fivetotal, fivesize); i++)
    {
        temp = five[i];

        int threetotal = (w - (i * 5)) / 3; //5���� ���� 3��
        threetotal = min(threetotal, threesize);

        temp += three[threetotal];

        ans = max(ans, temp);
    }

    cout << ans << endl;

    return 0;
}