def ex_3(d):
    d1={}
    for i in sorted(d.keys(),reverse=True):
        d1[i]=d[i]
d = dict()
n=int(input())
for i in range(n):
    l=input().split()
    d[l[0]]=l[1]
