#2011 암호코드
#dp[n]=n번쨰 자리의 해석가능한 개수이고, i번째 자릿수가 0보다크다면 dp[i]+=dp[i-1]
#s[i-1:i+1]이 10~26 사이라면 dp[i]+=dp[i-2]이다.

s=str(input())
if s[0]=="0":
    print(0)
else:
    s='0'+s
    dp=[0]*(len(s)+1)
    dp[0]=dp[1]=1
    for i in range(2,len(s)):
        if int(s[i])>0: dp[i]+=dp[i-1]
        if int(s[i-1:i+1])>=10 and int(s[i-1:i+1])<=26:
            dp[i]+=dp[i-2]
    print(dp[len(s)-1]%1000000)