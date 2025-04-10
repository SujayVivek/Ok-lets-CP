for _ in range(int(input())):
    n, x, y = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    print(x-2 + sum((a[i]-a[i-1])%n==2 for i in range(x)))
