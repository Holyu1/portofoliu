def S6(n,m,a):
    oku=1
    okl=1
    for i in range (n):
        for j in range (m):
            if i < j:
                if a[i][j]==1:
                    oku=0
            if i>j:
                if a[i][j]==1:
                    okl=0
    if oku==1 and okl==1:
        print("The matrix is upper and lower triangular")
    elif oku == 1:
        print("The matrix is upper triangular")
    elif okl==1:
        print("The matrix is lower triangular")
    return 0
A=[]
S=[]
n=int(input())
m=int(input())
for i in range(n):
    row=[]
    for j in range(m):
        row.append(int(input()))
    A.append(row)
S6(n,m,A)