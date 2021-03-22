import sys
from collections import deque

w=b=0

m,n=map(int,input().split())
visited= [[False]*m for _ in range(n)]
place=list()
for i in range(n):
    place.append(list(map(str, sys.stdin.readline().strip())))

def bfs(x,y,color):
    visited[x][y]=True
    queue=deque()
    marin=list()
    queue.append((x,y,1))
    while queue:
        x,y,result= queue.popleft()
        for dx,dy in (1,0),(-1,0),(0,1),(0,-1):
            nx= dx+x
            ny= dy+y
            if 0<=nx<n and 0<=ny<m:
                if not visited[nx][ny] and place[nx][ny]==color:
                    marin.append((nx,ny))
                    visited[nx][ny]=True
                    queue.append((nx,ny, result+1))
    return len(marin)+1


for i in range(n):
    for j in range(m):
        if not visited[i][j]:
            if place[i][j]=="W":
                result=bfs(i, j,"W")
                w+=result*result
            if place[i][j]=="B":
                result = bfs(i, j, "B")
                b+=result*result
print(w, b)