n = int(input())
for i in range(1, n + 1):
    a, b, c = map(int, input().split())
    print('Case #%d: ' % i, end='')
    print('true') if a + b > c else print('false')
