
def main():
    lst = list(input().zfill(4))
    while True:
        n = ''.join(sorted(lst, reverse=True))
        m = n[::-1]
        if n == m:
            print('%s - %s = 0000' % (n, m))
            return
        r = int(n) - int(m)
        print("%s - %s = %04d" % (n, m, r))
        if r == 6174:
            return
        lst = list(str(r).zfill(4))


main()



