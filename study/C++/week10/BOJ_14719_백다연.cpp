#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
//14719 ����
int H,W;
//���� �������� ������ ū���� �� �����ſ� ����.

int main()
{
    cin >> H >> W;
    int arr[W];
    for(int i = 0; i < W; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    for(int i = 1; i < W-1; i++)
    {
        int left = 0;
        int right = 0;

        for(int j = 0; j < i; j++)
            left = max(left, arr[j]);
        for(int k = W-1; k > i; k--)
            right = max(right, arr[k]);

        //���� ���ϱ�
        int height = min(left,right);
        ans += max(0, height - arr[i]); //�ְ���̿��� �� �ڽ� ����
        
    }

    cout << ans << endl;



    return 0;
}

