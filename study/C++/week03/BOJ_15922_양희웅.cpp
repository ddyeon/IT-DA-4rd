#include <iostream>

using namespace std;

int N;
int front = -1000000000;
int rear = -1000000000;
int result;

void solve(void)
{
    int x, y;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        if (front <= x && y <= rear) {
            continue;
        }
        else if (front <= x && x <= rear && rear < y) {
            rear = y;
        }
        else if (rear < x) {
            result += (rear - front);
            front = x;
            rear = y;
        }
    }
    result += (rear - front);
    cout << result << endl;
}

int main(void)
{
    solve();

    return 0;
}