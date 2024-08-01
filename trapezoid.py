import math

delta_x = int(input("Give value of delta_x: "))

b = 2* math.pi
a = 0

n = int((b-a)/delta_x)

def Intergral(x):
    p = 7*x
    return math.sin(p)*math.sin(p)

li = []
q = a
for i in range(n+1):
    li.append(Intergral(q))
    q+= delta_x

ans = 0
for i in range(1,n):
    if (i==1 or i==n) :
        ans+= li[i]
    else:
        ans+= 2*li[i]

print()