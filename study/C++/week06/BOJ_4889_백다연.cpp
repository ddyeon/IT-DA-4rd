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
stack<char> stacks;
vector <int> v;
//수정해야함..
//4889 안정적인 문자열

int main()
{
    while(true)
    {
        string s;
        cin >> s;
        int cnt = 0;

        if(s[0] == '-')
            break;
        

        for(int i = 0; i < s.size(); i++)
        {
            //비어있는데 닫힌괄호가 들어올 경우
            if(stacks.size() == 0 && s[i]== '}')
            {
                cnt++;
                s[i] = '{';
                stacks.push(s[i]);
            }
            else if(stacks.size() != 0 && s[i] == '}')
            {
                stacks.pop();
            }
            else
            {
                stacks.push(s[i]);
            }
            
        }

        cnt = cnt + stacks.size() /2;
        v.push_back(cnt);

    }

    for(int i = 1; i < v.size(); i++)
    {
        cout << i << ". " << v[i] << endl;
    }

    return 0;
}