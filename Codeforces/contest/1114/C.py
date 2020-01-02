[n, b] = list(map(int, input().split()))
ans = 10000000000000000000
for i in range(2, b + 1):
    if i * i > b:
        i = b
    cnt = 0
    while b % i == 0:
        b = b // i
        cnt += 1
    if cnt == 0:
        continue
    tmp = 0
    mul = i
    while mul <= n:
        tmp += n // mul
        mul *= i
    ans = min(ans, tmp // cnt)
    if b == 1:
        break
print(ans)
