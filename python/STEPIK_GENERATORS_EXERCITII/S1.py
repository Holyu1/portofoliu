import math
def pct2(n,A,x):
    print("PCT 3: ")
    for i in range(n):
        for j in range(n):
            if A[i][j]<x:
                print((i,j))

def pct3 (n,A):
    max = -1
    for i in range(n):
        for j in range(n):
            if A[i][j]>max:
                max=A[i][j]
                pi=i
                pj=j
    return (pi,pj)
S=[]
A=[]
n=int(input())
x=int(input())
for i in range(n):
    row=[]
    for j in range(2):
        row.append(int(input())) #S.append([i,i,i])
    S.append(row)
for i in range(n):
    row=[]
    for j in range(n):
        row.append(math.sqrt((S[i][0] - S[j][0]) ** 2 + (S[i][1] - S[j][1]) ** 2))
    A.append(row)
pct2(n,A,x)
print("PCT 4: ")
print(pct3(n,A))