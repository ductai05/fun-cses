# Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
# https://cses.fi/problemset
# --------------------------------
import sys
import os


def solve():
    input_data = sys.stdin.read().split()
    it = iter(input_data)
    DNA = str(next(it))
    ans, max_ans = 1, 1
    pre_char = 'X'
    for char in DNA:
        if char != pre_char:
            pre_char = char
            ans = 1
        else:
            ans += 1
            max_ans = max(max_ans, ans)
    print(max_ans)


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
