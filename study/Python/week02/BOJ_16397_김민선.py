#탈출
#https://dailyheumsi.tistory.com/47
import sys
from collections import deque

def bfs(n, t, g):
    q, visited = [n], {n}
    step = 0
    while q:
        size = len(q)
        for i in range(size):
            cur = q.pop(0)
            if cur == g:
                return step

            if cur*2 > 99999:
                next_move = [cur+1]
            else:
                m = list(str(cur*2))
                m[0] = str(int(m[0])-1) if int(m[0])-1 > 0 else str(0)
                m = int("".join(m))
                next_move = [cur+1, m]

            for j in next_move:
                if j >= 0 and j <= 99999 and j not in visited:
                    q.append(j)
                    visited.add(j)
        step += 1

        if step > t:
            break
    return "ANG"

N, T, G = map(int, sys.stdin.readline().split())
print(bfs(N, T, G))