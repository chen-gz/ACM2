[n, k, m] = list(map(int, input().split()))
a = list(map(int, input().split()))
a.sort()
sum = 0
for i in a:
    sum += i
ans = (sum + min(k * n, m)) / n
for i in range(min(len(a) -1 , m)):
    sum -= a[i]
    tmp = sum + min(k * (n - i - 1), m - i - 1)
    ans = max(ans, tmp / (n - i - 1))
print(ans)