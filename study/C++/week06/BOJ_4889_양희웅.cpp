#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

char str[2010] {};

void solve(int cnt)
{
    int result = 0;
    stack<char> s;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '}') {
            if (s.size() == 0) {
                result++;
                s.push('{');
            }
            else if (s.top() == '{') {
                s.pop();
            }
        }
        else { // str[i] == '{'
            if (i == strlen(str) - 1) {
                if (s.top() == '{') {
                    s.pop();
                }
                result++;
                break;
            }
            s.push('{');
        }
    }

    if (s.size() != 0) {
        result += s.size() / 2;
    }

    cout << cnt << ". " << result << endl;
}

void input(void)
{
    int cnt = 0;

    while (true) {
        cin >> str;
        if (str[0] == '-') {
            break;
        }
        solve(++cnt);
    }
}

int main(void)
{
    input();

    return 0;
}