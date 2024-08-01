import math

b = 2*math.pi
a = 0

h = int(input("Give h value: "))

n = int((b-a)/h)
# h = int((b-a)/n)

def Intergral(x):
    p = 7*x
    return math.sin(p)*math.sin(p)

li = []
q = a
for i in range(n+1):
    li.append(Intergral(q))
    q+=h

oddS = 0
evenS = 0
for i in range(1,n):
    if i%2==0:
        evenS+= li[i]
    else:
        oddS+= li[i]

ans = (h/3)*(li[0]+ li[-1] + 4*(oddS) + 2*(oddS))

percent_error = (abs(math.pi- ans)/math.pi)*100
print(ans)
print(percent_error)