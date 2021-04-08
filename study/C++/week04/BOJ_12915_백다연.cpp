#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
int arr[6];
vector <int> v;
int cnt = 0;

//e, em, m, mh, h
int main()
{
    for(int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    
   while(true)
   {
       //easy
        if(arr[0] > 0) //e
            arr[0]--;
        else if(arr[1] > 0) //em
            arr[1]--;
        else
            break;
        
        //Áß°£
        if(arr[2] > 0)
            arr[2]--;
        else if(arr[1] >0 || arr[3] >0) {
            if(arr[1] >= arr[3])
                arr[1]--;
            else
                arr[3]--;
        }
        else
            break;

        //high
        if(arr[4] > 0)
            arr[4]--;
        else if(arr[3] > 0)
            arr[3]--;
        else
            break;

    cnt++;       
        
   }

   cout << cnt << endl;

    return 0;
}