import sys

optimized_input = sys.stdin.readline

def solution():
    n, m = map(int, optimized_input().split())
    unheard = set()
    unseen = set()

    for i in range(n):
        name = optimized_input()
        unheard.add(name)

    for i in range(m):
        name = optimized_input()
        unseen.add(name)

    total = list(unseen & unheard) # __and__ overload YEAH!
    total.sort()
    string_output = str()
    string_output += str(len(total))
    string_output += "\n"
    for i in range(len(total)):
        string_output += total[i]

    return string_output





print(solution())