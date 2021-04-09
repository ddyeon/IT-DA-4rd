
E, EM, M, MH, H= map(int, input().split())

cnt=0
while True:
    print(E,EM,M,MH,H)
    Eflag=Mflag=Hflag=False
    if E>0:
        E-=1
        Eflag=True
    else:
        if EM>0:
            EM-=1
            Eflag=True
    if H>0:
        H-=1
        Hflag=True
    else:
        if MH>0:
            MH-=1
            Hflag-=1
    #m을 어떻게 나누냐가 중요
    if M>0:
        M-=1
        Mflag=True
    #m이 0일경우
    else:
        if EM+E>MH+H:
            if EM>0:
                EM-=1
                Mflag=True
            elif MH>0:
                MH-=1
                Mflag=True
        elif EM+E<MH+H:
            if MH>0:
                MH-=1
                Mflag=True
            elif EM>0:
                EM-=1
                Eflag=True
        else:
            if EM>MH:
                EM-=1
                Mflag=True
            else:
                MH-=1
                Mflag=True

    if Eflag and Mflag and Hflag:
        cnt+=1
    else: break
print(cnt)
#
# E, EM, M, MH, H= map(int, input().split())
#
# start=0
# end= E+EM+M+MH+H
#
# while start>end:
#     mid=(start+end)//2
#     result=0
#     if

