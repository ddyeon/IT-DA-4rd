#5624 좋은 수
#input의 범위가 5000이여서 O(N^3)은 시간 초과가 나게 된다
import sys
input=sys.stdin.readline


n=int(input())
number=list(map(int, input().split()))
candidate=set()

for i in range(n):
    for j in range(n):
        candidate.add(i+j)

for i in number:
    # for j in range()
    for j in candidate:
        if i+j in