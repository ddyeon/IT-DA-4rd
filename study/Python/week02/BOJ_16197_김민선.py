#두 동전
import sys
from collections import deque

def bfs(start_x, start_y) :
    q = deque()
    q.append([start_x,start_y])
    visited[start_x][start_y] = 1
    cnt = 1
    while q:
        x, y = q.popleft()
        for i in range(4) :
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < N and 0 <= ny < M and board[nx][ny] == '.' and visited[nx][ny] == 0 :
                cnt += 1
                q.append([nx, ny])
                visited[nx][ny] = 1
    return cnt


N, M = map(int, sys.stdin.readline().split())
board = [list(sys.stdin.readline().strip()) for i in range(N)]
visited = [[0]*(M) for i in range(N)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
coin = []
for i in range(N) :
    for j in range(M) :
        if board[i][j] == 'o' :
            coin.append(bfs(i,j))

if min(coin) > 10 : print(-1)
else : print(min(coin))