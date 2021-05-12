import sys
input= sys.stdin.readline

n,m=map(int, input().split())
if m>0:
    resort=list(map(int, input().split()))
else: resort=[]

INF=int(1e9)
dp=[[INF]*300 for i in range(n+1)]
dp[0][0]=0

for i in range(1,n+1):
    # coupon의 최대개수는 day*2이다.
    for coupon in range(2*i):
        if dp[i - 1][coupon] == INF: continue
        #이용불가능한 날
        if i in resort:
            dp[i][coupon]= min(dp[i][coupon],dp[i-1][coupon] )
        #이용가능한 날
        if coupon>=3:
            dp[i][coupon-3]=min(dp[i][coupon-3], dp[i-1][coupon])
        dp[i][coupon]= min(dp[i][coupon],dp[i-1][coupon]+10000)
        if i-3>=0:
            dp[i][coupon+1]= min(dp[i][coupon+1], dp[i-3][coupon]+25000)
        if i-5>=0:
            dp[i][coupon+2]= min(dp[i][coupon+2], dp[i-5][coupon]+37000)
print(min(dp[n]))
