import sys


def solution():
    n, *nums = map(int, sys.stdin.buffer.read().splitlines())
    s = list()
    answer = list()
    pos = 1
    for value in nums:
        while pos <= value:
            answer.append("+")
            s.append(pos)
            pos += 1
        if s.pop() != value:
            return "NO"
        answer.append("-")
    return "\n".join(answer)


print(solution())
