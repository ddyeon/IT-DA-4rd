import sys
n=int(input())
result=0
pre_start, pre_end=map(int,sys.stdin.readline().split())
for i in range(n-1):
    start, end= map(int, sys.stdin.readline().split())
    if start>pre_end:
        result+= pre_end-pre_start
        pre_start=start
        pre_end=end
    else:
        if end>pre_end: pre_end=end
result+= pre_end-pre_start
print(result)