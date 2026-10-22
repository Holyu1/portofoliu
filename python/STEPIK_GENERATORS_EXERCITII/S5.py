def S5(n,m,a,s):
    max=a[0][0]
    min=a[0][0]
    for i in range(n):
        for j in range(m):
            if a[i][j]>max:
                max=a[i][j]
            if a[i][j]<min:
                min=a[i][j]
    for i in range(n):
        for j in range(m):
            ok = 0
            for q in range(m):
                if a[i][q]==max:
                    ok=1
                    break
            if ok == 1:
                for q in range (n):
                    if a[q][j]==min:
                        S.append((i,j))
                        break
A=[]
S=[]
n=int(input())
m=int(input())
for i in range(n):
    row=[]
    for j in range(m):
        row.append(int(input()))
    A.append(row)
S5(n,m,A,S)
print(S)