#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
string str;
vector<int>vec;
int main() {
	while (cin >> str) {
		
		if (str[0] == '-')
			break;

		else {
			int result = 0;
			stack<char>st;
			for (int i = 0; i < str.size(); i++) {
				if (st.size() == 0 || str[i] == '{')
					st.push(str[i]);
				else if (str[i] == '}') {
					if (st.top() == '}')
						st.push('}');
					else
						st.pop();
				}

			}

			while (!st.empty()) {
				char a = st.top();
				st.pop();
				char b = st.top();
				st.pop();
				if (a == b)
					result++;
				else
					result += 2;
			}
			vec.push_back(result);
		}
	}
	for (int i = 0; i < vec.size(); i++)
		cout << i+1<<". "<< vec[i] << endl;
}