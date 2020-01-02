# s = input()
# t = input()
# ans = True
# if len(s) != len(t):
#     ans = False
# else:
#     for i in range(len(s)):
#         if s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u':
#             if t[i] != 'a' and t[i] != 'e' and t[i] != 'i' and t[i] != 'o' and t[i] != 'u':
#                 ans = False
#         if t[i] == 'a' or t[i] == 'e' or t[i] == 'i' or t[i] == 'o' or t[i] == 'u':
#             if s[i] != 'a' and s[i] != 'e' and s[i] != 'i' and s[i] != 'o' and s[i] != 'u':
#                 ans = False
# if ans:
#     print('Yes')
# else:
#     print('No')

s = input()
t = input()
can = True
vowel = ['a', 'e', 'i', 'o', 'u']
if len(s) != len(t):
    can = False
else:
    for i in range(len(s)):
        if s[i] in vowel and t[i] not in vowel:
            can = False
        if t[i] in vowel and s[i] not in vowel:
            can = False
if can:
    print('Yes')
else:
    print('No')
