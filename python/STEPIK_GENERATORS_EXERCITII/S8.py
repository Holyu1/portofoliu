import math
def S7(P,aph):
    mat=[]
    mat.append(P[0]*math.cos(aph)+P[1]*math.sin(aph))
    mat.append(-P[0]*math.sin(aph)+P[1]*math.cos(aph))
    return mat
x=float(input())
y=float(input())
aph=float(input())
bet=float(input())
P=[x,y]
P1=S7(P,aph)
print("P's coordinates after a rotation with alpha degrees are: ",P1) 