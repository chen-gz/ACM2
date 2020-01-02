[x, y, z] = list(map(int, input().split()))
[a, b, c] = list(map(int, input().split()))
ans = True
if a < x:
    ans = False
else:
    a -= x
    if a + b < y:
        ans = False
    else:
        if a + b + c < y + z:
            ans = False
if ans:
    print("YES")
else:
    print("NO")
