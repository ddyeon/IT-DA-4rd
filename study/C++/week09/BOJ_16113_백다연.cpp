#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//16113 시그널
/*시그널은 0:.,1:#, 시그널의 길이는 항상 5의 배수
# 검은색 , . 흰색
*/
char arr[20001][6];

int n;
string s;
//0부터 9
string zero = "####.##.##.####";
string one = "#####";
string two = "###..#####..###";
string three = "###..####..####";
string four = "#.##.####..#..#";
string five = "####..###..####";
string six = "####..####.####";
string seven = "###..#..#..#..#";
string eight = "####.#####.####";
string nine = "####.####..####";

string total[10] = {zero,one,two,three,four,five,six,seven,eight,nine};
string answer = "";

int findNum(int now)
{
    string nn;
    int result = 0;
    for(int i = 1; i <=5; i++)
        for(int j = 1; j<=3; j++)
        {
            nn += arr[i][j];
        }

    //cout << nn << endl;
    for(int i = 0; i < 10; i++)
    {
        if(nn == total[i])
            result = i;
        else 
            continue;
    }
    //cout << "result" << result << endl;
    return result;
    
}



int main()
{
    cin >> n;
    cin >> s;

    int k = n /5; 
    int idx = 0; // 값저장
    for(int i = 1; i <6; i++)
    {
        for(int j = 1; j <=k; j++)
        {
            arr[i][j] = s[idx++];
        }

    }
   
    for(int i = 1; i <= k; i++)
    {
        if(arr[1][i] == '#')
        {
            if(arr[1][i+1] == '#' && arr[1][i+2] =='#') //1-3까지 #인지 검사
            {
                //1과4를 제외한 나머지 숫자
                int tt = findNum(i);
                answer += to_string(tt);
    
                i = i + 4;

                if(i > k)
                    break;
                continue;

            }
        }
        //1이나 4인경우
       
        if(arr[4][i] == '#') //1은 가운데가 #
            answer += '1';
        else
        {
            answer +='4';
            i += 4;
            if(i > k)
                break;
        }
        
    }

    cout << answer << endl;


}
