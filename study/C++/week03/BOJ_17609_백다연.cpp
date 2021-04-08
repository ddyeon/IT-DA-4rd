#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>
//�����ؾ���.

using namespace std;
vector<string> v;

int n;
string s;
int leng = 0;

bool is_palindrome()
{
    int left = 0;
    int right = leng-1;
    
    while(left <= right)
    {
        if (s[left++] != s[right--]) //Ʋ�� ������ �ִٸ� 
            return false;
    }
    return true;


}

bool make_palindrome()
{
    int left = 0;
    int right = leng -1;
    int mid = right /2;
    int deletecnt = 1;
    bool check = false;

    for(int i = 0; i < mid; i++)
    {

        if(s[left + i] == s[right - i])
            continue;
        else //���� ���� ��� ���� �ؼ� Ȯ��
        {
            if (deletecnt == 1)
            {
                // ������ ����
                if(s[left + i + 1] == s[right -i])
                {
                    check = true;
                    left = left + 1;
                    deletecnt--;
                }
                
                else if(s[left +i] == s[right - i - 1])
                {
                    check = true;
                    right = right -1;
                    deletecnt--;
                }
                else
                    return false;
    
            }
            else //���� ���� ���� ���̻� ���� �� ����.
                check = false;
               
        }
        
    }

    return check;

}

int check_answer()
{
    if(is_palindrome())
        return 0;
    else if(make_palindrome())
        return 1;
    else
        return 2;
    
}


int main()
{
    cin >> n;
    int ans = 0;
    while(n--)
    {
        cin >> s;
        leng = s.size();

        ans = check_answer();
        cout << ans << endl;

    }

    return 0;
}