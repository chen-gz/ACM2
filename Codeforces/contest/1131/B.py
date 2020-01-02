n = int(input())
ll = 0
rr = 0
ans = 1
for i in range(n):
    [nl, nr] = list(map(int, input().split()))
    if min(nl, nr) >= max(ll, rr):
        # ans += abs(ll-rr)
        ans += min(nl, nr)-max(ll, rr)
        if ll != rr:
            ans += 1
    ll = nl
    rr = nr
print(ans)
