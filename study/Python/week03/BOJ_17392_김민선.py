#우울한 방학
import sys

def calc(num) :
    res = 0
    for i in range(num+1) :
        res += num * 2
    return res

N, M = map(int, sys.stdin.readline().split())
vac = list(map(int, sys.stdin.readline().split()))
apts = list()

for i in range(N) :
    for j in range(vac[i], -1, -1) :
        apts.append(j)

if len(apts) < M :
    if M-len(apts) <= N :
        print(M-len(apts))
    else :
        print(N+calc(M-len(apts)-(N+1)))
else :
    print(0)