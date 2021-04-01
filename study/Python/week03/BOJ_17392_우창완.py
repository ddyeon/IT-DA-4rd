#17392 우울한 방학
#결국 연속되는 날이 최소가 되어야한다.
n,m=map(int, input().split())

arr=list(map(int,input().split()))

result=ans=0
for val in arr:
    result+=val+1
#약속이 없는 날들
temp=m-result
#n+1개의 구간이 생긴다. interval=n+1
interval=n+1
#구간에 포함된 개수
number= temp//interval
res=temp%interval
ans= (res)*(number+1)**2+(interval-res)*(number)**2
print(ans)

