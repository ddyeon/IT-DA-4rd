#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;
//문자열 잘라내기 2866
int r,c;
char arr[1001][1001];
map <string, int> m;

int main()
{
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    int start = 0;
    int end = r-1;
    int mid;
    bool check = false;

    while(start <= end)
    {
        mid = (start + end) / 2;
        bool visit = true;
        for(int i = 0; i < c; i++)
        {
            string munja = "";
            for(int j = mid; j < r; j++)
            {
                munja += arr[j][i];
            }
            if(m[munja]) //중복 문자 존재
            {
                visit = false;
                break;
            }
            m[munja] +=1; //존재 안하면 +1

        }

        if(!visit)
            end = mid -1;
        else
        {
            start = mid + 1;
        }

        check = visit;
        m.clear();
    }

    if(!check)
        cout << mid-1 << endl;
    else
        cout << mid << endl;
    
}
ㅈ