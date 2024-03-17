import sys

optimizedInput = sys.stdin.readline

def recursive(older: int, younger: int):
    if older >= younger:
        return older - younger
    if older == 0:
        return recursive(1, younger) + 1
    if younger % 2 == 1:
        return min(recursive(older, younger - 1), recursive(older, younger + 1)) + 1
    return min(1 + recursive(older, younger / 2), younger - older)

def solution() -> int:
    older, younger = map(int, optimizedInput().split())
    return int(recursive(older, younger))

print(solution())