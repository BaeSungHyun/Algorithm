import heapq
import sys

input = sys.stdin.readline


def solution():
    n = int(input())

    absHeap = []
    answer = []

    for i in range(0, n):
        nums = int(input())

        if nums != 0:
            heapq.heappush(absHeap, (abs(nums), nums))
        elif nums == 0:
            if absHeap:
                answer.append(f"{(heapq.heappop(absHeap))[-1]}")
            else:
                answer.append("0")
    return "\n".join(answer)


print(solution())
