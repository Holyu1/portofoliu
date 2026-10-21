d=list(input())
i=0
while i<len(d)-1:
    auxi=int(d[i+1])-1
    auxs=d[i]
    d.pop(i+1)
    while auxi!=0:
        d.insert(i+1,auxs)
        auxi-=1
        i=i+1
    i=i+1
d="".join(d)
print(d)