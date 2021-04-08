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

int n, m;     //약속 개수와 방학 일수
//int arr[102]; //행복값 저장

//0보다 미만일때 제곱해서 출력하면 됨.
//약속한번 잡으면 0이 될때까지 약속안잡아도됨.

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m -= a + 1; //약속 수치에 + 1
    }

    if( m <= 0 ) // 우울한 날 개수 0미만이면 우울한 날 없음.
    {
        cout << 0;
        return 0; 
    }

    //우울함 최소하기위해서는 빈구간 최대한 많게
    //빈구간의 최대 길이는 약속+1
    //구간의 길이는 짧을 수록 좋다

    int q = m / (n+1);
    int r = m % (n+1);

    int ans = 0;

    for (int i = 0, j = 0; i < n + 1; i++, j++)
    {
        // 나머지보다 작으면 q+1
        int val = (j < r) ? q + 1 : q;
        
        ans += val * (val + 1) * (2 * val + 1) / 6; //제곱의합
    }

    cout << ans;
    
}