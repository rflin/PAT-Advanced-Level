
def main():
    n, base = map(int, input().split())
    lst = []
    while n > 0:
        lst.append(n % base)
        n = n // base
    if lst == lst[::-1]:
        print('Yes')
    else:
        print('No')
    print(' '.join(map(str, lst[::-1])))


main()


