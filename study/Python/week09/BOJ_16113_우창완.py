#16113 시그널
#생각: 1과 나머지 다른 숫자를 구분해야 될 것 같음..
# #의 개수만으로는 판단 불가

import sys
input=sys.stdin.readline

n= int(input())
arr=list(map(str,input().strip()))

row=len(arr)//5
print(row)
result=[[]*row for i in range(5)]
print(result)
for i in range(5):
    result[i].append(arr[i*row:i*row+row])

for j in range(row):
    for i in range(5):
        if result[i][j]=="#":
            if result[i+1][j]=="#"=="#"