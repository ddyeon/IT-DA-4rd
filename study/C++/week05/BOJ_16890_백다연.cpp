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
//16890
//������� ȸ���̸��� ���� ������ ���� �ռ���, ť�귯��� �ڿ�����
//�׻� ������� ���� , ȸ���̸��� N��
//�Ѿ����������..

string cube, gu;
deque <char> a,b;
string front, back;


int main()
{
    cin >> gu >> cube;

    int size = gu.length();

    sort(gu.begin(), gu.end()); //��������
    sort(cube.begin(), cube.end());
    reverse(cube.begin(), cube.end()); //cube�� ��������

    for(int i = 0; i < (size+1)/2; i++)
        a.push_back(gu[i]);
    for(int i = 0; i < size / 2; i++)
        b.push_back(cube[i]);

    for(int i = 0; i < size; i++)
    {
        //ť��
        if(i % 2)
        {
            if(a.empty()|| a.front() < b.front())
            {
                front += b.front();
                b.pop_front();
            }
            else
            {
                back += b.back();
                b.pop_back();
            }
            
        }
        //�����
        else
        {
            if (b.empty() || a.front() < b.front())
            {
                front += a.front();
                a.pop_front();
            }
            else
            {
                back += a.back();
                 a.pop_back();
            }
        }
        
    }

    reverse(back.begin(),back.end());
    cout << front << back;
    return 0;




}
