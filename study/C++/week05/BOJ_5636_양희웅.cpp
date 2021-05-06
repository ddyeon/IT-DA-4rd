#include <iostream>
#include <cstring>
#include <cmath>

#define Max(x,y) ((x)>(y)?(x):(y))

using namespace std;

char prime[260] {};
int result;

int makeInt(int start, int end)
{
    int result = 0;
    int digit = end - start;

    if (digit == 0) {
        return prime[start] - '0';
    }
    for (int i = 0; i < digit; i++) {
        result += (prime[start + i] - '0') * pow(10, digit - i);
    }
    result += prime[end] - '0';

    return result;
}

bool isPrime(int num)
{
    if (num < 2) {
        return false;
    }
	int a = (int) sqrt(num);
	for (int i = 2; i <= a; i++) {
        if (num % i == 0) {
            return false;
        }
    }

	return true;
}

void solve(void)
{
    int tmp;

    result = 0;
    for (int i = 0; i < strlen(prime); i += 5) {
        for (int j = 0; j < 5; j++) {
            tmp = makeInt(i, j);
            if (isPrime(tmp)) {
                result = Max(result, tmp);
            }
        }
        for (int j = 0; j < 5; j++) {
            tmp = makeInt(i + j, i + 4);
            if (isPrime(tmp)) {
                result = Max(result, tmp);
            }
        }
    }
    cout << result << endl;
}

void input(void)
{
    while (true) {
        cin >> prime;
        if (strlen(prime)== 1 && prime[0] == '0') {
            break;
        }
        if (strlen(prime) == 1) {
            if (prime[0] - '0' == 1 || prime[0] - '0' == 2 || prime[0] - '0' == 3 || prime[0] - '0' == 5 || prime[0] - '0' == 7) {
                cout << prime[0] - '0' << endl;
                continue;
            }
            cout << 0 << endl;
            continue;
        }
        solve();
    }
}

int main(void)
{
    input();

    return 0;
}