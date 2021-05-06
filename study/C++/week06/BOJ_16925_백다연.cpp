#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;
// ���ڿ� ���� 16925
int n;
char arr[200];
vector<string> v, vs;
string p, q;

int check(string s)
{
    vector<string> t;
    set<string> ps;

    //cout << "s" << s << endl;

    for (int i = 1; i < n; i++)
    {

        string pre = s.substr(0, i);
        string suffix = s.substr(n - i, i);
        ps.insert(pre);
        t.push_back(pre);
        t.push_back(suffix);
    } //���λ� ���̻� �ֱ�

    sort(t.begin(), t.end());
    if (t == vs)
    {
        cout << s << endl;
        for (int i = 0; i < v.size(); i++)
        {
            if (ps.count(v[i]))
            {
                cout << 'P';
                ps.erase(v[i]);
            }
            else
            {
                cout << 'S';
            }
        }
        return 1;
    }
    return 0;
}

int main()
{
    cin >> n;
    string s;

    for (int i = 0; i < 2 * n - 2; i++)
    {
        cin >> s;
        v.push_back(s);
        if (s.length() == n - 1) //����� ���̵��� ���ڿ�
        {
            if (p.length() > 0)
                q = s; //baba
            else
                p = s; //abab
        }
    }

    //cout << "p" << p << endl;
    //cout << "q" << q << endl;
    
    
    vs = v;
    sort(vs.begin(), vs.end());

   

    if (p.substr(1, n - 2) == q.substr(0, n - 2)) //���ڸ� ������ �� �� �� n-2
        if (check(p + q[n - 2]))
            return 0;

    check(q + p[n - 2]); //�ٸ��� ���ʿ� �ٿ��� Ȯ��
}

//set ���� ���� ��ȯ : s.count(i);
//���Խ� ���ĵ� ��ġ�� ���Ե�.
