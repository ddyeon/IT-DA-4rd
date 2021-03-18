#현수막
import sys
from collections import deque

def bfs(start):
    q = deque()
    q.append(start)
    visited[start[0]][start[1]] = 1
    while q :
        x, y = q.popleft()
        for i in range(8) :
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < M and 0 <= ny < N and visited[nx][ny] == 0 :
                visited[nx][ny] = 1
                if word[nx][ny] == 1 :
                    q.append([nx, ny])

M, N = map(int, sys.stdin.readline().split())
word = [list(map(int, sys.stdin.readline().split())) for i in range(M)]
visited = [[0]*(N) for i in range(M)]

dx = [1, -1, 0, 0, 1, 1, -1, -1]
dy = [0, 0, 1, -1, -1 , 1, 1, -1]

cnt = 0
for i in range(M):
    for j in range(N):
        if visited[i][j] == 0 and word[i][j] == 1:
            cnt += 1
            bfs([i, j])

print(cnt)