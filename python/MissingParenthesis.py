import sys

optimizedInput = sys.stdin.readline


def solution():
    plus = 0
    minus = 0

    minusSplit = optimizedInput().split('-')

    for index, i in enumerate(minusSplit):
        temp = i.split('+')
        for j in temp:
            if index == 0:
                plus += int(j)
            else:
                minus += int(j)

    return plus - minus


print(solution())
