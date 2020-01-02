n = input()
a = list(map(int, input().split()))
a.sort()
b = []
c = [a[0]]
ac = True

if len(a) >= 2:
    b.append(a[1])
for i in range(2, len(a)):
    if a[i] != a[i-1]:
        b.append(a[i])
    elif c[len(c)-1] != a[i]:
        c.append(a[i])
    else:
        ac = False
        break
if ac:
    print('YES')
    print(len(b))
    print(' '.join(str(i) for i in b))
    c.reverse()
    print(len(c))
    print(' '.join(str(i) for i in c))
else:
    print("NO")
