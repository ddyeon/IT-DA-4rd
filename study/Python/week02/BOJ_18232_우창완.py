import sys
from collections import deque

n,m= map(int,input().split())
s,e=map(int, input().split())

visited=[False]*(n+1)
port= [[] for _ in range(n+1)]
for i in range(m):
    a,b= map(int, sys.stdin.readline().split())
    port[a].append(b)
    port[b].append(a)

def bfs(x):
    queue=deque()
    queue.append((x,0))
    visited[x]=True

    while queue:
        x, cnt= queue.popleft()
        if x==e:
            print(cnt)
            return
        for dx in (x-1),(x+1):
            if 0<=dx<=n and not visited[dx]:
                visited[dx]=True
                queue.append((dx,cnt+1))
        # if port[x]!= 0 and not visited[port[x]]:
        #     queue.append((port[x], cnt+1))
        #     visited[port[x]]
        while port[x]:
            nx= port[x].pop()
            if not visited[nx]:
               queue.append((nx,cnt+1))

bfs(s)