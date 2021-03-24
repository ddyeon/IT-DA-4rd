#전쟁 - 전투
#런타임 에러?
import sys
from collections import deque

def bfs(sx, sy) :
    q = deque()
    q.append([sx,sy,war[sx][sy]])
    visited[sx][sy] = 1
    cnt = 1
    while q :
        x, y, who = q.popleft()
        for k in range(4) :
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx < N and 0 <= ny < M and who == war[nx][ny] and visited[nx][ny] == 0 :
                q.append([nx, ny, war[nx][ny]])
                visited[nx][ny] = 1
                cnt += 1
    return cnt ** 2

N, M = map(int, sys.stdin.readline().split())
war = [list(sys.stdin.readline().strip()) for i in range(M)]
visited = [[0]*(N) for i in range(M)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

res = [0, 0]
for i in range(M) :
    for j in range(N) :
        if visited[i][j] == 0 :
            if war[i][j] == 'W' :
                res[0] += bfs(i,j)
            else :
                res[1] += bfs(i,j)

print(*res)