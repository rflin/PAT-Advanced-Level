
import re

n = int(input())
lst = input().split()

res = 0.0
cnt = 0
pattern = re.compile(r'[-+]?\d+\.?\d{0,2}$')
for e in lst:
    if pattern.match(e) is None or float(e) > 1000 or float(e) < -1000:
        print('ERROR: %s is not a legal number' % e)
    else:
        res = res + float(e)
        cnt = cnt + 1

if cnt == 0:
    print('The average of 0 numbers is Undefined')
elif cnt == 1:
    print('The average of 1 number is %.2lf' % res)
else:
    print('The average of %d numbers is %.2lf' % (cnt, res / cnt))

