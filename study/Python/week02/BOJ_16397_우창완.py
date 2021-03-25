import sys
from collections import deque


n,t,g= map(int, input().split())
visited=[False]*100001

def bfs(n):
    queue=deque()
    queue.append((n,0))
    while queue:
        x, cnt= queue.popleft()
        if x==g:
            print(cnt)
            return
        if cnt== t:
            continue
        nx= 2*x
        #탈출할 수 없을 경우
        if nx<100000:
            for i in (10000,1000,100,10,1):
                if nx//i!=0:
                    nx-=i
                    break
            if not visited[nx]:
                visited[nx]=True
                queue.append((nx,cnt+1))
        if not visited[x+1] and x+1<100000:
            visited[x+1]=True
            queue.append((x+1,cnt+1))
    if not visited[g]: print("ANG")

bfs(n)

