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
    if n == 1:
        print(1)
        return
    elif n <= 3:
        print("NO SOLUTION")
        return
    
    for i in range(1, n+1):
        if i % 2 == 0:
            print(i, end=" ")
    for i in range(1, n+1):
        if i % 2 == 1:
            print(i, end=" ")


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
