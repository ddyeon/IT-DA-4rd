import sys
t=int(input())

def is_palin(str,cnt):
    if cnt==2: return 2
    start=0
    end=len(str)-1
    while start<end:
        if str[start]!=str[end]:return min(is_palin(str[start+1:end+1], cnt+1),is_palin(str[start:end], cnt+1))
        start+=1
        end-=1
    return cnt

for i in range(t):
    str= sys.stdin.readline().strip()
    start=0
    end= len(str)-1
    print(is_palin(str,0))