#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
//2608 로마숫자
/* vld는 한번만, IXCM은 연속해서 세번 가능
I : 1 / V : 5 / X : 10 / L : 50 / C : 100 / D : 500 / M : 1000
작은 숫자가 큰 숫자의 왼쪽에 오는 경우
 IV = 4, IX = 9, XL = 40, XC = 90, CD = 400, CM = 900
 앞에가 같은것끼리 같이 쓸 수 없음.
 모든 수는 가능한 적은 개수의 로마 숫자로 표현 */

string a, b;
map<string, int> m;
map<string, int> mm;

int add(string s)
{
    int rst = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (i < s.size() - 1)
        {
            string twoChar = s.substr(i, 2);
            if (m.find(twoChar) != m.end())
            {
                rst += m[twoChar];

                i++;
                continue;
            }
        }
        string temp;
        temp += s[i];
        rst += m[temp];
    }

    return rst;
}

int main()
{
    cin >> a >> b;

    m.insert(make_pair("I", 1));
    m.insert(make_pair("V", 5));
    m.insert(make_pair("X", 10));
    m.insert(make_pair("L", 50));
    m.insert(make_pair("C", 100));
    m.insert(make_pair("D", 500));
    m.insert(make_pair("M", 1000));

    m.insert(make_pair("IV", 4));
    m.insert(make_pair("IX", 9));
    m.insert(make_pair("XL", 40));
    m.insert(make_pair("XC", 90));
    m.insert(make_pair("CD", 400));
    m.insert(make_pair("CM", 900));

    int total = add(a) + add(b);

    cout << total << endl;
    while (total > 0)
    {
        if (total >= 1000)
            cout << "M", total -= 1000;
        else if (total >= 900)
            cout << "CM", total -= 900;
        else if (total >= 500)
            cout << "D", total -= 500;
        else if (total >= 400)
            cout << "CD", total -= 400;
        else if (total >= 100)
            cout << "C", total -= 100;
        else if (total >= 90)
            cout << "XC", total -= 90;
        else if (total >= 50)
            cout << "L", total -= 50;
        else if (total >= 40)
            cout << "XL", total -= 40;
        else if (total >= 10)
            cout << "X", total -= 10;
        else if (total >= 9)
            cout << "IX", total -= 9;
        else if (total >= 5)
            cout << "V", total -= 5;
        else if (total >= 4)
            cout << "IV", total -= 4;
        else
            cout << "I", total -= 1;
    }
    return 0;
}