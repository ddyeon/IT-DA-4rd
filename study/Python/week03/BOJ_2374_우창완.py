import sys

t=int(input())
arr=[]
for _ in range(t): arr.append(int(sys.stdin.readline().strip()))
flag=True
INF=int(1e9)
cnt=0
while flag:
    flag=False
    temp=arr[0]
    for i in range(1,len(arr)):
        if temp!=arr[i]:
            cnt+=1
            flag=True
            break
    minValue=index=INF
    for i in range(len(arr)):
        if minValue>arr[i]:
            minValue=arr[i]
            index=i
    arr[index]+=1
    for i in range(index-1 ,-1,-1):
        if minValue==arr[i]: arr[i]+=1
        else: break
    for i in range(index+1,len(arr)):
        if minValue==arr[i]: arr[i]+=1
        else: break
print(cnt)

