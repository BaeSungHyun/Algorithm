import sys
import time
import copy

opt_input = sys.stdin.readline


def quick_sort(array, left, right):
    if left >= right:
        return

    # Choose the rightmost element as pivot
    pivot = array[left]

    i = left
    j = right + 1

    while i < j:
        while i < right:
            i += 1
            if array[i] >= pivot:
                break

        while j > left:
            j -= 1
            if array[j] <= pivot:
                break


        if i < j:
            array[i], array[j] = array[j], array[i]  # how is this pythonic?

    array[right], array[i] = array[i], array[right]
    quick_sort(array, left, i - 1)
    quick_sort(array, i + 1, right)


def solution():
    number = int(opt_input())

    array = list(map(int, opt_input().split(' ')))
    array2 = copy.deepcopy(array)

    start = time.time()
    quick_sort(array, 0, number - 1)
    end = time.time()

    print(end - start)

    start = time.time()
    array2.sort()
    end = time.time()

    print(end - start)

    return ' '.join(map(str, array))


solution()


# with 2000 list input:
# 0.0574553 seconds
# 0.0 seconds