def sum_max(n,m,a):
    max=-1
    for i in range(n):
        sum = 0
        for j in range(m):
            sum = sum + a[i][j]
        if sum > max:
            max=sum
            poz=i
    return poz
A=[]
n=int(input())
m=int(input())
for i in range(n):
    row=[]
    for j in range(m):
        row.append(int(input()))
    A.append(row)
print(sum_max(n,m,A))