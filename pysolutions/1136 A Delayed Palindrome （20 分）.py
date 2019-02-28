
def main():
    n = input()
    cnt = 10
    while cnt > 0:
        cnt = cnt - 1
        if n == n[::-1]:
            print('%s is a palindromic number.' % n)
            return
        m = str(int(n) + int(n[::-1]))
        print('%s + %s = %s' % (n, n[::-1], m))
        n = m
    print('Not found in 10 iterations.')


main()
