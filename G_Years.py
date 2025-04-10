l=[];y=a=c=0
for i in range(int(input())):
    b,d=map(int,input().split())
    l.append((b,1))
    l.append((d,-1))
l.sort()
for i in l:
    c+=i[1]
    if c>a:a,y=c,i[0]
print(y,a)