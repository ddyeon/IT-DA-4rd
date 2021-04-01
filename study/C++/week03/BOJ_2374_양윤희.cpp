#include<iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
long long int sum;
long long int arr[1000001];
vector<long long int> v;
int main(void) {
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		if (v.empty())v.push_back(arr[i]);
		else {
			while (v.back() < arr[i]) {
				int tmp = v.back();
				v.pop_back();
				if (v.empty() || v.front() > arr[i]) {
					sum += arr[i] - tmp;
					break;
				}
				else {
					sum += v.back() - tmp;
				}
			}
			v.push_back(arr[i]);
		}
	}
	if (v.size() > 1)sum += v.front() - v.back();
	cout << sum;
}
