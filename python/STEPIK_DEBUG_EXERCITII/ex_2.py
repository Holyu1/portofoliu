def ex_2(l):
    i=0
    if len(l)%2==1:
        return 0
    while i<=len(l)-2 :
        poz=-1
        for j in range(len(l1)):
            if l[i] == l1[j]:
                poz=j
                break
        if poz != -1:
                if l[i+1]==l2[poz]:
                    i=i+1
                elif l[len(l)-1]!=l2[poz]:
                    return 0
        else:
            return 0
        i=i+1
    return 1
l=input()
l1="([{"
l2=")]}"
if ex_2(l)==1:
    print("DA")
else:
    print("NU")
