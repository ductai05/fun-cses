# Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
# https://cses.fi/problemset
# --------------------------------
import sys
import os


def solve():
    input_data = sys.stdin.read().split()
    it = iter(input_data)
    n = int(next(it))
    l = [int(next(it)) for _ in range (n-1)]
    # print(*l)

    xor_l, xor_n = 0, 0
    for i in l:
        xor_l ^= i
    for i in range(1, n + 1):
        xor_n ^= i
    print(xor_l ^ xor_n)

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
