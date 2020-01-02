def lcs(a, b):
    c = [[0 for i in range(len(a)+2)] for i in range(len(b)+2)]
    for i in range(len(a)+1):
        for j in range(len(b)+1):
            if i == 0 or j == 0:
                c[i][j] = 0
            elif a[i-1] == b[j-1]:
                c[i][j] = c[i-1][j-1] + 1
            else:
                c[i][j] = max(c[i-1][j], c[i][j-1])
    return c[len(a)][len(b)]


print(lcs('abcsa', 'cbasa'))
