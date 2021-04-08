#아우으 우아으이야!!
#https://kimcodingvv.github.io/BOJ-15922/

import sys
INF = sys.maxsize

N = int(sys.stdin.readline())
res = 0
left = -INF; right = -INF

for i in range(N) :
    x, y = map(int, sys.stdin.readline().split())
    if x > right :
        res += (right - left)
        left = x; right = y
    else :
        right = max(right, y)

res += (right - left)
print(res)