import sys

turn=1
while True:
    cnt=0
    stack=list()
    brackets= str(sys.stdin.readline())
    if '-' in brackets:
        break
    for bracket in brackets:
        if bracket=="{":
            stack.append('{')
        elif bracket=="}":
            if stack:
                stack.pop()
            else:
                stack.append("{")
                cnt+=1
    answer=int(cnt+len(stack)/2)
    print(turn,'. ',answer, sep="" )
    turn+=1

