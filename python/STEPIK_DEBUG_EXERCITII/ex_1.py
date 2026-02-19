def bs(x,l):
    low=0
    high=len(l)-1
    while low<=high:
        mid=(low+high)//2
        if l[mid]==x:
            return mid
        elif l[mid]>x:
            high=mid-1
        else:
            low=mid+1
    return -1
l1=[]
l2=[]
x=int(input())
l3=input().split()
for i in range (len(l3)):
    l1.append(int(l3[i]))
for i in range (len(l1)):
    l3[i]=l1[i]
l1=[]
i=0
j=0
ok=1
while i<=len(l3)-2:
    if l3[i] > l3[i + 1]:
        break
    l1.append(l3[i])
    i=i+1
if i!=0:
    j=i
    while j <= len(l3) - 2:
        if l3[j] < l3[j+1]:
            break
        l2.append(l3[j])
        j=j+1
    l2.append(l3[j])
else:
    while j <= len(l3) - 2:
        if l3[j] < l3[j + 1]:
            break
        l2.append(l3[j])
        j = j + 1
    i=j
    while i <= len(l3) - 2:
        if l3[i] > l3[i+1]:
            break
        l1.append(l3[i])
        i = i + 1
    l1.append(l3[i])
if bs(x,l1) == -1 and bs(x,l2) == -1:
    print("valoarea x nu exista in lista")
elif bs(x,l1) != -1:
    print("valoarea x se afla pe pozitia ", bs(x,l1))
elif bs(x,l2) != -1:
    print("valoarea x se afla pe pozitia ", bs(x,l2))