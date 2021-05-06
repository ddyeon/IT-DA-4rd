	#include <iostream>
	#include <vector>
	#include <algorithm>
	#include <string>
	using namespace std;
	int T,a,b;
	bool q;
	string str1, str2, str3;
	vector<int>com;

	void put() {
		vector<char>vec(400);
		for (int i = 0; i < com.size(); i++)
			vec[com[i]] = str1[i];
	
		int k = 0;
		for (int i = 0; i < a + b; i++) {
			if (vec[i] == NULL)
			{
				vec[i] = str2[k];
				k++;
			}
		}

		for (int i = 0; i < a + b; i++) {
			if (str3[i] != vec[i])
				return;
		
		}

		q = true;
		return;
	
	}

	void simulate(int lastidx) {

		if (q)
			return;

		if (com.size() == a) {
		
			put();
			return;
		}
	

		for (int i = lastidx+1; i < a + b; i++) {
			com.push_back(i);
			simulate(i);
			com.pop_back();
		}
	}

	int main() {
		cin >> T;
		T;
		int i = 1;
		while (T--) {
			q = false;
			com.clear();
			cin >> str1 >> str2 >> str3;
			a = str1.size();
			b = str2.size();
			if (str3.size() != a + b) {
				continue;
			}
			simulate(-1);
			if (q)
				cout << "Data set " << i++ << ": yes" << endl;
			else
				cout << "Data set " << i++ << ": no" << endl;
		}
	
	}