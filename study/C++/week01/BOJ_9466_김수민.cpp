#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
int N;
int a[100002];
bool visited[100002];
vector <int> q;
map<int, int>tmp;
int F = 0;
int anw,T;
vector<int> cycle;
void find(int a) {
	
	if ((tmp[a] == a)&&(visited[a]==false)) { //자기가 자기 뽑았을 때
		visited[a] = true;
		anw--;
		return;
	}

	else if (F == tmp[a]) { //싸이클 탈출
		cycle.push_back(a);
		for (int j = 0; j < cycle.size();j++) {
			visited[cycle[j]] = true;
		}
		anw -= cycle.size();
		cycle.clear();
		return;
	}
	else if (tmp[a] != a) { //다른사람 뽑았을 때
		cycle.push_back(a);
		F = cycle.front();
		find(tmp[a]);
	}
	else { //이미 팀 결성된 사람 뽑았을 때
		cycle.clear();
		return;
	}

}
int main()
{
	cin >> T;
	while (T) {
		memset(visited, false, sizeof(visited));
		q.clear();
		cin >> N;
		anw = N;
		for (int i = 0; i < N; i++) {
			int k;
			cin >> k;
			tmp[i + 1] = k;
		}
		for (int i = 1; i <= N; i++) {
			if (visited[i] != true) {
				F = 0;
				find(i);
			}
			
		}
		cout << anw<<"\n";
		
		T--;
	}
	

}

