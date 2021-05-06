import sys

sys.setrecursionlimit(100000)

word= str(input())
cnt=0
def check(word):
    moum=['A','E','I','O','U']
    # moum_cnt=0
    # jaum_cnt=0
    # for i in word:
    #     if i == "_":
    #         moun_cnt=0
    #         jaum_cnt=0
    #     else:
    #         if i in moum:
    #             moum_cnt+=1
    #             jaum_cnt=0
    #         if i not in moum:
    #             jaum_cnt+=1
    #             moum_cnt=0
    #         if moum_cnt>=3 or jaum_cnt>=3:
    #             return False
    for i in range(len(word)-2):
        if word[i] in moum and word[i+1] in moum and word[i+2] in moum: return False
        if word[i] not in moum and word[i]!="_" and word[i+1] not in moum and word[i+1]!="_" and word[i+2] not in moum and word[i+2]!="_" : return False
    return True

def backtracking(word):
    global cnt
    if '_' not in word:
        if 'L' in word:
            cnt+=1
    else:
        if check(word):
            for i in range(65,91):
                changed=word.replace('_', chr(i),1)
                if check(changed):
                    backtracking(changed)
backtracking(word)
print(cnt)