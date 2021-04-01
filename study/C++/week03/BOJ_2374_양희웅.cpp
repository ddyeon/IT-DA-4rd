#include <iostream>

#define Max(x,y)    ((x) > (y) ? 1 : 0)

using namespace std;

int n;
int len = 1;
int num[1010] {};
int result;

int find_big_index(int arr[], int l, int r)
{
    int big = l;
    for (int i = l; i < r - l + 1; i++) {
        if (Max(arr[i], arr[big])) {
            big = i;
        }
    }
    return big;
}

void make_same(int arr[], int l, int r, bool right)
{
    if (r == l) {
        return;
    }
    if (r - l + 1 == 2) {
        if (right) {
            result += arr[r] - arr[l];
        }
        else {
            result += arr[l] - arr[r];
        }
    }
    else {
        int big_index; 
        if (right) {
            big_index = find_big_index(arr, l, r - 1);
            result += arr[r] - arr[big_index];
            make_same(arr, l, big_index, true);
            make_same(arr, big_index, r - 1, false);
        }
        else {
            big_index = find_big_index(arr, l + 1, r);
            result += arr[l] - arr[big_index];
            make_same(arr, l + 1, big_index, true);
            make_same(arr, big_index, r, false);
        }
    }
}

void solve(void)
{
    int tmp;
    int big_index;

    cin >> n;
    cin >> num[0];
    for (int i = 1; i < n; i++) {
        cin >> tmp;
        if (tmp == num[len - 1]) {
            continue;
        }
        num[len++] = tmp;
    }

    big_index = find_big_index(num, 0, len -1);
    make_same(num, 0, big_index, true);
    make_same(num, big_index, len - 1, false);

    cout << result << endl;
}

int main(void)
{
    solve();

    return 0;
}