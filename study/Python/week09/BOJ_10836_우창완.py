# import sys
# input=sys.stdin.readline
#
# m,n=map(int, input().split())
# bee= [[1]*m for i in range(m)]
# size=[]
# for i in range(n):
#     size.append(list(map(int, input().split())))
#
# for i in range(n):
#     left=0
#     bottom=m-1
#     if bottom>=size[i][0]:
#         bottom-=size[i][0]
#     else:
#         bottom=0
#         left+=(size[i][0]-(m-1))
#
#     for j in range(size[i][1]):
#         bee[bottom][left]+=1
#         if bottom != 0: bottom -= 1
#         else: left += 1
#     for j in range(size[i][2]):
#         bee[bottom][left]+=2
#         if bottom != 0: bottom -= 1
#         else: left += 1
#
# print(*bee[0])
# for i in range(1,m):
#     for j in range(m):
#         if j!=0: bee[i][j] += (bee[i - 1][j]-1)
#         print(bee[i][j], end=" ")
#     print()
import sys

M,N=map(int,input().split())

L=[[1 for j in range(M)] for i in range(M)]
day=[0 for i in range(2*M-1)]



for _ in range(N):
    z,o,t=map(int,sys.stdin.readline().rstrip().split())
    for i in range(z,z+o):
        day[i]+=1
    for i in range(z+o,2*M-1):
        day[i]+=2

#왼쪽꺼
for i in range(M-1,-1,-1):
    L[i][0]+=day[M-1-i]
#위쪽
for j in range(1,M):
    L[0][j]+=day[M-1+j]

#1열 이후라인
for j in range(1,M):
    for i in range(1,M):
        L[i][j]=L[i-1][j]

for i in L:
    print(*i)