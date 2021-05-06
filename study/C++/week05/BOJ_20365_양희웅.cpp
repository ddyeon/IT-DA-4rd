#include <iostream>
#include <cstring>

#define Min(x,y,z) (x<y?x:((y<z)?y:z))

using namespace std;

int N;
char question[500000] {};

void solve(void)
{
    int count[3] = {1, 1, 1};
    char start = question[0];
    char changeB = 'B';
    char changeR = 'R';

    for (int i = 0; i < N; i++) {
        if (start != question[i]) {
            count[0]++;
            start = question[i];
        }
        if (question[i] == 'R') {
            if (changeB == 'B') {
                count[1]++;
                changeB = 'R';
            }
            changeR = 'R';
        }
        else {
            if (changeR == 'R') {
                count[2]++;
                changeR = 'B';
            }
            changeB = 'B';
        }
    }
    cout << Min(count[0], count[1], count[2]) << endl;
}

void input(void)
{
    cin >> N;
    cin >> question;
}

int main(void)
{
    input();
    solve();

    return 0;
}