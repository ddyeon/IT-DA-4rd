import sys
input= sys.stdin.readline

arr=list()
n,k=map(int, input().split())
#k개의 방을 닫아야함

for i in range(n):
    arr.append(map(int, input().split()))
dp=[[0]*2 for i in range(n)]
dp[0][0]=arr[0][1]
dp[0][1]=arr[0][0]
#dp[i][0]= 0번째를 닫았을 때 최대 가치
for i in range(1,n):
    dp[i][0]= max(dp[i-1][0]+arr[i][1], dp[])
