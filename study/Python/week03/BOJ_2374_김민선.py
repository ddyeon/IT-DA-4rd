#같은 수로 만들기
#?

import sys

def greedy() :
    for i in range(n) :
        print(group.index(min(group)))

n = int(sys.stdin.readline())
group = []
for i in range(n) :
    group.append(int(sys.stdin.readline()))
greedy()