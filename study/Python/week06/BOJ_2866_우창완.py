
import sys
place=[]
r,c= map(int, input().split())
for i in range(r):
    place.append(list(map(str, sys.stdin.readline().strip())))
start= 0
end= len(place)
answer=0
while start<=end:
    result=[]
    mid=(start+end)//2
    flag=False
    for i in range(c):
        word=""
        for j in range(mid, len(place)):
            word+= place[j][i]
        if word in result:
            flag=True
            break
        else: result.append(word)
    if flag:
        answer=mid
        end= mid-1
    else:
        start= mid+1
print(answer)
# while True:
#     place.popleft()
#     result=[]
#     for i in range(c):
#         word=""
#         for j in range(len(place)):
#             word+=place[j][i]
#         if word in result:
#             print(cnt)
#             sys.exit()
#         result.append(word)
#     place.popleft()
#     cnt+=1
# print(cnt)