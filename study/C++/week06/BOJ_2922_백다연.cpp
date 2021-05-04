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
//��ſ� �ܾ� 2922
//������ �����ؼ� 3��, ������ �����ؼ� ���� x
//�ݵ�� L�� ����.
string s;

long long dfs(int moum, int jaum, int lword, int index)
{
    //�����̶� ������ 3���̻����� �������� ���Դ���
    if(moum >= 3)
        return 0;
    if(jaum >= 3)
        return 0;

    if(index == s.size()) //���ڰ� ��ä�������� l�� �ִ��� ������
    {
        if(lword == 0)
            return 0;
        else
            return 1;
        
    }

    long long cnt = 0;

    if(s[index] != '_')
    {
        if (s[index] == 'A' || s[index] == 'E' || s[index] == 'I' || s[index] == 'O' || s[index] == 'U')
            cnt = dfs(moum+1, 0, lword, index+1);
        else
        {
            if(s[index] == 'L')
                cnt = dfs(0, jaum + 1, lword + 1, index + 1);
            else
            {
                cnt = dfs(0, jaum+1, lword,index+1);
            }
            
        }
        
    }
    else
    {
        cnt += (5* dfs(moum+1, 0, lword, index+1)); //����
        cnt += (20* dfs(0,jaum+1, lword, index+1)); //����
        cnt += 1*dfs(0, jaum+1, lword+1, index+1); //L�� �ִ� ���
    }

    return cnt;
    
}


int main()
{
   
    cin >> s;
    cout << dfs(0,0,0,0);

    return 0;

}