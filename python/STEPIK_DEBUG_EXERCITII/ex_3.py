def ex_3(d):
    for i in sorted(d.keys(),reverse=True):
        aux=d[i]
        del d[i]
        d[i]=aux
d = dict()
n=int(input())
for i in range(n):
    key=input()
    value=input()
    d[key]=value
ex_3(d)
print(d)
