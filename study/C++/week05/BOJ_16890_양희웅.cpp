#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char name1[300000] {}; 
char name2[300000] {};

bool Min(int a, int b) 
{
    return a > b ? true : false;
}

void input(void)
{
    cin >> name1;
    cin >> name2;

    sort(name1, name1 + strlen(name1));
    sort(name2, name2 + strlen(name2), Min);
}

void solve(void)
{
    int idx0 = 0;
    int idx1 = 0;

    for (int i = 0; i < strlen(name1); i++) {
        if (i % 2 == 0) {
            cout << name1[idx0++];
        }
        else {
            cout << name2[idx1++];
        }
    }
    cout << endl;
}

int main(void)
{
    input();
    solve();

    return 0;
}