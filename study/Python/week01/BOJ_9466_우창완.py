import sys
sys.setrecursionlimit(10000)
n,m,h=map(int, input().split())

milk=list()
graph=list()

for i in range(n):
    graph.append(list(map(int,sys.stdin.readline().split())))

answer=0


def backtracking(x, y,health,cnt):
    global answer
    # 집으로 돌아갈수 있다면 answer과 비교

    for mx,my in milk:
        if graph[mx][my]==2:
            dist = abs(mx - x) + abs(my - y)
            if dist<=health:
                graph[mx][my] = 0
                backtracking(mx,my,health+h-dist,cnt+1)
                graph[mx][my]=2

    if abs(hx - x) + abs(hy - y) <= health:
        answer = max(answer, cnt)


for i in range(n):
    for j in range(n):
        if graph[i][j]==1:
            hx,hy= i,j
        elif graph[i][j]==2:
            milk.append((i,j))

backtracking(hx,hy,m,0)
print(answer)



