import math
z=[]
def ok(k,y):
    for i in range(k):
        if z[i] == z[k]:
            return 0
    return 1
def sol(k,y):
    if k == len(y)-1:
        return 1
    return 0
def back(y,k):
        for i in range(len(y)):
            z[k]=y[i]
            if ok(k,y)==1:
                if sol(k,y) == 1:
                    num=0
                    for i in range(len(z)):
                        num=num*10+int(z[i])
                    print(num)
                else:
                    back(y,k+1)
x = input()
for i in range(len(x)):
    z.append(0)
back(x,0)
