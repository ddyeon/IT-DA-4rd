import sys
from collections import deque

n=int(input())
k=int(input())
dx=[0,1,0,-1]
dy=[1,0,-1,0]
queue=deque()

graph=[[0]*(n+1) for _ in range(n+1)]
#사과
for i in range(k):
    a,b= map(int, sys.stdin.readline().split())
    graph[a][b]=1
l=int(input())

direction=deque()
for i in range(l):
    x,c =sys.stdin.readline().split()
    direction.append((x,c))

x=y=1
time=cnt= 0
snake=1
point=0
queue.append((1,1))

while True:
    x+=dx[point]
    y+=dy[point]
    if x<=0 or x>n or y<=0 or y>n: break
    # 몸통끼리 부딪힌다면 break처리
    if graph[x][y]==-1:
        # print(graph)
        break
    #사과가 있다면
    if graph[x][y]==1:
        queue.append((x,y))
    elif graph[x][y]==0:
        queue.append((x,y))
        backx,backy= queue.popleft()
        graph[backx][backy]=0
    graph[x][y] = -1

    time+=1
    if direction:
        if int(direction[0][0])==time:
            if direction[0][1]=='D':
                point = (point + 1) % 4
            if direction[0][1]=='L':
                point=(point-1)%4
            direction.popleft()

print(time+1)
