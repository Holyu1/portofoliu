def pct1(n,a):
    for i in range(0,n):
        for j in range(0,n):
            if a[i][j] == 0:
                return 0
    return 1
def pct2(n,a):
    for i in range(0,n-1):
            if a[n-1][0] == 0 or a[0][n-1]==0:
                return 0
            if a[i][i+1]==0 or a[i+1][i]==0:
                return 0
    for i in range(0,n):
        for j in range(0,n):
            if j!= i+1 and i!=j+1:
                if i!=1 or j!=n-1 and i!=n-1 or j!=1:
                    if a[i][j]==1:
                        return 0
    return 1
def pct3(n,a):
    for i in range(0,n):
        ok=0
        for j in range(0,n):
            if a[i][j]==1 and a[j][i]==1:
                if i != j:
                    ok=1
                else:
                    return 0
            elif a[i][j]==1:
                return 0
        if ok == 0:
            return 0
    return 1
n=int(input())
A=[]
for i in range(0,n):
    row=[]
    for j in range(0,n):
        row.append(int(input()))
    A.append(row)
if pct1(n,A) == 1:
    print("PCT1: DA")
else:
    print("PCT1: NU")
if pct2(n,A) ==1:
    print("PCT2: DA")
else:
    print("PCT2: NU")
if pct3(n,A) ==1:
    print("PCT3: DA")
else:
    print("PCT3: NU")