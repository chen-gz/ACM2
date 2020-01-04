import random

input()
a = list(map(int, input().split()))
b = a.copy()
b.sort()
tmp = 1
fill = []
for i in range(len(b)):
    if b[i] < tmp:
        continue
    elif b[i] == tmp:
        tmp += 1
    else:
        for j in range(tmp, b[i]):
            fill.append(j)
        tmp = b[i] + 1
for j in range(tmp, len(a) + 1):
    fill.append(j)

blank = []
for i in range(len(a)):
    if a[i] == 0:
        blank.append(i)

begin = 0
end = len(fill) - 1
for i in blank:
    if end - begin + 1 <= 3:
        break
    if i + 1 != fill[end]:
        a[i] = fill[end]
        end -= 1
    else:
        a[i] = fill[begin]
        begin += 1
OK = False

while not OK:
    if end - begin == 0:
        Ok = True
        break
    OK = True
    left = end - begin + 1
    left_begin = len(blank) - left
    rand = random.randint(0, 100) % (left)
    for i in range(left):
        a[blank[left_begin + ((i + rand) % left)]] = fill[begin + i]
        if blank[left_begin + ((i + rand) % (left))] + 1 == fill[begin + i]:
            OK = False
print(" ".join(str(i) for i in a))
