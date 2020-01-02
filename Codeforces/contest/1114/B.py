[n, m, k] = list(map(int, input().split()))
a = list(map(int, input().split()))
b = a[:]
b.sort(reverse=True)
can = b[m * k - 1]
last = 0
for i in range(m * k, len(b)):
    if b[i] == can:
        last += 1
    else:
        break
ans = 0
for i in range(m * k):
    ans += b[i]
print(ans)
num = 0
ans = []
for i in range(len(a)):
    if a[i] >= can:
        if last > 0 and a[i] == can:
            last -= 1
        else:
            num += 1
    if num >= m:
        ans.append(i + 1)  # jiayi
        num = 0
    if len(ans) == k - 1:
        break
print(" ".join(str(i) for i in ans))