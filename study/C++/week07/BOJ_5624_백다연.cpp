#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
//5624 ���� ��

using namespace std;

int arr[5001];
bool visit[400001];//400000�����ϸ� 50���ο��� Ʋ��..

int main()
{
    int n; 
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int cnt = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j=0; j < i; j++)
        {
            //�ΰ������� ���� �����ϴ� ��� ���� ���� �� �� ����.
            if(visit[arr[i]-arr[j] + 200000]) //�ִ����� 2000000
            {
                cnt++; 
                break;
            }
        }
        
        for(int k =0; k <=i; k++)
            visit[arr[i]+arr[k] + 200000] = true;
    }

    cout << cnt << endl;

    return 0;
}