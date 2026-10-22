def S4(m,n,a,k,h):
    for i in range(n):
        A[i].pop(k-1)
    A.pop(h-1)
A=[]
n=int(input())
m=int(input())
k=int(input())
h=int(input())
for i in range(n):
    row=[]
    for j in range(m):
        row.append(int(input()))
    A.append(row)
S4(m,n,A,k,h)
print(A)