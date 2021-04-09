n=int(input())
arr=list(map(int,input().split()))

if n==0: print(0)
else:print(arr[0] if n==1 else sum(arr)+ max(arr)*(n-2))


