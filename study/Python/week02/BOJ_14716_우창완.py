import sys
from collections import deque


n,m= map(int , input().split())
arr=list()
visited=[[False]*(m) for _ in range(n)]

for i in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))

def bfs(x,y,visited):
    queue=deque()
    queue.append((x,y))
    visited[x][y]=True
    while queue:
        x,y=queue.popleft()
        for dx, dy in (1,0),(-1,0),(0,1),(0,-1),(1,1),(1,-1), (-1,1), (-1,-1):
            nx=x+dx
            ny=y+dy
            if 0<=nx<n and 0<=ny<m:
                if not visited[nx][ny] and arr[nx][ny]==1:
                    visited[nx][ny]=True
                    queue.append((nx,ny))

cnt=0

for i in range(n):
    for j in range(m):
        if not visited[i][j] and arr[i][j]==1:
            bfs(i,j,visited)
            cnt+=1
print(cnt)