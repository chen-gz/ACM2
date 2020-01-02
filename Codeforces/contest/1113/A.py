[n, k] = list(map(int, input().split()))
ans = 0
rest = 0
if n > k+1:
    rest += k
    ans += k
    for i in range(2, n-1-k+2):
        ans += i
else:
    ans += n-1
print(ans)
