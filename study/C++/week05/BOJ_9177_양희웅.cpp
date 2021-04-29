#include <iostream>
#include <cstring>

using namespace std;

/*
    cat tree tcraete
    cata tree catrteea
    cat tree cttaree
    cat cat  ccatta
*/

int N;
char word[3][400] {};

void solve(int seq)
{
    int idx0 = 0;
    int idx1 = 0;

    for (int i = 0; i < strlen(word[2]); i++) {
        if ((word[2][i] == word[0][idx0]) && (word[2][i] == word[0][idx1])) {
            
            continue;
        }
        if (word[2][i] == word[0][idx0]) {
            idx0++;
        }
        else if (word[2][i] == word[1][idx1]) {
            idx1++;
        }
        else {
            cout << "Data set " << seq + 1 << ": no" << endl;
        }
    }
    cout << "Data set " << seq + 1 << ": yes" << endl;
}

void input(void)
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> word[0];
        cin >> word[1];
        cin >> word[2];
        solve(i);
    }
}

int main(void)
{
    input();

    return 0;
}