#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
//12842 Ƣ��Һ��� 
//��������� ����
/* m���� �־��� ������ Ƣ��Һ��� 1���� �Դµ�
�ɸ��� �ð� ���� ����
������ Ƣ��Һ��� ����� ��� ��ȣ  */
int n, s;
int arr[100005];
int main()
{
    cin >> n >> s; //Ƣ�� ������ ���� ����
    int m; //�����
    cin >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    int eat = n-s; //���� �Һ��� ����

    for(int time = 0; time < 1000000; time++)
    {
        for(int i = 0; i < m; i++)
            if(time % arr[i] == 0) {
                sum++;
                if(sum >= eat)
                    {
                        cout << i+1 << endl;
                        return 0;
                    }
            }


    }

}
