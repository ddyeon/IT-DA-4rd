#include <iostream>
#include <cstring>

using namespace std;

int T;
char palindrome[100010] {};

void solve(void)
{ 
    int len;
    int lflag, rflag;
    int fix;
    bool fail;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> palindrome;
        len = strlen(palindrome);
        lflag = 0; rflag = 1;
        fix = 0;
        fail = false;

        for (int j = 0; j < 100000; j++) {
            if (j + lflag >= len - rflag - j) {
                break;
            }
            if (palindrome[j + lflag] == palindrome[len - rflag - j]) {
                continue;
            }
            if (palindrome[j + lflag] == palindrome[len - rflag - j - 1]) {
                rflag++;
                lflag--;
                fix++;
            }
            else if (palindrome[j + lflag + 1] == palindrome[len - rflag - j]) {
                lflag++;
                rflag--;
                fix++;
            }
            else {
                fail = true;
                break;
            }

            if (fix >= 2) {
                fail = true;
                break;
            }
        }
        if (fail) {
            cout << 2 << endl;
            continue;
        }
        if (lflag == 0 && rflag == 1) {
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
        }
    }
}

int main(void)
{
    solve();

    return 0;
}