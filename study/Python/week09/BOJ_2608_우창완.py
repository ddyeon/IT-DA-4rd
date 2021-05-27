#2608 로마 숫자
# 아라비아 숫자를 더한뒤 로마숫자로 바꾸면 더 편할 것 같은데...덧셈 하드

# arab=[['I',1], ['V',5],	['X',10],	['L',50],	['C',100],	['D',500],	['M',1000]]
arab=['I'	,'V'	,'X'	,'L'	,'C'	,'D'	,'M']
roma=[1,5,10,50,100,500,1000]

number1= list(map(str, input().strip()))
number2= list(map(str, input().strip()))

result1=result2=0
for i in range(len(number1)):
    if i+1!=len(number1):
        if arab.index(number1[i])>=arab.index(number1[i+1]):
            result1+=roma[arab.index(number1[i])]
        else:
            result1-=roma[arab.index(number1[i])]
    else:result1+=roma[arab.index(number1[i])]

for i in range(len(number2)):
    if i + 1 != len(number2):
        if arab.index(number2[i]) >= arab.index(number2[i + 1]):
            result2 += roma[arab.index(number2[i])]
        elif arab.index(number2[i]) < arab.index(number2[i + 1]):
            result2 -= roma[arab.index(number2[i])]
    else:
        result2 += roma[arab.index(number2[i])]

rom_number=result1+result2
print(rom_number)

#두수의 합은 4천보다 작으니 4천이상 고려 x
arab_number=""
while True:
    if rom_number==0: break
    if rom_number>=1000:
        arab_number+="M"
        rom_number-=1000
    elif rom_number>=500:
        if rom_number>=900:
            arab_number+="CM"
            rom_number-=900
        else:
            arab_number+="D"
            rom_number-=500
    elif rom_number>=100:
        if rom_number>=400:
            arab_number+="CD"
            rom_number-=400
        else:
            arab_number+="C"
            rom_number-=100
    elif rom_number>=50:
        if rom_number>=90:
            arab_number+="XC"
            rom_number-=90
        else:
            arab_number+="L"
            rom_number-=50
    elif rom_number>=10:
        if rom_number>=40:
            arab_number+="XL"
            rom_number-=40
        else:
            arab_number+="X"
            rom_number-=10
    elif rom_number>=5:
        if rom_number>=9:
            arab_number+="IX"
            rom_number-=9
        else:
            arab_number+="V"
            rom_number-=5
    elif rom_number >= 1:
        if rom_number >= 4:
            arab_number += "IV"
            rom_number -= 4
        else:
            arab_number += "I"
            rom_number -= 1
print(arab_number)