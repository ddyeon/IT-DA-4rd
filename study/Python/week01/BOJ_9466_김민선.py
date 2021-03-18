#텀 프로젝트
import sys
from collections import deque

def bfs(arr) :
    res = []; rest = 0
    for i in range(1,n+1) :
        if arr[i] == i :
            visited[i] = 1
            res.append(i)
    if len(res) < len(arr)-1 :
        q = deque()
        q.append(1)
        while q and q[0] <= n:
            num = q.popleft()
            if arr[num] in res and visited[num] == -1:
                visited[num] = 1
            elif 0 < num <= n and visited[num] == -1 :
                visited[num] = 1
                q.append(arr[num])
                res.append(num)
            q.append(num+1)
        rest = len(arr)-1-len(res)
    return rest


T = int(sys.stdin.readline())
for i in range(T) :
    n = int(sys.stdin.readline())
    project = list(map(int,sys.stdin.readline().split()))
    project.insert(0, 0)
    visited = [-1]*(n+1)
    print(bfs(project))