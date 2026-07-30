# Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
# https://cses.fi/problemset
# --------------------------------
import sys
import os


def solve():
    input_data = sys.stdin.read().split()
    # if not input_data: return
    it = iter(input_data)
    n = int(next(it))
    ans = [n]
    while n != 1:
        if n % 2 == 0:
            n //= 2
        else:
            n = n*3 + 1
        ans.append(n)
    print(*ans)
    pass


def main():
    # I/O local
    for p in ('input.txt', 'Python/input.txt', '../input.txt'):
        if os.path.exists(p):
            sys.stdin, sys.stdout = open(p), open(p.replace('input.txt', 'output.txt'), 'w')
            break

    # sys.setrecursionlimit(200000)
    solve()


if __name__ == '__main__':
    main()
