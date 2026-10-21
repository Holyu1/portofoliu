import re
def ex_4(s):
     if len(s)<8:
         return 0
     else:
         regex=re.compile("[A-Z]+[a-z]+[@_!#$%^&*()<>?/|}{~:]+")
         result = regex.findall(s)
         if len(result)==0:
             return 0
         return 1
s=input()
if ex_4(s)==0:
    print("NO")
else:
    print("YES")