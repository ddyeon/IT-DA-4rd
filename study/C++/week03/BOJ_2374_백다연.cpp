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

int main()
{
    int n;
    cin >> n;

    vector<int> s;

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (s.empty() || s.back() > x)
        {
            s.push_back(x);
            continue;
        }

        ans += x - s.back(); //크기만큼 더해주고

        while (!s.empty() && s.back() <= x) 
            s.pop_back();

        s.push_back(x);
    }

    ans += s[0] - s.back();

    cout << ans << endl;

    return 0;
}