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
//a는 업그레이드 되는 카드 
//두카드 레벨의 합만큼 골드를 받음.
int n;
vector <int> v;
int total = 0;

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
        total += a;
    }

    int max_level = 0;
    max_level = *max_element(v.begin(), v.end());

    //총 레벨값에 최고값은 한번더 더해지니간
    int ans = total + max_level*(n-2);

    cout << ans << endl;



}



