from collections import deque
import sys

n,m = map(int, input().split())
place=list()

for i in range(n):
    place.append(list(map(str, sys.stdin.readline().strip())))

position=list()
def bfs():
    ax,ay=position.pop()
    bx,by=position.pop()
    queue=deque()
    queue.append((ax,ay,0))
    queue.append((bx,by))
    while queue:
        ax, ay,cnt=queue.popleft()
        bx, by= queue.popleft()
        if cnt >=10:
            continue
        for dx,dy in (1,0), (-1,0),(0,1),(0,-1):
            aflag = bflag = False
            nax= ax+dx
            nay= ay+dy
            nbx= bx+dx
            nby= by+dy
            if 0<=nax<n and 0<=nay<m:
                if place[nax][nay]=="#":
                    queue.append((ax,ay,cnt+1))
                else:
                    queue.append((nax,nay,cnt+1))
                aflag=True
            if 0<=nbx<n and 0<=nby<m:
                if place[nbx][nby]=="#":
                    queue.append((bx,by))
                else:
                    queue.append((nbx,nby))
                bflag=True
            if aflag and not bflag:
                print(cnt+1)
                return
            if not aflag and bflag:
                print(cnt+1)
                return
    print(-1)
for i in range(n):
    for j in range(m):
        if place[i][j]=="o":
            position.append((i,j))

bfs()

