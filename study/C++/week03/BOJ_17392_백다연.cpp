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

int n, m;     //��� ������ ���� �ϼ�
//int arr[102]; //�ູ�� ����

//0���� �̸��϶� �����ؼ� ����ϸ� ��.
//����ѹ� ������ 0�� �ɶ����� ��Ӿ���Ƶ���.

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m -= a + 1; //��� ��ġ�� + 1
    }

    if( m <= 0 ) // ����� �� ���� 0�̸��̸� ����� �� ����.
    {
        cout << 0;
        return 0; 
    }

    //����� �ּ��ϱ����ؼ��� �󱸰� �ִ��� ����
    //�󱸰��� �ִ� ���̴� ���+1
    //������ ���̴� ª�� ���� ����

    int q = m / (n+1);
    int r = m % (n+1);

    int ans = 0;

    for (int i = 0, j = 0; i < n + 1; i++, j++)
    {
        // ���������� ������ q+1
        int val = (j < r) ? q + 1 : q;
        
        ans += val * (val + 1) * (2 * val + 1) / 6; //��������
    }

    cout << ans;
    
}