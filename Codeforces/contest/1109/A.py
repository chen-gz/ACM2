n = int(input())
a = list(map(int, input().split()))
cnt = [[0 for i in range(int(2 << 20)+10)],
       [0 for i in range(int(2 << 20)+10)]]
cnt[1][0] =1
x = 0
ans = 0
for i in range(n):
    x ^= a[i]
    ans += cnt[i % 2][x]
    cnt[i % 2][x] += 1
print(ans)
