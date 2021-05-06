import sys

n=int(input())
words=[]
for i in range(2*n-2):
    words.append(str(input()))

can={}

for a in words:
    for b in words:
        result=a+b
        if len(result)==n:
            if result in can.keys():
                can[result]=can[result]+1
            else:
                can[result]=1
# for key,value in can.

min=0
answer=""
for key, value in can.items():
    if min<value:
        min=value
        answer=key
print(answer)
# print(can[1])
# if can[0][1:n]==can[1][0:n-1]
