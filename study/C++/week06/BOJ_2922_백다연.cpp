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
//즐거운 단어 2922
//모음이 연속해서 3번, 자음이 연속해서 세번 x
//반드시 L를 포함.
string s;

long long dfs(int moum, int jaum, int lword, int index)
{
    //모음이랑 자음이 3번이상으로 연속으로 나왔는지
    if(moum >= 3)
        return 0;
    if(jaum >= 3)
        return 0;

    if(index == s.size()) //글자가 다채워졌을때 l이 있는지 없는지
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
        cnt += (5* dfs(moum+1, 0, lword, index+1)); //모음
        cnt += (20* dfs(0,jaum+1, lword, index+1)); //자음
        cnt += 1*dfs(0, jaum+1, lword+1, index+1); //L을 넣는 경우
    }

    return cnt;
    
}


int main()
{
   
    cin >> s;
    cout << dfs(0,0,0,0);

    return 0;

}