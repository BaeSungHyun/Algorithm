import sys

inputBae = sys.stdin.readline


def min(a, b):
    return b if a > b else a


def solve(n):
    if n <= 1:
        return 0
    x = solve(int(n / 3)) + 1 + n % 3
    y = solve(int(n / 2)) + 1 + n % 2
    return min(x, y)


def solution():
    num = int(inputBae())

    return solve(num)


print(solution())
