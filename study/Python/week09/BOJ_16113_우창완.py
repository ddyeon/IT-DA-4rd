#16113 시그널
#생각: 1과 나머지 다른 숫자를 구분해야 될 것 같음.

import sys
input=sys.stdin.readline

n= int(input())
arr=list(map(str,input().strip()))

row=len(arr)//5
print(row)

for i in range(row):
