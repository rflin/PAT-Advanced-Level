s1 = input()
s2 = set(input())
s = ''

for x in s1:
    if x not in s2:
        s += x

print(s)
