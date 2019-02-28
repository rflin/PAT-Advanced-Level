
import re

rp_ch = {
    '1': '@', '0': '%', 'l': 'L', 'O': 'o'
}
n = int(input())
lst = []
pattern = re.compile(r'[10lO]')
for i in range(n):
    name, password = input().split()
    if pattern.search(password) is not None:
        lst.append(name + ' ' + re.sub(r'[10lO]', lambda x: rp_ch[x.group(0)], password))

m = len(lst)
if m == 0:
    if n == 1:
        print('There is 1 account and no account is modified')
    else:
        print('There are %d accounts and no account is modified' % n)
else:
    print(m)
    for e in lst:
        print(e)
