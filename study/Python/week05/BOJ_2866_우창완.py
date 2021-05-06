from collections import deque
import sys

r,c= map(int, input().split())

place=deque()
for i in range(r):
    place.append(list(map(str, sys.stdin.readline().strip())))
cnt=0

while True:
    place.popleft()
    result=[]
    for i in range(c):
        word=""
        for j in range(r-cnt-1):
            word+=place[j][i]
        if word in result:
            print(cnt)
            sys.exit()
        result.append(word)
    place.popleft()
    cnt+=1
print(cnt)