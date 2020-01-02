n = input()
a = list(map(int, input().split()))
a_min = min(a)
a_sum = sum(a)
ans = -1
for i in a:
    for j in range(1, i + 1):
        if i % j == 0:
            ans = max(i - i // j - a_min * j + a_min, ans)
print(a_sum - ans)
