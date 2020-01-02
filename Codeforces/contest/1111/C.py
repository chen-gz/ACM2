import bisect


def calc(l, r):
    index_small = bisect.bisect_left(a, l)
    index_large = bisect.bisect_right(a, r)
    num = index_large - index_small
    if num == 0:
        ans = A
    else:
        ans = B * (r - l + 1) * num
    if l != r and num != 0:
        mid = (l+r-1)/2
        ans = min(ans, calc(l, mid) + calc(mid+1, r))
    return ans


[n, k, A, B] = list(map(int, input().split()))
global a
a = list(map(int, input().split()))
a.sort()
r = 1 << n
print(int(calc(1, r)))
