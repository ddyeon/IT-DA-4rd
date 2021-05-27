#include <iostream>
#include <vector>
#include <string>
using namespace std;
string arr[5][20003];

int N;
vector<int>vec;

string str2 = "###..#####..###";
string str3 = "###..####..####";
string str4 = "#.##.####..#..#";
string str5 = "####..###..####";
string str6 = "####..####.####";
string str7 = "###..#..#..#..#";
string str8 = "####.#####.####";
string str9 = "####.####..####";
string str0 = "####.##.##.####";
string str11 = "#.##.##.##.##.#";
int main() {
	cin >> N;
	string str;
	cin >> str;
	int k = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < N / 5; j++) {
			arr[i][j] = str[k];
			k++;
		}
	}
	
	for (int j = 0; j < N / 5; j++) {
		if (arr[0][j] == "#")
		{
			string tmp;
			for (int i = 0; i < 5; i++) {
				for (int l = j; l <= j + 2; l++) {
					if (l >= N / 5)
						tmp = tmp + ".";
					else
						tmp = tmp + arr[i][l];
				}
			}
			
			if (tmp == str2)
				vec.push_back(2);
			else if (tmp == str3)
				vec.push_back(3);
			else if (tmp == str4)
				vec.push_back(4);
			else if (tmp == str5)
				vec.push_back(5);
			else if (tmp == str6)
				vec.push_back(6);
			else if (tmp == str7)
				vec.push_back(7);
			else if (tmp == str8)
				vec.push_back(8);
			else if (tmp == str9)
				vec.push_back(9);
			else if (tmp == str0)
				vec.push_back(0);
			
			else if(tmp[0]=='#'&& tmp[3] == '#'&& tmp[6] == '#'&& tmp[9] == '#'&& tmp[12] == '#'){
				vec.push_back(1);
			}
			if (vec[vec.size() - 1] == 1)
				j += 1;
			else
				j += 3;
		}
	}

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
	}

}