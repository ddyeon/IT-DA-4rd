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
//a�� ���׷��̵� �Ǵ� ī�� 
//��ī�� ������ �ո�ŭ ��带 ����.
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

    //�� �������� �ְ��� �ѹ��� �������ϰ�
    int ans = total + max_level*(n-2);

    cout << ans << endl;



}



