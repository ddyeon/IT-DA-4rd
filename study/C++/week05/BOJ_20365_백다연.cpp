#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>

//��α�2
//https://www.acmicpc.net/problem/20365
//���������ϴ� ������ ĥ�ϴ¹��� �ּҰ�

using namespace std;
int n;
string s;
int b,r;



int main()
{
   
   cin >> n >> s; //BBRBRBBR

   if(s[0] == 'B') b++;
   else r++;
    
    for(int i = 1; i< n; i++)
    {
        if(s[i] == 'B' && s[i-1] == 'R') // ����� b�ε� �������٤Ѥ���
            b++;
        else if(s[i] == 'R' && s[i-1] == 'B')
            r++;
    }

    if(r>=b)
        cout << b+1; //��ó�� ĥ�ϰ� ����
    else
    {
        cout << r+1;
    }
    

   return 0;
}
