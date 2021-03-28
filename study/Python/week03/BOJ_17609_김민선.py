#회문
#https://kkk4872.tistory.com/143 참고

import sys

def check(arr, left, right) :
    while (left < right) :
        if (arr[left] == arr[right]) :
            left += 1
            right -= 1
        else :
            return False
    return True

def greedy(arr) :
    left = 0; right = len(arr)-1
    while (left < right) :
        if (arr[left] == arr[right]) : 
            left += 1
            right -= 1
        else :
            is_left = check(arr, left+1, right)
            is_right = check(arr, left, right-1)
            if is_left == True or is_right == True :
                return 1
            else :
                return 2
    return 0

T = int(sys.stdin.readline())
for i in range(T) :
    print(greedy(sys.stdin.readline().strip()))